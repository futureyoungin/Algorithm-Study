#include <iostream>
#include <string.h>

#define DIVISION 15746

using namespace std;

int fibonacci[1000001];

void get_fibonacci(int N){
	fibonacci[1] = 1; fibonacci[2] = 2;
	for(int i = 3; i<= N; i++){
		fibonacci[i] = (fibonacci[i-1] + fibonacci[i-2])%15746;
	}
}

int main(){
	int N, total = 0;
	memset(fibonacci, 0, sizeof(int));
	cin >> N;

	get_fibonacci(N);

	cout << fibonacci[N] % DIVISION << "\n";
}