#include <iostream>

#define MAX 2147483647

using namespace std;

int map[11][11];
int paper_size[6] = {0, 5, 5, 5, 5, 5};

int min_count = MAX;

void Input(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			cin >> map[i][j];
		}
	}
}

void dfs(int x, int y, int cnt){
	if(x==10){
		dfs(0, y+1, cnt);
		return;
	}

	if(y==10){
		min_count = min(min_count, cnt);
		return;
	}

	if(map[x][y]==0){
		dfs(x+1, y, cnt);
		return;
	}

	for(int k=5; k>0;k--){
		bool flag = true;
		if(paper_size[k] <= 0 || x+k > 10 || y+k > 10) continue;
		for(int i=0;i<k;i++){
			for(int j=0;j<k;j++){
				if(map[x+i][y+j] == 0){
					flag= false;
					break;
				}
			}
			if(!flag) break;
		}
		if(!flag) continue;

		for(int i=0;i<k;i++){
			for(int j=0;j<k;j++){
				map[x+i][y+j] = 0;
			}
		}

		paper_size[k]--;

		dfs(x+k, y, cnt+1);

		for(int i=0;i<k;i++){
			for(int j=0;j<k;j++){
				map[x+i][y+j] = 1;
			}
		}

		paper_size[k]++;
	}

}

int main(){
	Input();
	dfs(0, 0, 0);
	if(min_count == MAX) cout << -1 << "\n";
	else cout << min_count << "\n";
	return 0;
}