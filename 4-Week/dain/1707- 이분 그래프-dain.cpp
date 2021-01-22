#include <iostream>
#include <cstring>
#include <vector>

#define BLACK 1
#define WHITE -1

using namespace std;

int T, V, E;
vector<int> graph[20001];
int node_color[20001];

void colorit(int node, int color){
	node_color[node] = color;
	for(int i=0;i<graph[node].size();i++){
		int next_node = graph[node][i];
		if(node_color[next_node] == 0){
			colorit(next_node, color * -1);
		}
	}
}

bool check_graph(){
	for(int i=1;i<=V;i++){
		for(int j=0;j<graph[i].size();j++){
			int next_node = graph[i][j];
			if(node_color[i] == node_color[next_node])
				return false;
		}
	}
	return true;
}

int main(){
	freopen("Input.txt", "r", stdin);
	cin >> T;
	while(T--){
		for(int i=0;i<20001;i++)
			graph[i].clear();
		memset(node_color, 0, sizeof(node_color));
		cin >> V >> E;
		for(int k=0;k<E;k++){
			int i, j;
			cin >> i >> j;
			graph[i].push_back(j);
			graph[j].push_back(i);
		}

		for(int i=1;i<=V;i++){
			if(node_color[i] == 0)
				colorit(i, BLACK);
		}

		if(check_graph() == true)	cout << "YES\n";
		else						cout << "NO\n";
	}
}
