#include <cstdio>
#include <cstring>
#define eps 1e-4
#define maxm 5010
#define maxn 1010
#define inf 0x3f3f3f3f
using namespace std;
int n, p, tot;
double dist[maxn];
int a[maxn];
struct Edge {
    int from, to, cost, val; double d;
    Edge(int a = 0, int b = 0, int c = 0, int v = 0, double _d = 0.0) :
        from(a), to(b), cost(c), val(v), d(_d) {}
}edge[maxm];
void add(int from, int to, int cost, int val) {
    edge[tot++] = Edge(from, to, cost, val);
}
inline double max(double a, double b) { return a > b ? a : b; }
bool check(double x) {
    for (int i = 0; i < tot; ++i) edge[i].d = -(edge[i].val - x * edge[i].cost);
//    for (int i = 0; i < tot; ++i) printf("%d %d %d %d %.3f\n", edge[i].from, edge[i].to, edge[i].cost, edge[i].val, edge[i].d);

    int src = 1;
    for (int i = 1; i <= n; ++i) dist[i] = inf; dist[src] = 0;
    for (int i = 0; i < n; ++i) {
        bool flag = false;
        for (int j = 0; j < tot; ++j) {
            Edge e = edge[j];
            if (dist[e.to] > dist[e.from] + e.d) {
                dist[e.to] = dist[e.from] + e.d;
                flag = true;
            }
        }
//        for (int j = 1; j <= n; ++j) printf("%.3f ", dist[j]); printf("\n");
        if (!flag) return false;
    }
    return true;
}
void work() {
    tot = 0;
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    double r = 0;
    for (int i = 0; i < p; ++i) {
        int x, y, t;
        scanf("%d%d%d", &x, &y, &t);
        add(x, y, t, a[x]);
        r = max(r, (double)a[x] / t);
    }
    double l = 0.0, mid;
    while (r - l > eps) {
        mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    printf("%.2f\n", mid);
}
int main() {
    freopen("in.txt", "r", stdin);
    while (scanf("%d%d", &n, &p) != EOF) work();
    return 0;
}
