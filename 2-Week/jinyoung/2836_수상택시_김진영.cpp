#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    unsigned int n, m;
    vector<pair<unsigned int, unsigned int>> v;
    cin >> n >> m;
    for (unsigned int i = 0; i < n; i++) {
        unsigned int from, to;
        cin >> from >> to;
        if (from > to) {
            v.push_back(make_pair(to, from));
        }
    }
    sort(v.begin(), v.end());
    unsigned int start = 0, end = 0, ans = 0;
    for (auto item:v) {
        unsigned int a = item.first, b = item.second;
        if (a <= end) {
            end = max(end, b);
        } else {
            ans += end - start;
            start = a;
            end = b;
        }
    }
    ans += end - start;
    cout << ans*2 + m << '\n';
    return 0;
}