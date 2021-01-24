#include <iostream>
#include <cstring>
#include <vector>


using namespace std;

#define RED 1
#define BLUE 2

int T, v, e;
int visit[20001]={0, };
vector<int> vertex[20001];

void input(){
    int temp_v1, temp_v2;
    for(int i=0; i<e; i++){
        cin >> temp_v1 >> temp_v2;
        vertex[temp_v1].push_back(temp_v2);
        vertex[temp_v2].push_back(temp_v1);
    }
}

void data_clear(){
    for(int i=0; i<=v; i++){
        vertex[i].clear();
    }
    memset(visit, 0, sizeof(int)*(v+1));
}

void dfs(int v_start){
    int cur_vertex;
    if(visit[v_start] == 0)
        visit[v_start] = RED;
    for(int i=0; i<vertex[v_start].size(); i++){
        cur_vertex = vertex[v_start][i];
        if(visit[cur_vertex] != 0)
            continue;
        if(visit[v_start] == RED){
            visit[cur_vertex] = BLUE;
            dfs(cur_vertex);
        }
        else{
            visit[cur_vertex] = RED;
            dfs(cur_vertex);
        }
    }
}

bool is_bipartite(){
    int cur_vertex, edge_vertex;
    for(cur_vertex = 1; cur_vertex <= v; cur_vertex++){
        for(int i=0; i<vertex[cur_vertex].size(); i++){
            edge_vertex = vertex[cur_vertex][i];
            if(visit[edge_vertex] == visit[cur_vertex])
                return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> v >> e;
        input();
        for(int v_start = 1; v_start <= v; v_start++)
            dfs(v_start);
        if(is_bipartite())
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
        data_clear(); // vector, visit clear.
    }
    
    return 0;
}