#include <iostream>
#include <vector>
#include <queue>

#define MAX 987654321

using namespace std;

int main(){
	int V, E, K;
	cin >> V >> E >> K;

	vector<pair<int, int>> graph[20001];
	vector<int> d(V+1, MAX);
	d[K] = 0;

	for(int i=0;i<E;i++){
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(w, v));
	}

	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, K));

	while(!pq.empty()){
		int cur_dist = -pq.top().first;
		int cur_index = pq.top().second;
		pq.pop();

		if(d[cur_index] < cur_dist)	continue;

		for(int i=0;i<graph[cur_index].size(); i++){
			int next_dist = graph[cur_index][i].first;
			int next_index = graph[cur_index][i].second;
			if(next_dist + cur_dist < d[next_index]){
				d[next_index] = next_dist + cur_dist;
				pq.push(make_pair(-d[next_index], next_index));
			}
		}
	}

	for(int i=1;i<V+1; i++){
		if (d[i]==MAX)
			cout << "INF\n";
		else
			cout << d[i] << "\n";
	}


}