#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point{
	int x, y, cnt = 0;
};

int R, C;
char forest[51][51];
bool visited[51][51] = {false,};

queue<Point> water;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

Point hedgehog, beaver;

void Input(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("Input.txt", "r", stdin);

	cin >> R >> C;

	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cin >> forest[i][j];
			if(forest[i][j] == 'S') hedgehog = {i, j};
			if(forest[i][j] == 'D') beaver = {i, j};
			if(forest[i][j] == '*') water.push({i, j});
		}
	}
}

int simulation(){
	queue<Point> hq;
	hq.push(hedgehog);

	visited[hedgehog.x][hedgehog.y] = true;

	while(!hq.empty()){
		//flood first
		int watersize = water.size();
		for(int i=0;i<watersize;i++){
			int nowx = water.front().x, nowy = water.front().y;
			water.pop();
			for(int dir=0;dir<4;dir++){
				int nx = nowx + dx[dir], ny = nowy + dy[dir];
				if(nx < 0|| ny < 0 || nx >= R || ny >= C) continue;
				if(forest[nx][ny]=='.'){
					forest[nx][ny] = '*';
					water.push({nx, ny});
				}
			}
		}
		//now hedgehog
		for(int i=0;i<hq.size();i++){
			Point now_h = hq.front(); hq.pop();
			int hx = now_h.x, hy = now_h.y;

			if(hx == beaver.x && hy == beaver.y)
				return now_h.cnt;
			
			for(int dir=0;dir<4;dir++){
				int hhx = hx + dx[dir], hhy = hy + dy[dir];
				
				if(hhx < 0|| hhy < 0 || hhx >= R || hhy >= C) continue;
				if(visited[hhx][hhy]) continue;
				if(forest[hhx][hhy]=='X' || forest[hhx][hhy]=='*') continue;
				
				visited[hhx][hhy] = true;
				hq.push({hhx, hhy, now_h.cnt+1});
			}
		}
	}
	return -1;
}

int main(){
	Input();
	int ret = simulation();
	if(ret == -1)
		cout << "KAKTUS\n";
	else cout << ret << "\n";
	return 0;
}