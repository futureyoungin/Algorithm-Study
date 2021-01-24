#include <stdio.h>
#include <queue>
#include <fstream>

using namespace std;

typedef struct{int r,c;}coo;
int cases,ga,se,K,in1,in2,ans;
int farm[50][50] = {0,};
queue<coo> qu1,qu2;
int dc[] = {1,0,-1,0};
int dr[] = {0,1,0,-1};

coo fmove(coo now, int dir){
    now.r += dr[dir];
    now.c += dc[dir];
    if( now.r<0 || now.r==se || now.c<0 || now.c==ga ){
        now.r = -1;
    }
    return now;
}

void bfs(){
    coo now,next;
    ans = 0;
    while( !qu1.empty() ){
        now = qu1.front();
        qu1.pop();
        if( farm[now.r][now.c]==0 ) continue;
        farm[now.r][now.c] = 0;
        qu2.push(now);
        while( !qu2.empty() ){
            now = qu2.front();
            qu2.pop();
            for(int i=0; i<4; i++){
                next = fmove(now, i);
                if( next.r==-1 ) continue;
                if( farm[next.r][next.c]==0 ) continue;
                farm[next.r][next.c] = 0;
                qu2.push(next);
            }
        }
        ans++;
    }
    printf("%d\n", ans);
}

int main(){
    scanf("%d", &cases);
    for(int i=0; i<cases; i++){
        scanf("%d %d %d", &ga, &se, &K);
        for(int j=0; j<K; j++){
            scanf("%d %d", &in1, &in2);
            qu1.push({in2,in1});
            farm[in2][in1] = 1;
        }
        bfs();
    }
    /*ifstream in("test.txt");
    if( in.is_open() ){
        in>>cases;
        for(int i=0; i<cases; i++){
            in>>ga>>se>>K;
            for(int j=0; j<K; j++){
                in>>in1>>in2;
                qu1.push({in2,in1});
                farm[in2][in1] = 1;
            }
            bfs();
        }
    }*/
    return 0;
}
