#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cnt, M, N, K;
vector<int> cnt_num;
bool visited[101][101];

void check_white(int i, int j){
	if(i < 0 || j < 0 || i >= N || j >= M) return;
	if(visited[i][j]) return;
	visited[i][j] = true;
	cnt++;
	check_white(i+1, j);
	check_white(i, j+1);
	check_white(i-1, j);
	check_white(i, j-1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("Input.txt", "r", stdin);

	int x1, x2, y1, y2;

	cin >> M >> N >> K;

	for(int t=0;t<K;t++){
		cin >> x1 >> y1 >> x2 >> y2;
		for(int i=x1;i<x2;i++){
			for(int j=y1;j<y2;j++){
				visited[i][j] = true;
			}
		}
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(!visited[i][j]){
				cnt = 0;
				check_white(i, j);
				if (cnt!=0) cnt_num.push_back(cnt);
			}
		}
	}
	sort(cnt_num.begin(), cnt_num.end());
	cout << cnt_num.size() << "\n";
	for(int i=0;i<cnt_num.size();i++){
		cout << cnt_num[i] << " ";
	}
	cout << "\n";

	return 0;
}