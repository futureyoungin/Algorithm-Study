#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 75000

using namespace std;

int T, N;
int x, y;
vector<pair<int, int>> island;
vector<int> y_island;
int tree[MAX*4];

bool comp_island(pair<int, int> a, pair<int, int> b){
	if(a.first == b.first) return a.second > b.second;
	return a.first < b.first;
}

void init_tree(int now, int start, int end) {
	if (start>end) 
		return;
	if (start==end) {
		tree[now] = 0;
		return;
	}
	tree[now] = 0;
	int mid = (start+end)/2;
	init_tree(now*2, start, mid);
	init_tree(now*2+1, mid+1, end);
}

void update_tree(int now, int target, int start, int end) {
	if (target > end || target < start) 
		return;
	if (start == end) {
		tree[now]++;
		return;
	}
	int mid = (start+end)/2;
	update_tree(now*2, target, start, mid);
	update_tree(now*2+1, target, mid+1, end);
	tree[now] = tree[now*2] + tree[now*2+1];
}

int query(int now, int left, int right, int start, int end){
	if(left > end || right < start) return 0;
	if(left <= start && end <= right)	return tree[now];
	int mid = (start+end)/2;
	return query(now*2, left, right, start, mid) + query(now*2+1, left, right, mid+1, end);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	for(int k=0;k<T;k++) {
		cin >> N;
		long long answer = 0;
		island.clear(); y_island.clear();
		init_tree(1, 0, N - 1);
		for (int i = 0; i < N; i++) {
			cin >> x >> y;
			island.push_back({ x,y });
			y_island.push_back(y);
		}
		sort(island.begin(), island.end(),comp_island);
		sort(y_island.begin(), y_island.end(), greater<int>());
		for (int i = 0; i < island.size(); i++) {
			int x = island[i].first, y = island[i].second;
			int index = upper_bound(y_island.begin(), y_island.end(), y, greater<int>()) - y_island.begin() - 1;
			answer += query(1, 0, index, 0, N - 1);
			update_tree(1, index, 0, N - 1);
		}
		cout << answer << "\n";
	}
	return 0;	
}
