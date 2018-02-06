#include <cstdio>
#include <cstring>
#include <cmath>
#define eps 1e-5
#define inf 0x3f3f3f3f
#define maxn 1010
using namespace std;
int cost[maxn][maxn], x[maxn], y[maxn], h[maxn], n;
double len[maxn][maxn], dist[maxn], val[maxn][maxn];
bool vis[maxn];
inline int abs(int a) { return a > 0 ? a : -a; }
bool check(double x) {
//    printf("%.3f\n", x);
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; ++i) dist[i] = inf;
    int src = 0; vis[src] = true;
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) val[i][j] = cost[i][j] - x * len[i][j];
    }

    for (int num = 0; num < n - 1; ++num) {
        double minn = inf; int p = -1;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            double vall = val[src][i];
            dist[i] = vall < dist[i] ? vall : dist[i];
            if (dist[i] < minn) { minn = dist[i]; p = i; }
        }
        sum += minn; vis[src = p] = true;
//        printf("%d ", src);
    }
//    printf("\n\n");
    if (sum <= 0) return true;
    return false;
}
inline double max(double a, double b) { return a > b ? a : b; }
void work() {
    for (int i = 0; i < n; ++i) scanf("%d%d%d", &x[i], &y[i], &h[i]);
    double r = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            cost[i][j] = cost[j][i] = abs(h[i] - h[j]);
            len[i][j] = len[j][i] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
            r = max(r, cost[i][j] / len[i][j]);
        }
    }

    double l = 0.0, mid;
//    printf("%f\n", r);
    while (r - l > eps) {
        mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    printf("%.3f\n", mid);
}
int main() {
    freopen("in.txt", "r", stdin);
    freopen("2728.out", "w", stdout);
    while (scanf("%d", &n) != EOF && n) work();
    return 0;
}
