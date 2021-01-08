#include <iostream>

using namespace std;

int board[10][10];
bool row[10][10];
bool col[10][10];
bool square[10][10];

void get_input(){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cin >> board[i][j];
			if(board[i][j]!=0){
				row[i][board[i][j]] = true;
				col[j][board[i][j]] = true;
				square[(i/3)*3 + (j/3)][board[i][j]] = true;
			}
		}
	}
}

void print_sudoku(){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}

void solution(int cnt){
	if(cnt==81){
		print_sudoku();
		exit(0);
	}

	int y = cnt/9; int x = cnt%9;

	if(board[y][x] == 0){
		for(int i=1;i<=9;i++){
			if(col[x][i] == false && row[y][i] == false && square[(y/3)*3 + (x/3)][i] == false){
				col[x][i] = true;
				row[y][i] = true;
				square[(y/3)*3 + (x/3)][i] = true;
				board[y][x] = i;
				
				solution(cnt+1);
				
				col[x][i] = false;
				row[y][i] = false;
				square[(y/3)*3 + (x/3)][i] = false;
				board[y][x] = 0;

			}
		}
	}else	solution(cnt+1);
}

int main(){
	get_input();
	solution(0);
}