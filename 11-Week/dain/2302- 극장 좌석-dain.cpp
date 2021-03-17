#include <iostream>

using namespace std;

int N, M;
int dp[41];

void switch_seats(){
	dp[0] = 1; dp[1] = 1;
	for(int i=2; i<= N; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	int sum = 1;
	int now = 0, prev = 0;

	switch_seats();

	for(int i=0;i<M;i++){
		cin >> now;
		sum *= dp[now-prev-1];
		prev = now;
	}

	sum *= dp[N-now];
	
	cout << sum << "\n";
	return 0;
}