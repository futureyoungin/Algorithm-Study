#include <stdio.h>
#include <queue>

using namespace std;

typedef struct{int x,y;}coo;
int cases,n,in1,in2,ca;
int arr[300][300] = {0,};
coo st,ed;

int dx[] = {1,2,2,1,-1,-2,-2,-1};
int dy[] = {2,1,-1,-2,-2,-1,1,2};

coo fmove(coo now, int dir){
    now.x += dx[dir];
    now.y += dy[dir];
    if( now.x<0 || now.x>=n || now.y<0 || now.y>=n )
        now.x = -1;
    return now;
}

void bfs(){
    queue<coo> qu;
    qu.push(st);

    int i,ans=0,chk=1;
    coo now,next;
    while( !qu.empty() ){
        now = qu.front();
        qu.pop();
        for(i=0; i<8; i++){
            next = fmove(now, i);
            if( next.x==-1 ) continue;
            if( arr[next.x][next.y]==ca ) continue;
            arr[next.x][next.y] = ca;
            qu.push(next);
        }
        chk--;
        if( chk==0 ){
            ans++;
            if( arr[ed.x][ed.y]==ca ){
                printf("%d\n", ans);
                return;
            }
            chk = qu.size();
        }
    }
}

int main(){
    scanf("%d", &cases);
    for(ca=1; ca<=cases; ca++){
        scanf("%d", &n);
        scanf("%d %d", &in1, &in2);
        st = {in1, in2};
        scanf("%d %d", &in1, &in2);
        ed = {in1, in2};
        if( st.x==ed.x && st.y==ed.y ){
            printf("0\n");
            continue;
        }
        arr[st.x][st.y] = 1;
        bfs();
    }
    return 0;
}
