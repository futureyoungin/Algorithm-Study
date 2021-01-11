#include <iostream>
#include <vector>
#include <utility>
#include <algorithm> // copy, iter_swap



using namespace std;

#define SUDOKU_SIZE 9

vector<pair<int, int>> zeros;		// zero들의 row, col을 저장하기 위한 vector
int sudoku[SUDOKU_SIZE][SUDOKU_SIZE] = { 0, };		
int result_sudoku[SUDOKU_SIZE][SUDOKU_SIZE] = { 0, };  



void input() {
	for (int i = 0; i < SUDOKU_SIZE; i++) {
		for (int j = 0; j < SUDOKU_SIZE; j++) {
			cin >> sudoku[i][j];
			if (sudoku[i][j] == 0)
				zeros.push_back(make_pair(i, j));
		}
	}
}

void print_sudoku() {
	for (int i = 0; i < SUDOKU_SIZE; i++) {
		for (int j = 0; j < SUDOKU_SIZE; j++) {
			cout << result_sudoku[i][j];
			if (j != SUDOKU_SIZE - 1)
				cout << " ";
		}
		cout << "\n";
	}
}

bool is_possible(int row, int col, int value) {
	for (int i = 0; i < SUDOKU_SIZE; i++) {
		if (sudoku[row][i] == value)
			return false;
		if (sudoku[i][col] == value)
			return false;
	}
	for (int i = (row / 3) * 3; i < (row / 3) * 3 + 3; i++) {
		for (int j = (col / 3) * 3; j < (col / 3) * 3 + 3; j++) {
			if (sudoku[i][j] == value)
				return false;
		}
	}
	return true;
}

void fill_sudoku(long unsigned int level) {
	if (level == zeros.size()) {
		copy(&sudoku[0][0], &sudoku[0][0] + 81, &result_sudoku[0][0]);
		return;
	}

	int row, col;
	for (int i = 1; i <= 9; i++) {
		row = zeros[level].first, col = zeros[level].second;
		if (is_possible(row, col, i)) {
			sudoku[row][col] = i;
			fill_sudoku(level + 1);
			sudoku[row][col] = 0;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	input();
	fill_sudoku(0);
	print_sudoku();
	return 0;
}