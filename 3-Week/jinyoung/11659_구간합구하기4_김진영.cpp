#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, arr[100001], sumArr[100001] = {0};
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sumArr[i] = sumArr[i-1] + arr[i];
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        cout << sumArr[b] - sumArr[a-1] << '\n';
    }
    return 0;
}
