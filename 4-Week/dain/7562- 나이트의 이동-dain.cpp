#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int T, I;
int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int board[301][301];

struct Position{
	int x, y;
};

void move_knight(Position now, Position target){
	queue<Position> q;
	q.push(now);
	while(!q.empty()){
		Position front = q.front();
		q.pop();
		if(front.x == target.x && front.y == target.y){
			cout << board[target.x][target.y] << "\n";
			return;
		}
		for(int dir=0;dir<8;dir++){
			Position next;
			next.x = front.x + dx[dir]; next.y = front.y + dy[dir];
			if(next.x < 0 || next.y < 0 || next.x >= I || next.y >=I)	continue;
			if(board[next.x][next.y] == 0){
				q.push(next);
				board[next.x][next.y] = board[front.x][front.y]+1;
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("Input.txt", "r", stdin);

	cin >> T;

	while(T--){
		memset(board, 0, sizeof(board));
		cin >> I;
		Position now, target;
		cin >> now.x >> now.y >> target.x >> target.y;

		move_knight(now, target);
	}

	return 0;
}
