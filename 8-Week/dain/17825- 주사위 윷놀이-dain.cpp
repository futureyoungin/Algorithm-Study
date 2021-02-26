#include <iostream>
using namespace std;

int route[34], score[34], blue[34];
bool visited[34];
int dice[10], token[4];

int ans = 0;

void dfs(int idx, int sum){
	if(idx == 10){
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int now = token[i], next = now;
		int move = dice[idx];

		if(blue[now] > 0){	//파란 화살표
			next = blue[next];
			move--;
		}

		while(move--) next = route[next];

		if(next!=21 && visited[next]) continue;

		visited[now] = false; visited[next] = true;
		token[i] = next;

		dfs(idx+1, sum+score[next]);

		visited[now] = true; visited[next] = false;
		token[i] = now;
		
	}
}

int main(){
	//init route board
	for (int i = 0; i < 21; i++) route[i] = i+1;	//빨간 화살표만 쫓아갔을 때
	route[21] = 21; 	//FINISH NODE
	for (int i = 22; i < 27; i++) route[i] = i+1;
	route[27] = 20; route[28] = 29; route[29] = 30; route[30] = 25; route[31] = 32; route[32] = 25;

	//init score board
	for (int i = 0; i < 21; i++) score[i] = 2 * i;
	score[22] = 13; score[23] = 16; score[24] = 19;
	score[25] = 25; score[26] = 30; score[27] = 35;
	score[28] = 28; score[29] = 27; score[30] = 26;
	score[31] = 22; score[32] = 24;

	//init blue board -> 파란 화살표 용
	blue[5] = 22; blue[10] = 31; blue[15] = 28;

	//주사위 입력
	for (int i = 0; i < 10; i++) cin >> dice[i];

	dfs(0,0);

	cout << ans << "\n";

	return 0;
}