#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Relation{
	int first, second;
	bool visit;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("Input.txt", "r", stdin);

	int N; cin >> N;

	int array[100001];
	vector<int> v[100001];
	queue<int> q;

	for(int i=0;i<N;i++){
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	q.push(1);
	
	while(!q.empty()){
		int top = q.front(); q.pop();
		for(int i=0;i<v[top].size();i++){
			if(array[v[top][i]] != 0) continue;
			q.push(v[top][i]);
			array[v[top][i]] = top;
		}
	}

	for(int i=2;i<=N;i++) cout << array[i] << "\n";

	return 0;
}