#include <iostream>
#include <vector>

using namespace std;

int main(){
	int N, K, answer;
	cin >> N >> K;

	int left = 1, right = K;

	while(left<=right){
		int cnt = 0, mid = (left+right)/2;
		for(int i=1;i<=N;i++){
			cnt += min(mid/i, N);
		}
		if(cnt < K){
			left = mid+1;	
		}else{
			answer = mid;
			right = mid-1;
		}
	}


	cout << answer << "\n";

	return 0;
}
