#include <cstdio>
#include <iostream>
#include <cstring>
#define maxn 1000010
using namespace std;
typedef long long LL;
struct Edge {
    int from, to, dist, ne;
    Edge(int a = 0, int b = 0, int c = 0, int d = 0) : from(a), to(b), dist(c), ne(d) {}
}edge[maxn * 2];
int next[maxn], tot, adj[maxn], cnt, lo[maxn], hi[maxn];
LL f[maxn][3], g[maxn];
inline LL max(LL a, LL b) { return a > b ? a : b; }
void add(int u, int v, int d) {
    Edge e(u, v, d, next[u]);
    edge[tot] = e;
    next[u] = tot++;
}
void dfs(int u, int fa) {
    f[u][0] = f[u][1] = 0;
    for (int i = next[u]; i != -1; i = edge[i].ne) {
        Edge e = edge[i]; int v = e.to;
        if (v == fa) continue;
        dfs(v, u);
        if (f[v][0] + (LL)e.dist > f[u][0]) {
            f[u][1] = f[u][0]; f[u][0] = f[v][0] + (LL)e.dist;
            adj[u] = v;
        }
        else if (f[v][0] + (LL)e.dist > f[u][1]) f[u][1] = f[v][0] + (LL)e.dist;
    }
}
void dfs2(int u, int fa) {
    for (int i = next[u]; i != -1; i = edge[i].ne) {
        Edge e = edge[i]; int v = e.to;
        if (v == fa) continue;
        if (adj[u] == v) f[v][2] = f[u][2] > f[u][1] ? f[u][2] : f[u][1];
        else f[v][2] = f[u][2] > f[u][0] ? f[u][2] : f[u][0];
        f[v][2] += (LL)e.dist;
        dfs2(v, u);
    }
}
int main() {
    memset(next, -1, sizeof(next));
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 2; i <= n; ++i) {
        int y, d;
        scanf("%d%d", &y, &d);
        add(i, y, d);
        add(y, i, d);
    }
    dfs(1, -1);
    dfs2(1, -1);
//    for (int i = 1; i <= n; ++i) printf("%d ", f[i][0]); printf("\n");
//    for (int i = 1; i <= n; ++i) printf("%d ", f[i][2]); printf("\n");

    for (int i = 1; i <= n; ++i) g[i] = max(f[i][0], f[i][2]);

    int f1 = 0, r1 = 0, f2 = 0, r2 = 0, l = 1, ans = 1;
    for (int i = 1; i <= n; ++i) {
        while (r1 > f1 && g[i] < g[lo[r1 - 1]]) --r1;
        lo[r1++] = i;
        while (r2 > f2 && g[i] > g[hi[r2 - 1]]) --r2;
        hi[r2++] = i;
        while (g[hi[f2]] - g[lo[f1]] > m) {
            l = min(hi[f2], lo[f1]) + 1;
            while (hi[f2] < l) ++f2;
            while (lo[f1] < l) ++f1;
        }
        if (g[hi[f2]] - g[lo[f1]] <= m) ans = max(ans, i - l + 1);
    }
    printf("%d\n", ans);
//    for (int i = 1; i <= n; ++i) printf("%d ", g[i]); printf("\n");
    return 0;
}
