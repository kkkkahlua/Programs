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
//    printf("%d\n", ceil(x));
//    printf("%d\n", floor(x));
    if (fabs(x - floor(x)) < eps) { y = floor(x); return true; }
    if (fabs(ceil(x) - x) < eps) { y = ceil(x); return true; }
    return false;
}
void work() {
    memset(tot, 0, sizeof(tot));
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
            int k = 4;
//            for (int k = 3; k <= n; ++k) {
                double sita = pi * (k - 2) / k,
                    coss = cos(sita), sinn = sin(sita);
//                printf("%lf %lf %lf\n", sita, coss, sinn);
                point ori = p1, ne = p2;
                while (true) {
                    if (ne.x == p1.x && ne.y == p1.y) { ++tot[k]; break; }//printf("%d %d\n", i, j); break; }
                    int dx = ne.x - ori.x, dy = ne.y - ori.y;
                    double dxx = coss * dx - sinn * dy;
                    double dyy = sinn * dx + coss * dy;
//                    printf("%d %d %d %d %lf %lf\n", ori.x, ori.y, ne.x, ne.y, dxx, dyy);
                    ori = ne;

                    int deltax, deltay;
                    bool flag1 = ok(dxx, deltax), flag2 = ok(dyy, deltay);
//                    printf("%d %d")
                    if (!flag1 || !flag2) {break;}

                    ne.x += deltax; ne.y += deltay;
//                    printf("%d %d\n", ne.x, ne.y);

                    if (!exist[ne.x][ne.y]) {break; }
                }

        }
    }
    int ans = 0;
    for (int i = 3; i <= n; ++i) { ans += tot[i] / i; }
    printf("%d\n", ans);
}
int main() {
    freopen("多校联合第二场数据和标程/数据/1011.in", "r", stdin);
    freopen("11.out", "w", stdout);
    while (scanf("%d", &n) != EOF) work();
    return 0;
}
