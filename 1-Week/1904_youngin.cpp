#include <iostream>
#include <cstring>

using namespace std;

int total = 0;

void op(int *array, int N) {
	if (N > 1) {
		for (int i = 2; i <= N; i++) {
			array[i] = (array[i - 1] + array[i - 2])%15746;
		}
	}
}

int main() {
	int N;
	cin >> N;
	int *array = new int[N + 1];
	array[0] = array[1] = 1;
	op(array, N);
	int result = array[N];
	cout << result;
	return 0;
}