#include <iostream>
#include <queue>
#include <string>

using namespace std;

int map[1000][1000];
bool visited[1000][1000][2] = { false };
int dx[] = { -1,0,1,0 };
int dy[] = {0, 1, 0, -1};

class Point{
public:
    int x;
    int y;
    int cnt;
    int brk;
    Point(int x, int y, int brk, int cnt) {
        this->x = x;
        this->y = y;
        this->cnt = cnt;
        this->brk = brk;
    }
};
int bfs(int n, int m) {
    queue<Point> q;
    q.push(Point(0,0,0,1));
    visited[0][0][0] = true;
    visited[0][0][1] = true;
    while (!q.empty()) {
        Point cur = q.front();
        q.pop();
        if (cur.x == n-1 && cur.y == m-1) {
            return cur.cnt;
        }
        for (int i = 0; i < sizeof(dx) / sizeof(int); i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (!visited[nx][ny][0]) {
                    if (map[nx][ny] == 0 && cur.brk == 0) {
                        q.push(Point(nx, ny, 0, cur.cnt + 1));
                        visited[nx][ny][0] = true;
                    }
                }
                if (!visited[nx][ny][1]) {
                    if ((map[nx][ny] == 1 && cur.brk == 0) || (map[nx][ny] == 0 && cur.brk == 1)) {
                        q.push(Point(nx, ny, 1, cur.cnt + 1));
                        visited[nx][ny][1] = true;
                    }
                }
            }
        }
    }
    return -1;
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < m; j++)
            map[i][j] = tmp[j] - '0';
    }
 
    cout << bfs(n,m);
    return 0;
}