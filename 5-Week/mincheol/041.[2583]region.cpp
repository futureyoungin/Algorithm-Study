#include <stdio.h>
#include <queue>

using namespace std;

typedef struct{int r,c;}coo;
int se,ga,sq,in1,in2,in3,in4;
int arr[100][100] = {0,};
int dr[] = {0,1,0,-1};
int dc[] = {1,0,-1,0};
queue<coo> qu;
priority_queue<int, vector<int>, greater<int> > ans;

void fset(coo a, coo b){
    for(int i=a.r; i<b.r; i++)
        for(int j=a.c; j<b.c; j++)
            arr[i][j] = 1;
}

coo fmove(coo now, int dir){
    now.r += dr[dir];
    now.c += dc[dir];
    if( now.r<0 || now.r==ga || now.c<0 || now.c==se )
        now.r = -1;
    return now;
}

void solution(){
    int chk = 0;
    coo now,next;
    for(int i=0; i<ga; i++){
        for(int j=0; j<se; j++){
            if( arr[i][j]==0 ){
                qu.push({i,j});
                arr[i][j] = 1;
                chk++;
            }
            while( !qu.empty() ){
                now = qu.front();
                qu.pop();
                for(int k=0; k<4; k++){
                    next = fmove(now, k);
                    if( next.r==-1 ) continue;
                    if( arr[next.r][next.c]==1 ) continue;
                    qu.push(next);
                    arr[next.r][next.c] = 1;
                    chk++;
                }
            }
            if( chk>0 ){
                ans.push(chk);
                chk = 0;
            }
        }
    }
}

int main(){
    scanf("%d %d %d", &se, &ga, &sq);
    for(int i=0; i<sq; i++){
        scanf("%d %d %d %d", &in1, &in2, &in3, &in4);
        fset({in1,in2}, {in3,in4});
    }
    solution();

    printf("%d\n", ans.size());
    while( !ans.empty() ){
        printf("%d ", ans.top());
        ans.pop();
    }
    return 0;
}
