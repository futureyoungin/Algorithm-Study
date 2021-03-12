#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main(){
	int T, N, M, temp;
	int dp[10001]; 
	cin >> T;

	while(T--){
		vector<int> v;
		cin >> N;
		for(int i=0;i<N;i++){
			cin >> temp;
			v.push_back(temp);
		}

		cin >> M;

		memset(dp, 0, sizeof(dp)); dp[0] = 1;
		for(int i=0; i<v.size(); i++){
			for(int j=v[i];j<=M;j++){
				dp[j] += dp[j-v[i]];
			}
		}
		cout << dp[M] << "\n";
	}


	return 0;
}