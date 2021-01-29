#include <iostream>
#include <vector>
#include <queue>

#define MAX 2147483647

using namespace std;

int answer;
bool visited[100001];
int route[100001];
vector<int> path;

void hideandseek(int start, int end){
	queue<pair<int, int>> q;
	q.push({start, 0});
	visited[start] = true;

	while(!q.empty()){
		int x = q.front().first, cnt = q.front().second;
		q.pop();

		if(x == end){
			answer = cnt;
			while(x != start){
				path.push_back(x);
				x = route[x];
			}
			path.push_back(start);
			return;
		}

		if(x - 1 >= 0 && !visited[x-1]){
			visited[x-1] = true;
			route[x-1] = x;
			q.push({x-1, cnt + 1});
		}
		if(x + 1 >= 0 && x + 1 < 100001 && !visited[x+1]){
			visited[x+1] = true;
			route[x+1] = x;
			q.push({x+1, cnt + 1});
		}
		if(x *2 >= 0 && x * 2 < 100001 && !visited[x*2]){
			visited[x*2] = true;
			route[x*2] = x;
			q.push({x*2, cnt + 1});
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("Input.txt", "r", stdin);

	int N, K;
	cin >> N >> K;
	answer = 0;

	hideandseek(N, K);
	cout << answer << "\n";
	for(int i=path.size()-1;i>=0;i--){
		cout << path[i] << " ";
	}
	cout << "\n";

	return 0;
}