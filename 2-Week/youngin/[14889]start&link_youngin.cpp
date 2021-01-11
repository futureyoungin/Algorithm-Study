#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#define MIN(a,b) a<b? a:b

int n;
int S[25][25] = { 0, };
int team_A[25] = { 0, };
int team_B[25] = { 0, };
int min_value = 100000;

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> S[i][j];
		}
	}
}

void left_team() {
	memset(team_B, 0, sizeof(int) * 25);
	int n_member = 0;
	for (int i = 1; i<=n; i++) {
		int is_there = 0;
		for (int j = 0; j < n / 2; j++) {
			if (team_A[j] == i) is_there = 1;
		}
		if (!is_there) {
			team_B[n_member++] = i;
		}
	}
}


int abs_team_value() {
	left_team();
	int A_value = 0, B_value = 0;
	for (int i = 0; i < n / 2; i++) {
		int A_member = team_A[i];
		int B_member = team_B[i];
		for (int j = i+1; j < n / 2; j++) {
			if (i == j) continue;
			A_value += S[A_member][team_A[j]];
			A_value += S[team_A[j]][A_member];
			B_value += S[B_member][team_B[j]];
			B_value += S[team_B[j]][B_member];
		}
	}
	return abs(A_value - B_value);
}

void op(int n_member, int before_member) {
	if (n_member == n / 2) {
		min_value = MIN(min_value, abs_team_value());
		return;
	}
	int temp_before_member = before_member;
	for (int i = 2; i <= n; i++) {
		if (i <= before_member) {
			continue;
		}
		team_A[n_member++] = i;
		before_member = i;
		op(n_member, before_member);
		team_A[n_member--] = 0;
		before_member = temp_before_member;

	}
}

int main() {
	input();
	team_A[0] = 1;
	op(1, 1);

	cout << min_value;

	return 0;
}