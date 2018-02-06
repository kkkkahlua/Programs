#include <cstdio>
#include <cmath>
#include <cstring>
#define mod 1000000007
#define maxn 510
const double pi = 3.1415926;
const double eps = 1e-6;
using namespace std;
typedef long long LL;
char s1[maxn], s2[maxn];
int kas, n, m;
struct point { int x, y; }a[maxn];
bool exist[maxn][maxn];
int tot[maxn];
int abs(int a, int b) { return a > b ? a - b : b - a; }
bool ok(double x, int& y) {
    if (fabs(x - floor(x)) < eps) { y = floor(x); return true; }
    if (fabs(ceil(x) - x) < eps) { y = ceil(x); return true; }
    return false;
}
void work() {
    int ans = 0;
    memset(exist, 0, sizeof(exist));
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i].x, &a[i].y);
        a[i].x += 100; a[i].y += 100;
        exist[a[i].x][a[i].y] = true;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            point p1 = a[i], p2 = a[j];
            point ori = p1, ne = p2;
            int dx = ne.x - ori.x, dy = ne.y - ori.y;
            double midx = (double)(ori.x + ne.x) / 2, midy = (double)(ori.y + ne.y) / 2;
            double hfdx = (double)(-dy) / 2, hfdy = (double)(dx) / 2;
            int x1, y1, x2, y2;
            double xa = midx + hfdx, ya = midy + hfdy,
                xb = midx - hfdx, yb = midy - hfdy;
            bool flag1 = ok(xa, x1), flag2 = ok(xb, x2),
                flag3 = ok(ya, y1), flag4 = ok(yb, y2);
            if (!flag1 || !flag2 || !flag3 || !flag4) continue;
//          printf("%d %d %d %d\n", x1, y1, x2, y2);
            if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0) continue;
            if (exist[x1][y1] && exist[x2][y2]) ++ans;
        }
    }
    printf("%d\n", ans / 4);
}
int main() {
    freopen("in.txt", "r", stdin);
    while (scanf("%d", &n) != EOF) work();
    return 0;
}
