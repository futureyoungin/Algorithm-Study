#include <iostream>
#include <vector>
#define MAX 100001

using namespace std;

int N, R, Q, U, V, tmp;
bool visit[MAX] = {false};
int node_num[MAX] = {0};
vector<int> v[MAX];

int dfs(int n){
	if(node_num[n] != 0)
		return node_num[n];

	visit[n] = true;
	int cnt = 1;

	for(int i=0;i<v[n].size();i++){
		int next = v[n][i];
		if(visit[next]==true) continue;
		cnt += dfs(v[n][i]);
	}

	node_num[n] = cnt;
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("Input.txt", "r", stdin);

	cin >> N >> R >> Q;

	for(int i=0;i<N-1;i++){
		cin >> U >> V;
		v[U].push_back(V);
		v[V].push_back(U);
	}

	node_num[R] = dfs(R);

	for(int i=0;i<Q;i++){
		cin >> tmp;
		cout << node_num[tmp] << "\n";
	}
}