#include <iostream>
using namespace std;

#define MAX(a,b) a>b? a:b
#define MIN(a,b) a<b? a:b

int v_min = 1000000000;
int v_max = -1000000000;

int N_operator[4] = { 0, };
int Level_operator[4] = { 0, };

int op_result(int a, int b, int op) {
	if (op == 0) {
		return (a + b);
	}
	else if (op == 1) {
		return (a - b);
	}
	else if (op == 2) {
		return (a*b);
	}
	else if (op == 3) {
		return (a / b);
	}
	else {
		return 1000000002;
	}
}

void BFS(int *array, int N, int level, int result) {
	if (level >= N) {
		return;
	}

	if (level == N - 1) {
		v_max = MAX(v_max, result);
		v_min = MIN(v_min, result);
	}

	for (int op = 0; op < 4; op++) {
		if ((Level_operator[op]) >= N_operator[op]) {
			continue;
		}
		Level_operator[op]++;
		int temp = result;
		result = op_result(result, array[level + 1], op);
		level++;

		BFS(array, N, level, result);

		level--;
		result = temp;
		Level_operator[op]--;

	}
}


int main() {
	int N;
	cin >> N;
	int *array = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> array[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> N_operator[i];
	}

	BFS(array, N, 0, array[0]);

	cout << v_max << "\n";
	cout << v_min << "\n";

	return 0;
}