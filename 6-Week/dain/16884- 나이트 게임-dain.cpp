#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, N;
	cin >> T;
	while(T--){
		cin >> N;
		if(N%2==0) cout << "cubelover\n";
		else cout << "koosaga\n";
		//레이튼 교수?
	}
	return 0;
}