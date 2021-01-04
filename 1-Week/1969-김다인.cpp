#include <iostream>

using namespace std;

char get_char(int letter){
	switch(letter){
		case 0:	return 'A';
		case 1:	return 'C';
		case 2:	return 'G';
		case 3:	return 'T';
	}
}

int main(){
	int N, M, total = 0;
	char dna[1001][51];
	int dna_count[4][51];
	string answer = "";

	cin >> N >> M;

	for(int i=0;i<N;i++){
		cin >> dna[i];
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			switch(dna[i][j]){
				case 'A':
				dna_count[0][j]++; break;
				case 'C':
				dna_count[1][j]++; break;
				case 'G':
				dna_count[2][j]++; break;
				case 'T':
				dna_count[3][j]++; break;
			}
		}
	}

	for(int i=0;i<M;i++){
		int max = 0, letter;
		for(int j=0;j<4;j++){
			if(dna_count[j][i] > max){
				max = dna_count[j][i];
				letter = j;
			}
		}
		total += (N-max);
		answer += get_char(letter);
	}

	cout << answer << "\n" << total << "\n";
}