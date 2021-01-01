#include <iostream>
#include <vector>

using namespace std;

int main(){
	int N, K;
	cin >> N >> K;
	int weight[101], value[101];
	int dp[101][100001];

	for(int i=0;i<N;i++){
		scanf("%d %d", &weight[i], &value[i]);
	}

	for(int i=1;i<=N;i++){
		for(int j=1;j<=K;j++){
			if(j-weight[i-1]>=0)
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i-1]]+value[i-1]);
			else
				dp[i][j] = dp[i-1][j];
		}
	}

	cout << dp[N][K] << "\n";

}