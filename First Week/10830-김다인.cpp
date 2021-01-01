#include <iostream>
#define MOD 1000

using namespace std;

long long origin[5][5], answer[5][5];

void multiple_matrix(long long matrixA[5][5], long long matrixB[5][5], int N){
	long long matrixC[5][5];

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			matrixC[i][j] = 0;
			for(int k=0;k<N;k++)
				matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
			matrixC[i][j] %= DIVIDE;
		}
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			matrixA[i][j] = matrixC[i][j];
		}
	}
}

void print_matrix(long long matrix[5][5], int N){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
}

int main(){
	long long N, B;
	cin >> N >> B;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			cin >> origin[i][j];
		answer[i][i] = 1;
	}

	while(B>0){
		if(B%2==1){
			multiple_matrix(answer, origin, N);
		}
		multiple_matrix(origin, origin, N);
		B/=2;
	}

	print_matrix(answer, N);
}