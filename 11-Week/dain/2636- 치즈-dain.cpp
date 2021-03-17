#include <iostream>

using namespace std;

int R, C;
int cheese[101][101], tmp_cheese[101][101];
int cheese_cnt = 0;
bool visited[101][101] = {false,};

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void Input(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;

	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cin >> cheese[i][j];
			if(cheese[i][j] == 1) cheese_cnt++;
		}
	}
}

void copy_map(int a[101][101], int b[101][101]){
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			a[i][j] = b[i][j];
		}
	}
}

void dfs(int x, int y){
	for(int dir=0;dir<4;dir++){
		bool flag = true;
		int nx = x+dx[dir], ny = y+dy[dir];
		if(nx<0 || ny<0 || nx >= R || ny >=C) continue;
		if(visited[nx][ny]) continue;
		visited[nx][ny] = true;
		if(cheese[nx][ny]==1){
			tmp_cheese[nx][ny] = 0;
			cheese_cnt--;
			flag = false;
		}
		if (flag) dfs(nx, ny);		
	}
}

int main(){
	Input();

	int prev = cheese_cnt;
	int cnt = 0;

	while(cheese_cnt>0){
		cnt++;
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				visited[i][j] = false;
			}
		}
		copy_map(tmp_cheese, cheese);
		prev = cheese_cnt;
		dfs(0, 0);
		copy_map(cheese, tmp_cheese);
	}
	cout << cnt << "\n";
	cout << prev << "\n";
	return 0;
}