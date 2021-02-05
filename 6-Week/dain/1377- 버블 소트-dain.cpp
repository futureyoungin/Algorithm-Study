#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("Input.txt", "r", stdin);

	int n, answer = 0;

	cin >> n;
	vector<pair<int, int>> a(n);

	//previous algorithm: O(n^2)
	//current  algorithm: O(n*log n)

	for(int i=0;i<n;i++){
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a.begin(), a.end());	//O(n*log n)

	for(int i=0;i<n;i++){	//O(n)
		answer = max(answer, a[i].second-i);
	}	

	cout << answer + 1 << "\n";

	return 0;
}