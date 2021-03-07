#include <iostream>
#include <algorithm>

using namespace std;

int N;
int wine[10010]={0, };
int dp[10010]={0, };


void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i=1; i<=N; i++)
        cin >> wine[i];
}

void make_dp(){
    dp[1] = wine[1]; dp[2] = wine[1] + wine[2];
    for(int i=3; i<=N; i++){
        dp[i] = max( max(dp[i-3]+wine[i]+wine[i-1], dp[i-2] + wine[i]), dp[i-1]);
    }
}


int main()
{
   input();
   make_dp();
   cout << dp[N];
   return 0;
}