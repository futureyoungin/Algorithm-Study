#include <iostream>
#include <vector>
using namespace std;
int p[20][20], n;
int go(int index, vector<int> &first, vector<int> &second)
{
    if (index == n) {
        if (first.size() != n/2 || second.size() != n/2) return -1;
        int t1 = 0, t2 = 0;
        for (int i = 0; i < n/2; i++) {
            for (int j = 0; j < n/2; j++) {
                if (i == j) continue;
                t1 += p[first[i]][first[j]];
                t2 += p[second[i]][second[j]];
            }
        }
        int diff = t1 - t2;
        if (diff < 0) diff = -diff;
        return diff;
    }
    if (first.size() > n/2 || second.size() > n/2) {
        return -1;
    }
    int ans = -1;
    first.push_back(index);
    int r1 = go(index+1, first, second);
    if (ans == -1 || r1 != -1 && ans > r1) {
        ans = r1;
    }
    first.pop_back();
    second.push_back(index);
    int r2 = go(index+1, first, second);
    if (ans == -1 || r2 != -1 && ans > r2) {
        ans = r2;
    }
    second.pop_back();
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> p[i][j];
    vector<int> first, second;
    cout << go(0, first, second) << '\n';
    return 0;
}

