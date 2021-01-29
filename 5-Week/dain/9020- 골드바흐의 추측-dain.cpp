#include <iostream>

using namespace std;

bool prime(int n){
	if(n==2) return true;
	if(n==1 || n%2==0) return false;
	for(int i=3;i<=n/2;i++){
		if(n%i==0) return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, n;
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = n/2; i>=2; i--){
			if(prime(i) && prime(n-i)){
				cout << i << " " << n-i << "\n";
				break;
			}
		}
	}

	return 0;
}