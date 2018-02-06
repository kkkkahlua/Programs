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
};
queue<node> q;
const int dx[4][2] =  {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int num[maxn][maxn][4], a[maxn][maxn], m, n;
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
    int k, x1, y1, x2, y2;
    scanf("%d%d%d%d%d", &k, &y1, &x1, &y2, &x2);
    memset(num, -1, sizeof(num));
    for (int i = 0; i < 4; ++i) {
        num[x1][y1][i] = 0;
        int tx = x1 + dx[i][0], ty = y1 + dx[i][1];
        if (tx > 0 && tx <= m && ty > 0 && ty <= n && !a[tx][ty]) {
            node temp;
            temp.x = tx; temp.y = ty; temp.num = 0; temp.dir = i;
            num[tx][ty][i] = 0;
            q.push(temp);
        }
    }

    while (!q.empty()) {
        node nowf = q.front();
        int x = nowf.x, y = nowf.y, nnum = nowf.num, d = nowf.dir;
//        printf("%d %d\n", x, y);
        if (nnum <= num[x][y][d]) {
            for (int i = 0; i < 4; ++i) {
                int tx = x + dx[i][0], ty = y + dx[i][1];
                if (tx > 0 && tx <= m && ty > 0 && ty <= n && !a[tx][ty]) {
                    int tot;
                    if (d == i) tot = nnum;
                    else tot = nnum + 1;
//                    int tot = min(abs(i - d), abs(4 - (i - d))) + nnum;
                    if (num[tx][ty][i] == -1 || tot < num[tx][ty][i]) {
                        num[tx][ty][i] = tot;
                        node temp;
                        temp.x = tx; temp.y = ty; temp.num = tot; temp.dir = i;
                        q.push(temp);
                    }
                }
            }
        }
        q.pop();
    }
    int ans = inf;

    for (int i = 0; i < 4; ++i) if (num[x2][y2][i] != -1) ans = min(ans, num[x2][y2][i]);
    if (ans <= k) printf("yes\n");
    else printf("no\n");
//    printf("%d\n", ans);
}
int main() {
//    freopen("1728.in", "r", stdin);
    int t;
    scanf("%d", &t);
    while (scanf("%d%d\n", &m, &n) != EOF) work();
    return 0;
}
