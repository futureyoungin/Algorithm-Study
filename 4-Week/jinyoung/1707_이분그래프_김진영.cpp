#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool dfs(vector<vector<int>> &g, vector<int> &visit, int start, int color)
{
    if (visit[start]) return true;
    visit[start] = color;
    for (int v:g[start]) {
        if (visit[v]) {
            if (visit[start] == visit[v])
                return false;
        } else {
            if (!dfs(g, visit, v, color == 1 ? 2:1))
                return false;
        }
    }
    return true;
}

void isBipartiteGraph(vector<vector<int>> &g, int n)
{
    vector<int> visit(n+1, 0);
    for (int v = 1; v <= n; v++) {
        if (!dfs(g, visit, v, 1)) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int v, e;
        cin >> v >> e;
        vector<vector<int>> g(v+1, vector<int>());
        while (e--) {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        isBipartiteGraph(g, v);
    }
    return 0;
}