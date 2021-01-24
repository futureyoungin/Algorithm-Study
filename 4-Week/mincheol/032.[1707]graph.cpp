#include <stdio.h>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int cases,nodes,vrtx,in1,in2;
vector<int> node[20001];
set<int> set1;

void arr_clear(){
    for(int i=1; i<=nodes; i++){
        node[i] = {};
    }
}

void bfs(){
    queue<int> qu;
    vector<int> chk(nodes+1, 0);
    int cnt=1,now,siz;
    while( !set1.empty() ){
        qu.push(*set1.begin());
        chk[qu.front()] = cnt++;
        siz = 1;
        while( !qu.empty() ){
            now = qu.front();
            qu.pop();
            set1.erase(now);
            for(int i : node[now]){
                if( chk[i]==chk[now] ){
                    set1.clear();
                    printf("NO\n");
                    return;
                }
                if( chk[i]==0 ){
                    chk[i] = cnt;
                    qu.push(i);
                }
            }
            siz--;
            if( siz==0 ){
                cnt++;
                siz = qu.size();
            }
        }
    }
    printf("YES\n");
}

int main(){
    scanf("%d", &cases);
    for(int i=0; i<cases; i++){
        scanf("%d %d", &nodes, &vrtx);
        for(int j=1; j<=nodes; j++)
            set1.insert(j);
        for(int j=0; j<vrtx; j++){
            scanf("%d %d", &in1, &in2);
            node[in1].push_back(in2);
            node[in2].push_back(in1);
        }
        bfs();
        arr_clear();
    }
    return 0;
}
