#include <stdio.h>
#include <algorithm>

using namespace std;

int cases,chapters,in1;
int acc[501];
int dp[501][501] = {0,};

void reset(){
    for(int i=0; i<501; i++)
        for(int j=0; j<501; j++)
            dp[i][j] = 0;
}

int dfs(int st, int ed){
    if( st==ed ) return 0;
    if( dp[st][ed]!=0 ) return dp[st][ed];
    dp[st][ed] = 2000000000;
    for(int mid=st; mid<ed; mid++){
        dp[st][ed] = min(dp[st][ed], dfs(st,mid)+dfs(mid+1, ed)+acc[ed]-acc[st-1]);
    }
    return dp[st][ed];
}

int main(){
    scanf("%d", &cases);
    for(int i=0; i<cases; i++){
        scanf("%d", &chapters);
        for(int j=1; j<=chapters; j++){
            scanf("%d", &in1);
            acc[j] = acc[j-1]+in1;
        }

        reset();
        dfs(1, chapters);
        printf("%d\n", dp[1][chapters]);
    }
    return 0;
}
