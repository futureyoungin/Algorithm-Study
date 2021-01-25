#include <iostream>
#include <algorithm>
using namespace std;
int arr[100000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int sum = arr[0], low = 0, high = 0, length = n+1;
    while (low <= high && high < n) {
        if (sum < s) {
            sum += arr[++high];
        } else {
            length = min(length, high-low+1);
            sum -= arr[low++];
        }
    }
    if (length == n+1) cout << 0 << '\n';
    else cout << length << '\n';
    return 0;
}