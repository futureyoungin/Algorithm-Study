#include <iostream>

using namespace std;

int N,i,j,k,x,y;
long long B;
int arr[5][5],res[2][5][5];

void arr_mul(int arr1[5][5], int arr2[5][5]){
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            res[x][i][j] = 0;
            for(k=0; k<N; k++)
                res[x][i][j] += arr1[i][k]*arr2[k][j];
            res[x][i][j] %= 1000;
        }
    }
    x = (x+1)%2;
    y = (y+1)%2;
}

void arr_sq(long long num){
    if( num/2>1 ){
        arr_sq(num/2);
    }
    arr_mul(res[y], res[y]);
    if( num%2==1 ){
        arr_mul(res[y], arr);
    }
}

int main(){
    cin>>N>>B;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            cin>>arr[i][j];
            arr[i][j] %= 1000;
            res[0][i][j] = arr[i][j];
            x=1, y=0;
        }
    }

    if( B>1 ) arr_sq(B);
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            //cout<<arr[i][j]<<" ";
            cout<<res[y][i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
