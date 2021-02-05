#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 2147483647

using namespace std;

int N, M, K, X;
vector<int> v[300001];
bool visit[300001];

void bfs(){
	int dist = 0;
	queue<int> q;
	q.push(X);
	visit[X] = true;
	while(!q.empty()){
		int qsize = q.size();
		while(qsize--){
			int front = q.front(); q.pop();
			for(int i=0;i<v[front].size();i++){
				int next = v[front][i];
				if(visit[next]) continue;
				visit[next] = true;
				q.push(next);
			}
		}
		dist++;
		if(dist==K){
			if(q.empty()){
				cout << -1 << "\n"; return;
			}
			vector<int> answer;
			while(!q.empty()){
				answer.push_back(q.front());
				q.pop();
			}
			sort(answer.begin(), answer.end());
			for(int i=0;i<answer.size();i++){
				cout << answer[i] << "\n";
			}
			return;
		}
	}
	cout << -1 << "\n"; return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K >> X;

	for(int i=0;i<M;i++){
		int x, y; cin >> x >> y;
		v[x].push_back(y);
	}

	bfs();

	return 0;
}