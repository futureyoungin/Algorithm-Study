#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

#define INF 0x7fffffff

typedef struct{int node,w;}vtx;
int vrtx,edges,in1,in2,in3,target=-1,ans=0;
vector<vtx> input[10001];
int visit_chk[10001] = {0,};
int w_chk[10001];

struct cmp{
    bool operator()(vtx a, vtx b){
        return a.w>b.w;
    }
};
priority_queue<vtx, vector<vtx>, cmp> qu;

void prim(){
    vtx now;
    while( !qu.empty() ){
        now = qu.top();
        qu.pop();
        if( visit_chk[now.node]==1 ) continue;
        visit_chk[now.node] = 1;
        ans += now.w;
        if( ++target==vrtx-1 ) return;

        for(vtx next : input[now.node]){
            if( visit_chk[next.node]==1 ) continue;
            if( w_chk[next.node]>=next.w ){
                w_chk[next.node] = next.w;
                qu.push(next);
            }
        }
    }
}

int main(){
    scanf("%d %d", &vrtx, &edges);
    for(int i=1; i<=edges; i++){
        scanf("%d %d %d", &in1, &in2, &in3);
        input[in1].push_back({in2, in3});
        input[in2].push_back({in1, in3});
    }
    for(int i=1; i<=vrtx; i++) w_chk[i] = INF;
    qu.push({1, 0});
    prim();
    printf("%d\n", ans);
    return 0;
}
