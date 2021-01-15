#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

// segment tree : 여러 개의 데이터가 연속적으로 존재할 때 특정한 범위의 데이터의 합을 구하는 방법.

#define MAX_N 100000
#define LL long long int

using namespace std;

int T, n;
int segment_tree[MAX_N*4]; // segment tree node 갯수 --> n보다 크면서 가장 작은 제곱수의 2배.
vector<pair<int, int>> islands;
vector<int> y_islands;


bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
}

void init_tree(int node, int start, int end) {
	if (start > end)
		return;

	if (start == end) {
		segment_tree[node] = 0;
		return;
	}
	segment_tree[node] = 0;
	int mid = (start + end) / 2;
	init_tree(node * 2, start, mid);
	init_tree(node * 2 + 1, mid + 1, end);
}

int query(int now, int left, int right, int start, int end) { // left, right : 구간 합 범위.
	if (left > end || right < start)                          // start, end : 인덱스 범위.
		return 0;                                             // now : 현재 node, 항상 1부터.
	if (left <= start && right >= end)
		return segment_tree[now];
	int mid = (start + end) / 2;
	return (query(now * 2, left, right, start, mid) + query(now * 2 + 1, left, right, mid + 1, end));
}

void update(int now, int target, int start, int end) {
	if (target > end || target < start)
		return;
	if (start == end) {
		segment_tree[now]++;
		return;
	}
	int mid = (start + end) / 2;
	update(now * 2, target, start, mid);
	update(now * 2 + 1, target, mid + 1, end);
	segment_tree[now] = segment_tree[now * 2] + segment_tree[now * 2 + 1];
}

void input() {
	cin >> n;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		islands.push_back(make_pair(x, y));
		y_islands.push_back(y);
	}
	sort(islands.begin(), islands.end(), cmp);                
	sort(y_islands.begin(), y_islands.end(), greater<int>()); // 내림차순.
}

LL winds() {
	LL possible = 0;
	vector<pair<int, int>>::iterator iter;
	vector<int>::iterator y_iter;

	int x, y, index;

	for (iter = islands.begin(); iter != islands.end(); iter++) {
		y = iter->second;
		index = upper_bound(y_islands.begin(), y_islands.end(), y, greater<int>()) 
            - y_islands.begin() - 1;
		possible += query(1, 0, index, 0, n - 1); // 0 ~ index까지의 합.
		update(1, index, 0, n - 1);
	}
	return possible;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	LL result;
	for (int i = 0; i < T; i++) {
		input();
		init_tree(1, 0, n - 1);
		result = winds();
		cout << result << "\n";
		islands.clear();
		y_islands.clear();
	}
	return 0;
}