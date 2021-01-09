#include <stdio.h>
#include <queue>
#include <stdlib.h>

// 배열을 인자로 줄 땐 복사 안함 주소만 넘김
// DFS : 너무 오래걸림
// BFS : 중복방문 최대한 걸러서 시간 줄이기

using namespace std;

typedef struct{int r,c,cnt;}coo;
int row,col,mini=1000000;
int dc[]={1,0,-1,0}, dr[]={0,1,0,-1};
char arr[1001][1001];
int chk_a[1001][1001]={0}, chk_b[1001][1001]={0};
queue<coo> qu;

coo moves(coo now, int dir){
    now.r += dr[dir];
    now.c += dc[dir];
    if( now.r<0 || now.r==row ) now.r=-1;
    if( now.c<0 || now.c==col ) now.r=-1;
    return now;
}

void bfs(){
    coo now,next;
    int isbr;
    while( !qu.empty() ){
        now = qu.front();
        if( now.cnt<0 ) isbr = 1;
        else isbr = 0;
        now.cnt = abs(now.cnt);
        qu.pop();

        if( now.cnt>=mini ) continue;
        if( arr[now.r][now.c]=='3' ){
            mini = now.cnt;
            continue;
        }
        if( chk_a[now.r][now.c]!=0 && chk_a[now.r][now.c]<=now.cnt ) continue;
        if( isbr && chk_b[now.r][now.c]!=0 && chk_b[now.r][now.c]<=now.cnt ) continue;

        if( isbr ){
            chk_b[now.r][now.c] = now.cnt;
        }else{
            chk_a[now.r][now.c] = now.cnt;
            chk_b[now.r][now.c] = now.cnt;
        }

        for(int i=0; i<4; i++){
            next = moves(now, i);
            if( next.r==-1 ) continue;

            if( isbr ){
                if( arr[next.r][next.c]=='1' ) continue;
                if( chk_b[next.r][next.c]!=0 && chk_b[next.r][next.c]<=now.cnt ) continue;
                qu.push({next.r, next.c, (now.cnt+1)*(-1)});
            }else{
                if( chk_a[next.r][next.c]!=0 && chk_a[next.r][next.c]<=now.cnt ) continue;
                if( arr[next.r][next.c]=='1' ){
                    qu.push({next.r, next.c, (now.cnt+1)*(-1)});
                }else{
                    qu.push({next.r, next.c, now.cnt+1});
                }
            }
        }
    }
}

int main(){
    scanf("%d", &row);
    scanf("%d", &col);
    for(int i=0; i<row; i++){
        scanf("%s", &arr[i]);
    }
    arr[row-1][col-1] = '3';
    qu.push({0,0,1});

    bfs();

    if( mini==1000000 ) printf("-1\n");
    else printf("%d\n", mini);
    return 0;
}
