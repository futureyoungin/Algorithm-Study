#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <utility>

using namespace std;

int n, m;
string map[1000];
int map_distance[2][1000][1000] = { 0, };
int end_n, end_m;
int min_distance=-1;

// first.first:current_n, first.second:current_m, second.first:distance, second.second:chance(벽을 부술 기회)
queue< pair< pair<int, int>, pair<int,int> > > que;


void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	end_n = n - 1, end_m = m - 1;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
		for (int j = 0; j < m; j++) {		
			map_distance[0][i][j] = 0;
			map_distance[1][i][j] = 0;
		}
	}
	map[0][0] = '1'; // 시작점으로 돌아오는 것은 필요없기 때문에.
}



void push_queue(int current_n, int current_m, int distance, int chance) {
	if (chance == 1) { //벽을 부수지 않고.
		if (map_distance[0][current_n][current_m] ==  0) {	// pruning, 방문하지 않았다면.
			que.push(make_pair(make_pair(current_n, current_m), make_pair(distance, chance)));
			map_distance[0][current_n][current_m] = distance;
		}
	}
	else {	// 벽을 부수고.
		if (map_distance[1][current_n][current_m] == 0) {	// pruning
			que.push(make_pair(make_pair(current_n, current_m), make_pair(distance, chance)));
			map_distance[1][current_n][current_m] = distance;
		}
	}
}

void pop_queue(int *pop_n, int *pop_m, int *pop_distance, int *pop_chance) {
	*pop_n = que.front().first.first;
	*pop_m = que.front().first.second;
	*pop_distance = que.front().second.first;
	*pop_chance = que.front().second.second;
}

void act(int pop_n, int pop_m, int pop_distance, int pop_chance) {
	if (pop_n + 1 < n) {
		if (map[pop_n + 1][pop_m] != '1') {
			push_queue(pop_n + 1, pop_m, pop_distance + 1, pop_chance);
		}
	}
	if (pop_m + 1 < m) {
		if (map[pop_n][pop_m + 1] != '1') {
			push_queue(pop_n, pop_m + 1, pop_distance + 1, pop_chance);
		}
	}
	if (pop_n - 1 >= 0) {
		if (map[pop_n - 1][pop_m] != '1') {
			push_queue(pop_n - 1, pop_m, pop_distance + 1, pop_chance);
		}
	}
	if (pop_m - 1 >= 0) {
		if (map[pop_n][pop_m - 1] != '1') {
			push_queue(pop_n, pop_m - 1, pop_distance + 1, pop_chance);
		}
	}

	if (pop_chance==1) {			// 벽을 뚫는 경우.
		if (pop_n + 1 < n) {
			if (map[pop_n + 1][pop_m] == '1') {
				push_queue(pop_n + 1, pop_m, pop_distance + 1, 0);
			}
		}
		if (pop_m + 1 < m) {
			if (map[pop_n][pop_m + 1] == '1') {
				push_queue(pop_n, pop_m + 1, pop_distance + 1, 0);
			}
		}
		if (pop_n - 1 >= 0) {
			if (map[pop_n - 1][pop_m] == '1') {
				push_queue(pop_n - 1, pop_m, pop_distance + 1, 0);
			}
		}
		if (pop_m - 1 >= 0) {
			if (map[pop_n][pop_m - 1] == '1') {
				push_queue(pop_n, pop_m - 1, pop_distance + 1, 0);
			}
		}
	}


}

void bfs(int current_n, int current_m) {
	int pop_n = current_n, pop_m = current_m;
	int pop_distance = 1, pop_chance;
	push_queue(current_n, current_m, 1, 1);
	while (!(pop_n==end_n&&pop_m==end_m) && (que.size() != 0)) {
		pop_queue(&pop_n, &pop_m, &pop_distance, &pop_chance);
		que.pop();
		act(pop_n, pop_m, pop_distance, pop_chance);
	}
	if (pop_n == end_n && pop_m == end_m) {
		min_distance = pop_distance;
	}
}

int main() {
	input();
	bfs(0, 0);
	cout << min_distance;
	return 0;
}