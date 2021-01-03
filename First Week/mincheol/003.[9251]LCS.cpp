#include <iostream>
#include <string>

using namespace std;

string a, b;
int arr[1001][1001] = {0,};

int lcs(){
    for(int i=0; i<a.length(); i++){
        for(int j=0; j<b.length(); j++){
            if( a[i]==b[j] ){
                arr[i+1][j+1] = arr[i][j]+1;
            }else{
                if( arr[i][j+1]>arr[i+1][j] ) arr[i+1][j+1] = arr[i][j+1];
                else arr[i+1][j+1] = arr[i+1][j];
            }
        }
    }
    return arr[a.length()][b.length()];
}

int main(){
    cin>>a;
    cin>>b;

    cout<<lcs()<<endl;
    return 0;
}
