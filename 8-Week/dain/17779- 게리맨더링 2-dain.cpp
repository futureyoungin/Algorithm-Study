#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 2147483647

using namespace std;

int N;
int map[21][21];

int get_area(int x, int y, int d1, int d2) {
	int area_pop[5] = {0};

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (r < x + d1 && c <= y && !(r >= x && c >= y - (r - x)))
				area_pop[0] += map[r][c];
			else if (r <= x + d2 && c > y && !(r >= x && c <= y + (r - x)))
				area_pop[1] += map[r][c];
			else if (r >= x + d1 && c < y - d1 + d2 && !(r <= x + d1 + d2 && c >= (y - d1 + d2 - (x + d1 + d2 - r))))
				area_pop[2] += map[r][c];
			else if (r > x + d2 && c >= y - d1 + d2 && !(r <= x + d1 + d2 && c <= (y - d1 + d2 + (x + d1 + d2 - r)))) 
				area_pop[3] += map[r][c];
			else
				area_pop[4] += map[r][c];
		}
	}

	sort(area_pop, area_pop+5);

	return area_pop[4] - area_pop[0];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N; int answer = MAX;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	for (int x = 1; x <= N - 2; x++) {
		for (int y = 2; y <= N - 1; y++) {
			for (int d1 = 1; d1 <= y - 1 && d1 <= N - x - 1; d1++) {
				for (int d2 = 1; d2 <= N - y && d2 <= N - x - 1; d2++) {
					answer = min(answer, get_area(x, y, d1, d2));
				}
			}
		}
	}

	cout << answer << "\n";

	return 0;
}