/*
정답이 아닌 소스임. 추후 수정하겠음
*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
char mapArr[1001][1002];
int n, m, dist[1001][1001], dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

class Pos {
public:
    bool useBreak;
    int r, c, dis;
    Pos(int r, int c, int dis, bool useBreak)
    : r(r), c(c), dis(dis), useBreak(useBreak) {}
};

int bfs()
{
    queue<Pos> q;
    memset(dist, -1, sizeof(dist));
    dist[0][0] = 0;
    q.push(Pos(0, 0, 1, false));
    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();
        bool useBreak = cur.useBreak;
        int r = cur.r, c = cur.c, dis = cur.dis;
        if (r == n-1 && c == m-1) {
            return dis;
        }
        for (int d = 0; d < 4; d++) {
            int dr = r + dir[d][0], dc = c + dir[d][1];
            if (dr < 0 || dr >= n || dc < 0 || dc >= m) continue;
            if (dist[dr][dc] == -1 || dist[dr][dc] >= dis + 1) {
                dist[dr][dc] = dis + 1;
                if (mapArr[dr][dc] == '0') {
                    if (dist[dr][dc] == dis + 1 && useBreak) {
                        continue;
                    }
                    q.push(Pos(dr, dc, dis+1, useBreak));
                } else if (mapArr[dr][dc] == '1' && !useBreak) {
                    q.push(Pos(dr, dc, dis+1, true));
                }
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int r = 0; r < n; r++) {
        cin >> mapArr[r];
    }
    int answer = bfs();
    cout << answer << '\n';
    return 0;
}