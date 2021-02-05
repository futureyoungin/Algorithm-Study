#include <iostream>

using namespace std;

int parent[1000001];

int find_parent(int node){
	if(parent[node]==node)	return node;
	return parent[node] = find_parent(parent[node]);
}

void set_parent(int a, int b){
	parent[parent[a]] = parent[b];
}

bool check_cycle(int start, int end){
	if(find_parent(start)==find_parent(end))	return true;
	else{
		set_parent(start, end);
		return false;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("Input.txt", "r", stdin);

	int N, M, cnt = 0;
	bool flag = true;
	cin >> N >> M;

	for(int i=0;i<N;i++) parent[i] = i;

	for(int i=0;i<M;i++){
		int start, end;
		cnt++;
		cin >> start >> end;
		if(check_cycle(start, end)){
			cout << cnt << "\n";
			flag = false;
			return 0;
		}
	}

	if(flag) cout << "0\n";

	return 0;
}
