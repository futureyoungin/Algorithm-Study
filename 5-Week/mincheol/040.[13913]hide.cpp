#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int st,ed,siz,chk=0;
int parent[100001];
queue<int> qu;

int bfs(){
    int now;
    while( !qu.empty() ){
        now = qu.front();
        qu.pop();
        siz--;
        if( now==ed ) return now;
        if( now!=0 && parent[now-1]==-1 ){
            parent[now-1] = now;
            qu.push(now-1);
        }
        if( now!=100000 && parent[now+1]==-1 ){
            parent[now+1] = now;
            qu.push(now+1);
        }
        if( now<50001 && parent[now*2]==-1 ){
            parent[now*2] = now;
            qu.push(now*2);
        }
        if( siz==0 ){
            chk++;
            siz = qu.size();
        }
    }
}

void fprint(int ans){
    if( parent[ans]!=-2 ) fprint(parent[ans]);
    printf("%d ", ans);
}

int main(){
    for(int i=0; i<100001; i++) parent[i] = -1;
    scanf("%d %d", &st, &ed);
    parent[st] = -2;
    qu.push({st});
    siz = 1;
    int ans = bfs();
    printf("%d\n", chk);
    fprint(ans);
    return 0;
}
