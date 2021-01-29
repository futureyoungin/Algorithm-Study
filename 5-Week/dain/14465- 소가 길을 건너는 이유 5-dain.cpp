#include <iostream>

using namespace std;

int main(){
	freopen("Input.txt", "r", stdin);

	int N, K, B, traffic, min_=2147483647;
	int broken[1000001];

	cin >> N >> K >> B;
	for(int i=0;i<B;i++){
		cin >> traffic;
		broken[traffic] = 1;
	}

	for(int i=1;i<=N;i++) 
		broken[i] += broken[i-1];

	for(int i=1; ; i++){
		if(i+K-1 > N) break;
		min_ = min(min_, broken[i+K-1] - broken[i-1]);
	}

	cout << min_ << "\n";

	return 0;
}

//살짝 다른 구현 방법 - 백준 채점 시간이 4초 더 걸림(while loop 때문이라 추정)
// #include <iostream>

// using namespace std;

// int main(){
// 	int N, K, B, traffic, min_=2147483647;
// 	int broken[1000001];

// 	cin >> N >> K >> B;
// 	for(int i=0;i<B;i++){
// 		cin >> traffic;
// 		broken[traffic] = 1;
// 	}

// 	int start = 1, end = start, cnt = broken[start];

// 	while(end <= N){
// 		if(end-start+1 != K){
// 			end++;
// 			cnt += broken[end];
// 		}else{
// 			min_ = min(min_, cnt);
// 			cnt -= broken[start];
// 			start++;
// 		}
// 	}

// 	cout << min_ << "\n";

// 	return 0;
// }