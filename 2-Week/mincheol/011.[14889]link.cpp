#include <stdio.h>
#include <stdlib.h>

using namespace std;

int N;
int arr[20][20], team[20] = {0};
int mini = 2000;
void dfs(int tsize, int i, int* team){
    if( tsize<N/2 ){
        for(int j=i; j<=N/2+tsize; j++){    // N-(N/2-tsize)
            team[j] = 1;
            dfs(tsize+1, j+1, team);
            team[j] = 0;
        }
    }else{
        int stat[] = {0,0};
        for(int j=0; j<N; j++)
            for(int k=0; k<N; k++)
                if( j!=k && team[j]==team[k] )
                    stat[team[j]] += arr[j][k];
        int diff = abs(stat[0]-stat[1]);
        if( mini>diff ) mini = diff;
    }
}

int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    dfs(0, 0, team);
    printf("%d\n", mini);
    return 0;
}

/*
int N, in, total=0;
int arr[20][20];
int x[20] = {0};
int mini = 2000;

void dfs(int idx, int cnt, int res){
    if( cnt==N/2 ){
        if( mini>abs(res) ) mini = abs(res);
        return;
    }
    if( idx<N-1 ){
        dfs(idx+1, cnt+1, res-x[idx]);
        dfs(idx+1, cnt, res);
    }
}

int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &in);
            total += in;
            x[i] += in;
            x[j] += in;
        }
    }

    dfs(0, 0, total);
    printf("%d\n", mini);
    return 0;
}
*/
