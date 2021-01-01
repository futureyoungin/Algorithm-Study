#include <iostream>

using namespace std;

int main(){
	int N, K, coin[11], target, total = 0;
	cin >> N >> K;

	for(int i=0;i<N;i++){
		cin >> coin[i];
	}

	for(int i=N-1;i>=0;i--){
		total += K / coin[i];
		K %= coin[i];
	}

	cout << total << "\n";
}