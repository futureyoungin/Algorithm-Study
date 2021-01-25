#include <iostream>
#include <cstring>
using namespace std;
bool visit[50][50];
int m, n;
int field[50][50], dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int sr, int sc)
{
    visit[sr][sc] = true;
    for (int d = 0; d < 4; d++) {
        int dr = sr + dir[d][0];
        int dc = sc + dir[d][1];
        if (dr < 0 || dr >= n || dc < 0 || dc >= m)
            continue;
        if (!visit[dr][dc] && field[dr][dc])
            dfs(dr, dc);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        memset(field, 0, sizeof(field));
        memset(visit, 0, sizeof(visit));
        int k, ans = 0;
        cin >> m >> n >> k;
        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            field[y][x] = 1;
        }
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (!visit[r][c] && field[r][c]) {
                    dfs(r, c);
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}