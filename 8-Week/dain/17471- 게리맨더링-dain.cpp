#include <iostream>
#include <vector>
#include <queue>
#define MAX 2147483647

using namespace std;

int N, K, temp, min_diff;
vector<int> population(11);
vector<int> area[11];
int color[11];	//default: 0 red: 1 blue: 2

void Input(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i=1;i<=N;i++){
		cin >> population[i];
		color[i] = 0;
	}
	for(int i=1;i<=N;i++){
		cin >> K;
		for(int k=1;k<=K;k++){
			cin >> temp;
			area[i].push_back(temp);
		}
	}
}

int get_first(int block_color){
	for(int i=1;i<=N;i++){
		if(color[i] == block_color) return i;
	}
}


int bfs(int block_color, int start, int cnt){
	//check graph connected and return total population of graph
	//if not connected, return -1
	//if bfs_cnt == cnt, we used all the nodes of block_color. If not, somewhat seperated.
	int total = population[start], bfs_cnt = 1;
	bool visited[11] = {false}; visited[start] = true;
	queue<int> q; q.push(start);
	while(!q.empty()){
		int top = q.front(); q.pop();
		for(int i=0;i<area[top].size();i++){
			int next = area[top][i];
			if(!visited[next] && color[next]==block_color){
				q.push(next);
				visited[next] = true;
				total += population[next];
				bfs_cnt++;
			}
		}
	}
	if(bfs_cnt==cnt)	return total;
	return -1;
}

void dfs(int idx, int red_cnt, int blue_cnt){
	if(red_cnt + blue_cnt==N){
		if(red_cnt==0 || blue_cnt==0) return;
		int pop_red = bfs(1, get_first(1), red_cnt);
		int pop_blue = bfs(2, get_first(2), blue_cnt);
		if(pop_red==-1 || pop_blue==-1) return;
		else{
			min_diff = min(min_diff, abs(pop_red-pop_blue));
			return;
		}
	}

	color[idx] = 1;
	dfs(idx+1, red_cnt+1, blue_cnt);
	color[idx] = 2;
	dfs(idx+1, red_cnt, blue_cnt+1);
}

int main(){
	Input();
	min_diff = MAX;
	dfs(1, 0, 0);
	if(min_diff == MAX) min_diff = -1;
	cout << min_diff << "\n";
	return 0;
}