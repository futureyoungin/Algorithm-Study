#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

int root;
int n_vertex;
int n_query;
int visit[100001] = { 0, };
int dp_child[100001] = { 0, };
deque<int> dq_tree[100001];

void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n_vertex >> root >> n_query;
	for (int i = 1; i <= n_vertex; i++)
		dq_tree[i].push_back(i);

	int temp_edge1, temp_edge2;
	visit[root] = 1;
	for (int i = 0; i < n_vertex - 1; i++) {
		cin >> temp_edge1 >> temp_edge2;
		dq_tree[temp_edge1].push_back(temp_edge2);
		dq_tree[temp_edge2].push_back(temp_edge1);
	}
}


int prunning(int search) {
	int child = 0;
	for (int i = 1; i < dq_tree[search].size(); i++) {
		if (visit[dq_tree[search][i]] == 0) {
			child++;
			visit[dq_tree[search][i]] = 1;
			child += prunning(dq_tree[search][i]);
		}
	}
	dp_child[search] = child;
	return child;
}


int main() {
	input();
	prunning(root);
	int query;
	for (int i = 0; i < n_query; i++) {
		cin >> query;
		cout << dp_child[query]+1 << "\n";
	}
	return 0;
}