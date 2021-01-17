#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int dp[1001][1001];
string a, b;
void print(int i, int j)
{
    if (i <= 0 || j <= 0) return; 
    if (a[i-1] == b[j-1]) {
        print(i-1, j-1);
        cout << a[i-1];
    } else {
        if (dp[i][j-1] > dp[i-1][j]) {
            print(i, j-1);
        } else {
            print(i-1, j);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b;
    int lenA = a.length(), lenB = b.length();
    for (int i = 0; i < lenA; i++) {
        for (int j = 0; j < lenB; j++) {
            if (a[i] == b[j]) {
                dp[i+1][j+1] = dp[i][j] + 1;
            } else {
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    cout << dp[lenA][lenB] << '\n';
    print(lenA, lenB);
    return 0;
}