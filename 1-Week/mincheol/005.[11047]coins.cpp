#include <iostream>

// 시간복잡도: O(N) 대략

using namespace std;

int N,K,i;
int coins[10];

int greedy(){
    int ans=0;
    for(i=N-1; i>-1; i--){
        while( K>=coins[i] ){
            K -= coins[i];
            ans++;
        }
        if( K==0 ) break;
    }
    return ans;
}

int main(){
    cin>>N>>K;
    for(i=0; i<N; i++){
        cin>>coins[i];
    }
    cout<<greedy()<<endl;
    return 0;
}
