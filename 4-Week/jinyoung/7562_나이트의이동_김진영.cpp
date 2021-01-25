#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef struct _point {
    int r, c, dis;
} Point;
bool check[300][300];
int n, ans;
int dir[8][2] = {{-1, -2}, {1, -2}, {-1, 2}, {1, 2}, {-2, -1}, {2, -1}, {-2, 1}, {2, 1}};
void bfs(Point start, Point end)
{
    if (start.r == end.r && start.c == end.c) {
        ans = 0;
        return;
    }
    memset(check, false, sizeof(check));
    queue<Point> q;
    check[start.r][start.c] = true;
    start.dis = 0;
    q.push(start);
    while (!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int dis = q.front().dis;
        q.pop();
        for (int d = 0; d < 8; d++) {
            int dr = r + dir[d][0];
            int dc = c + dir[d][1];
            if (dr == end.r && dc == end.c) {
                ans = dis+1;
                return;
            }
            if (dr < 0 || dr >= n || dc < 0 || dc >= n) continue;
            if (!check[dr][dc]) {
                Point temp;
                temp.r = dr; temp.c = dc;
                temp.dis = dis+1;
                check[dr][dc] = true;
                q.push(temp);
            }
        }

    }
    
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        Point start, end;
        cin >> start.r >> start.c;
        cin >> end.r >> end.c;
        bfs(start, end);
        cout << ans << '\n';
    }
    return 0;
}