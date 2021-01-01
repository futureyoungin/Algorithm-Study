#include <iostream>
#include <cstring>


using namespace std;
int n;
unsigned long long b;
unsigned long long temp_b;
int **matrix, **pre_matrix, **result;


int  **make_matrix() {
	int **matrix = new int*[n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n];
		memset(matrix[i], 0, sizeof(int)*n);
	}
	return matrix;
}

void free_matrix(int** matrix) {
	for (int i = 0; i < n; i++) {
		delete [] matrix[i];
	}
}

void init_matrix(int **matrix) {
	for (int i = 0; i < n; i++) {
		memset(matrix[i], 0, sizeof(int)*n);
	}
}

void mat_mul(int **mat_a, int **mat_b, int **mat_ret) {
	init_matrix(mat_ret);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				mat_ret[i][j] += (mat_a[i][k] * mat_b[k][j])%1000;
			}
			mat_ret[i][j] = mat_ret[i][j] % 1000;
		}
	}
}

void copy_matrix(int **mat_dst, int **mat_src) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mat_dst[i][j] = mat_src[i][j];
		}
	}
}

void op() {
	
	if (b == 1) {
		mat_mul(pre_matrix, matrix, result);
		return;

	}
	else {
		unsigned long long current_square = 1;
		int shift_b = 0;
		temp_b = b;

		if ((b >> shift_b) & 0x01) {
			temp_b -= current_square;
			mat_mul(pre_matrix, matrix, result);
		}
		shift_b++;
		current_square *= 2;
		memcpy(pre_matrix, matrix, sizeof(int)*n*n);

		while (temp_b != 0) {
			int **temp_matrix = make_matrix();
			mat_mul(pre_matrix, pre_matrix, temp_matrix);  
			if( (b >> shift_b) & 0x01 ) {				
				copy_matrix(pre_matrix, result);
				mat_mul(temp_matrix, pre_matrix, result);
				temp_b -= current_square;			
			}
			copy_matrix(pre_matrix, temp_matrix);
			current_square *= 2;
			shift_b++;
			free_matrix(temp_matrix);
		}

	}
}

int main(void) {
	cin >> n >> b;
	matrix = make_matrix();
	result = make_matrix();
	pre_matrix = make_matrix();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
			
			if (i == j) {
				pre_matrix[i][j] = 1;
				result[i][j] = 1;
			}
		}
	}

	op();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}