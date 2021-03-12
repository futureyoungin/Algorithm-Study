#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, L, R, answer;
bool flag;
int A[51][51];
int visited[51][51];
int sum, cnt;
vector<pair<int, int>> v;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void Input(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> L >> R;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> A[i][j];
		}
	}
}


void bfs(int i, int j);
void merge_union();

void get_union(){
	answer = 0;
	while(true){
		memset(visited, false, sizeof(visited));
		flag = false;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(visited[i][j]) continue;
				bfs(i, j);
			}
		}
		if(flag)
			answer++;
		else break;
	}
	cout << answer << "\n";
}

void bfs(int i, int j){
	queue<pair<int, int>> q;
	sum = A[i][j]; cnt = 1; v.clear();
	q.push({i, j});
	visited[i][j] = true;
	v.push_back({i, j});
	while(!q.empty()){
		pair<int, int> frt = q.front(); q.pop();
		int x = frt.first, y = frt.second;

		for(int dir = 0; dir<4; dir++){
			int nx = x + dx[dir], ny = y + dy[dir];
			if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if(visited[nx][ny]) continue;

			if(L <= abs(A[x][y] - A[nx][ny]) && abs(A[x][y] - A[nx][ny]) <= R){
				visited[nx][ny] = true;
				sum += A[nx][ny]; 
				cnt++;
				v.push_back({nx, ny});
				q.push({nx, ny});
			}
		}
	}

	if(v.size()>1){
		merge_union();
		flag = true;
	}
}

void merge_union(){
	int average = sum / cnt;
	for(int i=0;i<v.size();i++){
		int x = v[i].first, y = v[i].second;
		A[x][y] = average;
	}
}

int main(){
	Input();
	get_union();
	return 0;
}