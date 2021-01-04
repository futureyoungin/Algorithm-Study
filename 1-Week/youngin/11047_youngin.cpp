#include <iostream>

using namespace std;
int n, k;

int make_coin(int *coin) {
	int repeat = 0;

	for (int i = n - 1; i >= 0; i--) {
		int ret = k / coin[i];
		if (ret > 0) {
			repeat += ret;
			k = k - ret * coin[i];
		}
	}
	return repeat;
}


int main(void) {
	cin >> n >> k;
	int *coin = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	cout << make_coin(coin);

	return 0;
}