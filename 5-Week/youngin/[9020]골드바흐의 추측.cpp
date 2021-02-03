#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 10000
int T, N;
int filter[MAX_N + 1] = { 0, };
int set_Eratos[MAX_N] = { 0, };
int set_cnt = 0;

int min_integer() {
	for (int i = 2; i <= MAX_N; i++) {
		if (filter[i] == i) {
			set_Eratos[set_cnt++] = i;
			return i;
		}
	}
	return -1;
}

void fill_filter() {
	for (int i = 2; i <= MAX_N; i++)
		filter[i] = i;

	int Eratos = 0;
	int Eratos_cnt;
	int filter_N;
	
	while (Eratos != -1) {
		Eratos = min_integer();
		if (Eratos == -1)
			break;
		Eratos_cnt = 1;
		for (; Eratos*Eratos_cnt <= MAX_N;) {
			filter_N = Eratos * Eratos_cnt;
			if (filter[filter_N] == filter_N) {
				filter[filter_N] = MAX_N + 1;
			}
			Eratos_cnt++;
		}
	}
}

void Gold() {
    int left, right;
    int temp_sum=0;
	int upper_idx = (upper_bound(set_Eratos, set_Eratos+set_cnt, N/2) - set_Eratos);
    if(N/2 == set_Eratos[upper_idx-1])
        cout << N/2 << " " << N/2 << "\n";
    else{
        right = upper_idx, left = upper_idx-1;
        while(temp_sum != N){
            temp_sum = set_Eratos[left] + set_Eratos[right];
            if(temp_sum > N)
                left--;
            else if(temp_sum == N)
                cout << set_Eratos[left] << " " << set_Eratos[right] << "\n";
            else
                right++;
        }
    }
	
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	fill_filter();
	int temp_N;
	for (int i = 0; i < T; i++) {
		cin >> N;
		Gold();
		
	}
	return 0;
}