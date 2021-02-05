#include <iostream>
#include <vector>
#include <queue>

#define MAX 2147483647
using namespace std;

struct point{
	int x, y;
};

struct passenger{
	point src, dst;
	bool visited;
};

int N, M, fuel;
point taxi;
int board[21][21];
vector<passenger> p;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
bool flag;

void Input(){
	cin >> N >> M >> fuel;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			cin >> board[i][j];

	cin >> taxi.x >> taxi.y;

	for(int i=0;i<M;i++){
		point a, b;
		cin >> a.x >> a.y >> b.x >> b.y;
		p.push_back({a, b, false});
	}
}

void finish(){//강종 함수
	cout << "-1\n"; exit(0);
}

int get_distance(point start, point fin){
	//start에서 fin 까지의 거리값 리턴
	//도착하지 못 할 시 -1 리턴
	queue<pair<point, int>> q;
	q.push({start, 0});
	bool visited[21][21] = {false};
	visited[start.x][start.y] = true;
	while(!q.empty()){
		point front = q.front().first; int cnt = q.front().second; q.pop();
		if(fin.x == front.x && fin.y == front.y){
			return cnt;
		}
		for(int dir = 0; dir < 4; dir++){
			int nx = front.x + dx[dir], ny = front.y + dy[dir];
			if(nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
			if(visited[nx][ny] || board[nx][ny] == 1) continue;
			visited[nx][ny] = true;
			q.push({{nx, ny}, cnt+1});
		}
	}
	return -1;
}

int swap_now(int now, int j){
	//now점과 j점의 행과 열 비교
	if (now == -1) return j;
	if(p[now].src.x > p[j].src.x) return j;
	else if(p[now].src.x == p[j].src.x && p[now].src.y > p[j].src.y) return j;
	else return now;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("Input.txt", "r", stdin);

	Input();

	int now = -1;
	for(int i=0;i<p.size();i++){
		int min_dist = MAX, dist;
		for(int j=0;j<p.size();j++){
			flag = false;	// 도착하지 못 할 시 true. for문이 끝났을 때도 true이면 강종
			if (p[j].visited == false){
				dist = get_distance(taxi, p[j].src);
				if (dist==-1){
					flag = true;
				}else flag = false;
				if(min_dist >= dist && flag == false){
					if(min_dist == dist) now = swap_now(now, j);
					else now = j;
					min_dist = dist;
				}
			}
		}

		if(flag) finish();

		p[now].visited = true;
		taxi.x = p[now].src.x; taxi.y = p[now].src.y;
		fuel = fuel - min_dist;

		int used_fuel = get_distance(taxi, p[now].dst);
		if(fuel-used_fuel < 0 || used_fuel == -1){
			finish();
		}

		fuel += used_fuel;
		taxi.x = p[now].dst.x; taxi.y = p[now].dst.y;

	}

	cout << fuel << "\n";

	return 0;
}