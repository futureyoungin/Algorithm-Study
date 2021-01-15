#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string a, b;
int dp[1001][1001] = { 0, };
string lcs[1001][1001];


void input() {
	cin >> a >> b;
}

int LCS() {
	int sub_length = 0;
	for (int i = 0; i < a.length(); i++) {
		for (int j = 0; j < b.length(); j++) {
			if (a[i] == b[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
				lcs[i + 1][j + 1] = lcs[i][j] + a[i];
			}
			else {
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
				if (dp[i + 1][j] > dp[i][j + 1]) {
					lcs[i + 1][j + 1]  = lcs[i+1][j];
				}
				else {
					lcs[i + 1][j + 1] = lcs[i][j+1];
				}
			}
		}
	}
	return dp[a.length()][b.length()];
}



int main() {
	input();
	int ret = LCS();
	cout << ret << "\n";
	if (ret != 0)
		cout << lcs[a.length()][b.length()];

	return 0;
}