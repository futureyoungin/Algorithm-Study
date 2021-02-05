#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 2147483647

using namespace std;

int N, M, k;
int map[11][11], bridge[7][7], parent[7];	//bridge[a][b]: a섬과 b섬을 잇는 다리의 최소 길이 저장
bool visited[11][11];						//change_Island()를 돌릴 때 필요한 array
vector<pair<int, int>> island_start[7];				//각 라벨 별 섬의 좌표 저장
vector<pair<pair<int, int>, int>> bridge_total;	//bridge_total {{a, b}, a와 b를 잇는 다리의 최소 길이} 저장

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
	return a.second < b.second;
}

void change_number(int i, int j, int k);
void dfs(int x, int y, int dir, int cnt, int start);
void get_bridge_length(int start);
int parent_check(int node);
void same_parent(int a, int b);
bool check_all();

void Input(){
	cin >> N >> M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> map[i][j];
		}
	}
}

void change_Island(){
	k = 1;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(map[i][j]==1 && visited[i][j]==false) {change_number(i, j, k); k++;}
		}
	}
	k--;
}

void change_number(int i, int j, int k){
	if(i<0 || j<0|| i>=N || j>=M) return;
	if(visited[i][j]==true || map[i][j]==0) return;

	map[i][j] = k;
	island_start[k].push_back({i, j});
	visited[i][j] = true;

	change_number(i+1, j, k);
	change_number(i, j+1, k);
	change_number(i-1, j, k);
	change_number(i, j-1, k);
}

void get_bridge(){
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++){
			bridge[i][j] = MAX;
		}
	}
	for(int i=1;i<=k;i++){
		get_bridge_length(i);
	}
	for(int i=1;i<=k;i++){
		for(int j=i+1;j<=k;j++){
			if(bridge[i][j]!= MAX) bridge_total.push_back({{i, j}, bridge[i][j]});
		}
	}
}

void get_bridge_length(int start){
	for(int i = 0 ; i < island_start[start].size(); i++){
		int x = island_start[start][i].first, y = island_start[start][i].second;
		for (int dir = 0; dir<4; dir++){
			dfs(x, y, dir, 0, start);
		}
	}
}

void dfs(int x, int y, int dir, int cnt, int start){
	int nx = x + dx[dir], ny = y + dy[dir];
	if(nx < 0 || ny < 0 || nx >= N || ny >= M) return;

	int now = map[nx][ny];

	if (now == 0) dfs(nx, ny, dir, cnt+1, start);
	else if(now != start){
		if(cnt > 1){
			if(bridge[start][now] > cnt){
				bridge[start][now] = cnt;
				bridge[now][start] = cnt;
			}
			return;
		}
	}
}

void get_min_length(){
	int answer = 0;

	sort(bridge_total.begin(), bridge_total.end(), comp);
	
	for(int i=1;i<=k;i++) parent[i] = i;
	for(int i=0;i<bridge_total.size();i++){	//connect bridges
		int start = bridge_total[i].first.first, end = bridge_total[i].first.second;
		int length = bridge_total[i].second;
		if(parent_check(start) != parent_check(end)){
			answer += length;
			same_parent(start, end);
		}
	}

	if(check_all() == true) cout << answer << "\n";
	else cout << "-1\n";
}

bool check_all(){
	bool answer = true; int tmp = parent_check(1);
	for(int i=2;i<=k;i++){
		if(tmp != parent_check(i))
			return false;
		tmp = parent_check(i);
	}
	return answer;
}

int parent_check(int node){
	if(parent[node]==node)	return node;
	return parent[node] = parent_check(parent[node]);
}

void same_parent(int a, int b){
	parent[parent[a]] = parent[b];
}

void print_map(){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++)
			cout << map[i][j] << " ";
		cout << "\n";
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("Input.txt", "r", stdin);

	Input();				//입력 받기
	change_Island();		//입력 받은 배열로부터 섬 라벨 붙이기
	get_bridge();			//각 섬을 연결하는 다리의 최소길이 구하기
	get_min_length();	//다리 길이 합의 최솟값 + 섬들이 모두 연결 되어있는지 확인
	
	return 0;
}