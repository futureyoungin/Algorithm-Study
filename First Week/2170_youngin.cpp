#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>


#define MAX(a,b) a>b? a:b
#define MIN(a,b) a<b? a:b

using namespace std;
int n;
int a, b;
vector<pair<int, int>> set_point;
int result = 0;


void op() {
	sort(set_point.begin(), set_point.end());
	vector<pair<int, int>>::iterator iter;
	int p_a = set_point[0].first, p_b = set_point[0].second;
	for (iter = set_point.begin()+1; iter != set_point.end(); iter++) {
		if (p_b < iter->first) {
			result += p_b - p_a;
			p_a = iter->first, p_b = iter->second;
		}
		else if (p_b >= iter->first && p_b < iter->second) {
			p_b = iter->second;
		}
	}
	result += p_b - p_a;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int big, small;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		big = MAX(a, b);
		small = MIN(a, b);
		set_point.push_back(make_pair(small, big));
	}

	op();
	cout << result;
	return 0;
}