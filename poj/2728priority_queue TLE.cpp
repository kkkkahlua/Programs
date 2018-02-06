#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#define eps 1e-5
#define inf 0x3f3f3f3f
#define maxn 1010
using namespace std;
int cost[maxn][maxn], x[maxn], y[maxn], h[maxn], n;
double len[maxn][maxn], dist[maxn];
bool vis[maxn];
inline int abs(int a) { return a > 0 ? a : -a; }
struct node {
    int v; double c;
    node(int _v = 0, double _c = 0) : v(_v), c(_c) {}
    bool operator < (const node& nd) const { return c > nd.c; }
};
priority_queue<node> q;
bool check(double x) {
//    printf("%.3f\n", x);
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; ++i) dist[i] = inf;
    int src = 0; vis[src] = true;
    while (!q.empty()) q.pop();
    q.push(node(src, 0));
    double sum = 0;
    while (true) {
        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            double val = cost[src][i] - x * len[src][i];
            if (val < dist[i]) {
                dist[i] = val;
                q.push(node(i, dist[i]));
            }
        }
        while (!q.empty() && vis[q.top().v]) q.pop();
        if (q.empty()) break;
        vis[src = q.top().v] = true;
        sum += q.top().c;
    }
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
