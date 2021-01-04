#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX(a,b) a>b? a:b
#define MAX_TREE 1000000

int n;
long long m;
long long total_height = 0;
int max_height = 0;
int trees[MAX_TREE] = { 0, };

long long cutting(int cut) {
	long long temp_height = 0;
	for (int i = 0; i < n; i++) {
		if (trees[i] > cut) {
			temp_height += trees[i] - cut;
		}
	}
	return temp_height;
}

int op() {
	int left = 0, right = max_height;
	int mid = 0;
	int result = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		long long left_tree = cutting(mid);
		if (left_tree < m) {
			right = mid - 1;
		}
		else if(left_tree > m){
			left = mid + 1;
		}
		else {
			break;
		}
	}

	result = (left+right)/2;
	return result;
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> trees[i];
		total_height += trees[i];
		max_height = MAX(max_height, trees[i]);
	}
	sort(trees, trees + n);

	cout << op();
	return 0;
}