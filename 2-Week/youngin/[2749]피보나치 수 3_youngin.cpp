#include <iostream>

using namespace std;

#define LONG unsigned long long

int m = 1000000;
int m1, m2, cnt;
LONG n;


LONG period_pissano() {
	LONG period = 0;
	m1 = 0, m2 = 1;
	cnt = 0;
	while (1) {
		if (m1 == 0 && m2 == 1 && period != 0) {
			break;
		}
		int temp = m1;
		m1 = m2;
		m2 = (temp + m1) % m;
		period++;
	}
	return period;
}

int pibonacci3(LONG n_fibonacci) {
	m1 = 0, m2 = 1;
	LONG result = 1;
	while (1) {
		if (result == n_fibonacci)
			break;
		int temp = m1;
		m1 = m2;
		m2 = (temp + m1) % m;
		result++;
	}
	return m2;
}

int main() {
	cin >> n;
	LONG period = period_pissano();
	LONG n_fibonacci = n % period;
	cout << pibonacci3(n_fibonacci);

	return 0;
}