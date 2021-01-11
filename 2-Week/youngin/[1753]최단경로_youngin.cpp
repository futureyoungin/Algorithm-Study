#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <limits.h>


//have to use dijkstra's algorithm O( (v+e)loge ) 
// floyd O(v^3), bellman-ford O( ve )
// https://www.acmicpc.net/board/view/34516


using namespace std;

int n, n_edge;
int start;

int destination[20001];
int visit[20001];

vector<pair<int, int>> vertex[20001];	//first->weight, second->destination vertex.
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;


void input() {
	cin >> n >> n_edge;
	cin >> start;
	int v_start, v_end, weight;
	for (int i = 0; i < n_edge; i++) {
		cin >> v_start >> v_end >> weight;
		vertex[v_start].push_back(make_pair(weight, v_end));
	}
}

void dijkstra_init() {
	for (int i = 1; i <= n; i++) {
		destination[i] = INT_MAX;
	}
	pq.push(make_pair(0, start));
	destination[start] = 0;
	visit[start] = 1;
}

void dijkstra() {
	dijkstra_init();
	while (!pq.empty()) {
		int v_now = pq.top().second;
		int cost_now = pq.top().first;
		pq.pop();

		if (destination[v_now] < cost_now)
			continue;

		for (int i = 0; i < vertex[v_now].size(); i++) {
			int next = vertex[v_now][i].second;
			if (visit[next] == 1)
				continue;
			int cost_next;
			if (destination[v_now] == INT_MAX) {
				cost_next = INT_MAX;
			}
			else {
				cost_next = vertex[v_now][i].first + destination[v_now];
			}

			if (destination[next] > cost_next) {
				destination[next] = cost_next;
				pq.push(make_pair(cost_next, next));
			}
		}
	}
}

void result() {
	for (int i = 1; i <= n; i++) {
		if (destination[i] == INT_MAX)
			cout << "INF" << "\n";
		else {
			cout << destination[i] << "\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();

	dijkstra();

	result();
	return 0;
}