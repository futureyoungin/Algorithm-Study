#include <iostream>
#define MAX 2147483647

using namespace std;

int main(){
	int N, target, answer = MAX;
	int num[100001];

	cin >> N >> target;

	for(int i=0;i<N;i++){
		cin >> num[i];
	}

	int left = 0, right = 0, sum = 0;

	while(left <= right){
		if(sum >= target){
			answer = min(answer, right-left);
			sum -= num[left++];
		}else if(sum < target){
			if(right == N) break;
			sum += num[right++];
		}
	}

	if(answer == MAX) cout << 0 << "\n";
	else cout << answer << "\n";

	return 0;
}
