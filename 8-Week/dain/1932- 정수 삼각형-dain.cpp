#include <iostream>

using namespace std;

int n;
int arr[501][501];
int dp[501][501];

void Input(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin >> arr[i][j];
		}
	}
}

int main(){
	Input();

	for(int i=1;i<=n;i++) dp[n][i] = arr[n][i];

	for(int i=n-1;i>0;i--){
		for(int j=1; j<=i;j++){
			dp[i][j] = arr[i][j] + max(dp[i+1][j], dp[i+1][j+1]);
		}
	}

	cout << dp[1][1] << "\n";
	return 0;
}
