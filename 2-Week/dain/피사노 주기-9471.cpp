#include <iostream>
#include <vector>

using namespace std;

int main(){
	int P, N, M;
	cin >> P;
	for(int i=0;i<P;i++){
		cin >> N >> M;

		vector<int> fib;

		fib.push_back(0); fib.push_back(1); fib.push_back(1);

		int k=3;

		while(1){
			fib.push_back(fib[k-2] + fib[k-1] % M);
			if(fib[k-1]% M == 0 && fib[k] % M ==1)
				break;
			k++;
		}

		cout << N << " " << k-1 << "\n";

		fib.clear();
	}
}