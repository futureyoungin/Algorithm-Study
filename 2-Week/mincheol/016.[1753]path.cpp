#include <stdio.h>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

typedef struct{int w,dest;}lin;
int nodes,lines,st;
int graph[20001] = {0};

struct cmp{
    bool operator()(lin a, lin b){
        return a.w>b.w;
    }
};
vector<vector<lin>> arr;
vector<int> done;
priority_queue<lin, vector<lin>, cmp> qu;

void bfs(){
    lin tmp;
    while( !qu.empty() ){
        tmp = qu.top();
        //printf(" %d %d\n", tmp.w, tmp.dest);
        qu.pop();
        if( done[tmp.dest] ) continue;
        for(lin i : arr[tmp.dest]){
            if( done[i.dest] ) continue;
            if( graph[i.dest]==0 || tmp.w+i.w<graph[i.dest] ){
                graph[i.dest] = tmp.w+i.w;
                qu.push({graph[i.dest], i.dest});
            }
        }
        done[tmp.dest] = 1;
    }
}

int main(){
    int _in1,_in2,_in3;
    ifstream in("test.txt");
    if( in.is_open() ){
        in>>nodes>>lines;
        in>>st;
        arr.assign(nodes+1, {});
        done.assign(nodes+1, 0);
        for(int i=0; i<lines; i++){
            in>>_in1>>_in2>>_in3;
            arr[_in1].push_back({_in3,_in2});
        }
    }

    qu.push({0, st});
    bfs();

    for(int i=1; i<=nodes; i++){
        if( i==st ) printf("0\n");
        else if( graph[i]==0 ) printf("INF\n");
        else printf("%d\n", graph[i]);
    }

    return 0;
}

