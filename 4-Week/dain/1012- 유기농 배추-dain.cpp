#include <iostream>
#include <cstring>

using namespace std;

int T, M, N, K, X, Y;
int board[51][51];
bool visited[51][51];
int num_worm;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void visit_check(int x, int y){
	if(x<0 || y < 0 || x > M-1 || y > N-1) return;
	if(board[x][y]==0 || visited[x][y] == true)	return;

	visited[x][y] = true;

	for(int dir = 0; dir<4; dir++){
		int next_x = x+dx[dir], next_y = y+dy[dir];
		visit_check(next_x, next_y);
	}
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("Input.txt", "r", stdin);
	cin >> T;
	while(T--){
		num_worm = 0;
		memset(visited, false, sizeof(visited));
		memset(board, 0, sizeof(board));

		cin >> M >> N >> K;
		
		for(int input = 0; input<K;input++){
			cin >> X >> Y;
			board[X][Y] = 1;
		}

		for(int i=0;i<M;i++){
			for(int j=0; j<N; j++){
				if(board[i][j]==1 && visited[i][j] == false){
					visit_check(i, j);
					num_worm++;
				}
			}
		}
		cout << num_worm << "\n";

	}


	return 0;
}
