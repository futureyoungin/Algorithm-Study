#include <iostream>
#include <string>



using namespace std;

int n, m;
string word[1000];
string result_word ="";
int result_distance=0;






int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> word[i];
	}

	for (int ch = 0; ch < m; ch++) {
		int ch_set[26] = { 0, };
		int max_ch=0, max_index;
		for (int row = 0; row < n; row++) {
			ch_set[word[row][ch] - 'A']++;
		}
		for (int alphabet = 0; alphabet < 26; alphabet++) {
			if (max_ch < ch_set[alphabet]) {
				max_ch = ch_set[alphabet];
				max_index = alphabet;
			}
		}
		result_distance += n - max_ch;
		result_word += max_index + 'A';
	}
	cout << result_word << "\n";
	cout << result_distance << "\n";

	
	return 0;
}