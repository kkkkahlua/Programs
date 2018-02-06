#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
#define inf 0x3f3f3f3f
#define maxn 110
using namespace std;
struct node {
    int x, y, num, dir;
    node(int xx = 0, int yy = 0, int nn = 0, int dd = 0) : x(xx), y(yy), num(nn), dir(dd) {}
    bool operator < (const node& b) const { return num > b.num; }
};
priority_queue<node> q;
const int dx[4][2] =  {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int a[maxn][maxn], m, n;
bool vis[maxn][maxn][4];
char s[maxn][maxn];
inline min(int a, int b) { return a < b ? a : b; }
void work() {
    for (int i = 1; i <= m; ++i) {
        scanf("%s", s[i]);
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s[i][j - 1] == '.') a[i][j] = 0;
            else a[i][j] = 1;
        }
    }
    memset(vis, 0, sizeof(vis));
    int k, x1, y1, x2, y2;
    scanf("%d%d%d%d%d", &k, &y1, &x1, &y2, &x2);
    while (!q.empty()) q.pop();
    for (int i = 0; i < 4; ++i) q.push(node(x1, y1, 0, i));
    while (!q.empty()) {
        node nowf = q.top(); q.pop();
        int x = nowf.x, y = nowf.y, num = nowf.num, d = nowf.dir;
//        printf("%d %d %d\n", x, y, num);
        if (num > k) { printf("no\n"); return; }
        if (x == x2 && y == y2) { printf("yes\n"); return; }
        if (vis[x][y][d]) continue;
        vis[x][y][d] = true;
        for (int i = 0; i < 4; ++i) {
            int tx = x + dx[i][0], ty = y + dx[i][1];
            if (tx > 0 && tx <= m && ty > 0 && ty <= n && !a[tx][ty] && !vis[tx][ty][d]) {
                int tot = num;
                if (d != i) ++tot;
                q.push(node(tx, ty, tot, i));
            }
        }
    }
    printf("no\n");
}
int main() {
//    freopen("1728.in", "r", stdin);
    int t;
    scanf("%d", &t);
    while (scanf("%d%d\n", &m, &n) != EOF) work();
    return 0;
}
