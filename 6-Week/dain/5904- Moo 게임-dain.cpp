#include <iostream>

using namespace std;

int N, k = 1; long long int moo[30];

char find_moo(long long n){
	if(n==1)	return 'm';
	if(n==2||n==3) return 'o';

	int i = 0;
	while(moo[i]<n) i++;
	if(moo[i-1]+1==n) return 'm';
	if(moo[i]==n || moo[i-1] + i+3 >= n) return 'o';

	return find_moo(n-moo[i-1]-(i+3));
}

int main(){
	cin >> N;
	moo[0] = 3;

	while(true){
		moo[k] = moo[k-1]*2+k+3;
		if(moo[k]>=N) break;
		k++;
	}

	cout << find_moo(N);

	return 0;
}