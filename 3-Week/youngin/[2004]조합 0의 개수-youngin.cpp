#include <iostream>

#include <algorithm> // min
using namespace std;

int n, m;

int n_pow(int number, int power) {
	int temp_n = number;
	int result = 0;
	while (temp_n > 1) {
		result += temp_n / power;
		temp_n = temp_n / power;
	}
	return result;
}


int main() {
	cin >> n >> m;
	int two = n_pow(n, 2) - n_pow(n - m, 2) - n_pow(m, 2);
	int five = n_pow(n, 5) - n_pow(n - m, 5) - n_pow(m, 5);
	int result = min(two, five);
	cout << result;
	return 0;
}