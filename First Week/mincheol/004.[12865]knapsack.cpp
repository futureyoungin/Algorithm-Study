#include <iostream>

// 시간복잡도: O(N*K)

using namespace std;

int N, K;
int wss[100], vs[100];
int arr[1000001][101]={0,};

void sack(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=K; j++){
            if( j>=wss[i-1] ){
                if( arr[j-wss[i-1]][i-1]+vs[i-1] > arr[j][i-1] )
                    arr[j][i] = arr[j-wss[i-1]][i-1]+vs[i-1];
                else
                    arr[j][i] = arr[j][i-1];
            }else{
                arr[j][i] = arr[j][i-1];
            }
        }
    }
}

int main(){
    cin>>N>>K;
    for(int i=0; i<N; i++){
        cin>>wss[i]>>vs[i];
    }
    sack();
    cout<<arr[K][N]<<endl;
    return 0;
}
