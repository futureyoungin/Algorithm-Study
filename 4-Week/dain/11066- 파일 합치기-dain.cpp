#include <iostream>

#define MAX 2147483647

using namespace std;
 
int dp[501][501];
int num[501], sum[501];
int T, P;
 
int main() {
	cin >> T;
	while (T--) {
		cin >> P;
		for (int i=1;i<=P; i++) {
			cin >> num[i];
			sum[i] = sum[i-1] + num[i];
		}

		for (int r = 1; r<=P; r++) {
			for (int a=1; a+r <= P; a++){
				dp[a][a+r] = MAX;

				for (int k = a; k<a+r; k++){
					dp[a][a+r] = min(dp[a][a+r], dp[a][k] + dp[k + 1][a+r] + sum[a+r] - sum[a - 1]);
				}
			}
		}
		cout << dp[1][P] << "\n";
	}
}