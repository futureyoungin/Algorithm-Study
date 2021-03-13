#include <iostream>
#include <fstream>

using namespace std;

int cases,N,targ;
int coins[20];
int dp[10001];

void solution(){
    for(int i=1; i<=targ; i++) dp[i] = 0;
    for(int i=0; i<N; i++){
        for(int j=targ; j>=coins[i]; j--){
            if( j%coins[i]==0 ) dp[j]++;
            for(int k=j-coins[i]; k>0; k-=coins[i]){
                dp[j] += dp[k];
            }
        }
        /*for(int j=1; j<=targ; j++) cout<<dp[j]<<" ";
        cout<<"\n";*/
    }
    cout<<dp[targ]<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ifstream in("test.txt");
    if( in.is_open() ){
        in>>cases;
        for(int i=0; i<cases; i++){
            in>>N;
            for(int j=0; j<N; j++) in>>coins[j];
            in>>targ;
            solution();
        }
    }
    return 0;
}
