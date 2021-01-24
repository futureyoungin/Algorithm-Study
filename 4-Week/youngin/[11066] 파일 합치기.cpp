#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX_BOOK 501

int T, n;
int books[MAX_BOOK] = { 0, };
int sum[MAX_BOOK] = {0, };
int dp[MAX_BOOK][MAX_BOOK] = {0, };

void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> books[i];
        sum[i] = sum[i-1] + books[i];
	}	
}

int dp_find(int start, int finish) {
    if(dp[start][finish] != 0)       //memoization
        return dp[start][finish];
      
    
	if (start == finish) {
		return 0;
	}
	if (start+1 == finish){
        dp[start][finish] = books[start]+books[finish];
		return dp[start][finish];
    }
	
	if(dp[start][finish] == 0)
        dp[start][finish] = 1000000000;
	for (int i = start; i < finish; i++) {
		dp[start][finish] = min(dp[start][finish], dp_find(start, i) + dp_find(i + 1, finish));
	}
    dp[start][finish] += sum[finish]-sum[start-1];
    return dp[start][finish];
}

int main(int argc, char* argv[]) {
	cin >> T;
	for (int i = 0; i < T; i++) {
		input();
		cout << dp_find(1, n) << "\n";
		memset(books, 0, sizeof(int)*(n+1));
        memset(sum, 0, sizeof(int)*(n+1));
        memset(dp, 0, sizeof(int)*MAX_BOOK*MAX_BOOK);
	}

	return 0;
}