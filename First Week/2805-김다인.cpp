#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long N, M, t, ans, max_;

long long solution(vector<long long> tree, long long low, long long high){
	long long mid = (low+high)/2;
	long long total = 0;
	for(int i=0;i<tree.size();i++){
		if(tree[i]<mid) continue;
		total += tree[i] - mid;
	}

	if(total == M)
		return mid;
	if(low>=high)
		if(total >= M)
			return high;
		else
			return high-1;
	if(total > M)
		return solution(tree, mid+1, high);
	else
		return solution(tree, low, mid-1);
}

int main(){
	 max_ = 0;
	vector<long long> tree;
	cin >> N >> M;

	for(int i=0;i<N;i++){
		cin >> t;
		max_ = max(max_, t);
		tree.push_back(t);
	}

	ans = solution(tree, 0, max_);

	cout << ans << "\n";
}