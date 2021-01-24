#include <stdio.h>
#include <algorithm>

using namespace std;

int cases,chapters,in1;
int acc[501];
int dp[501][501] = {0,};

void solution(){
    for(int d=1; d<chapters; d++){
        for(int st=1; st+d<=chapters; st++){
            int ed = st + d;
            dp[st][ed] = 2000000000;
            for(int mid=st; mid<ed; mid++){
                dp[st][ed] = min(dp[st][ed], dp[st][mid]+dp[mid+1][ed]+acc[ed]-acc[st-1]);
            }
        }
    }
}

int main(){
    scanf("%d", &cases);
    for(int i=0; i<cases; i++){
        scanf("%d", &chapters);
        for(int j=1; j<=chapters; j++){
            scanf("%d", &in1);
            acc[j] = acc[j-1]+in1;
        }

        solution();
        printf("%d\n", dp[1][chapters]);
    }
    return 0;
}
