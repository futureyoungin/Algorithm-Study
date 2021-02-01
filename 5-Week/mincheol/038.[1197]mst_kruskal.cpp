#include <stdio.h>
#include <algorithm>

using namespace std;

typedef struct{int v1,v2,w;}edg;
int vrtx,edges,in1,in2,in3;
edg input[100000];
int unions[10001];

bool cmp(edg a, edg b){
    return a.w<b.w;
}

void union_set(){
    for(int i=1; i<=vrtx; i++) unions[i] = i;
}

void funion(int u1, int u2){
    unions[u2] = u1;
}

int union_find(int u1){
    if( unions[u1]==u1 ) return u1;
    else return unions[u1] = union_find(unions[u1]);
}

/*int union_find(int u1){
    while( unions[u1]!=u1 ) u1 = unions[u1];
    return u1;
}*/

void solution(){
    int target=0,ans=0,idx=0,u1,u2;
    union_set();
    while( target<vrtx-1 ){
        u1 = union_find(input[idx].v1);
        u2 = union_find(input[idx].v2);
        if( u1!=u2 ){
            ans += input[idx].w;
            funion(u1, u2);
            target++;
        }
        idx++;
    }
    printf("%d\n", ans);
}

int main(){
    scanf("%d %d", &vrtx, &edges);
    for(int i=0; i<edges; i++){
        scanf("%d %d %d", &in1, &in2, &in3);
        input[i] = {in1, in2, in3};
    }
    sort(input, input+edges, cmp);
    solution();
    return 0;
}
