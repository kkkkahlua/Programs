#include <bits/stdc++.h>
#define maxn 1000010
int ne[maxn], sz[maxn], w[maxn], n, k, tot, q[maxn], fa[maxn];
bool vis[maxn];
inline min(int a, int b) { return a < b ? a : b; }
typedef long long LL;
struct Edge {
    int to, dist, ne;
    Edge(int a = 0, int b = 0, int c = 0) : to(a), dist(b), ne(c) {}
}edge[maxn * 2];
void add(int x, int y, int d) {
    edge[tot] = Edge(y, d, ne[x]);
    ne[x] = tot++;
}
void dfs(int u, int fa) {
    sz[u] = 1;
    for (int i = ne[u]; i != -1; i = edge[i].ne) {
        Edge e = edge[i]; int v = e.to;
        if (v == fa) continue;
        w[v] = e.dist;
        dfs(v, u);
        sz[u] += sz[v];
    }
}
void bfs(int src) {
    memset(vis, 0, sizeof(vis));
    int f = 0, r = 0;
    q[r++] = src; vis[src] = true;
    while (r > f) {
        int u = q[f]; sz[u] = 1;
        ++f;
        for (int i = ne[u]; i != -1; i = edge[i].ne) {
            Edge e = edge[i]; int v = e.to;
            if (vis[v]) continue;
            q[r++] = v; vis[v] = true;
            fa[v] = u; w[v] = e.dist;
        }
    }
    for (int i = r - 1; i >= 0; --i) sz[fa[q[i]]] += sz[q[i]];
//    for (int i = 0; i < r; ++i) printf("%d %d %d\n", q[i], sz[q[i]], fa[q[i]]);

}
void work() {
    memset(ne, -1, sizeof(ne));
    tot = 0;
    for (int i = 1; i < n; ++i) {
        int x, y, d;
        scanf("%d%d%d", &x, &y, &d);
        add(x, y, d);
        add(y, x, d);
    }
//    dfs(1, -1);
    bfs(1);
    LL ans = 0;
    for (int i = 2; i <= n; ++i) {
        ans += (LL)w[i] * min(sz[i], k);
    }
    printf("%lld\n", ans);
}
int main() {
    freopen("多校第三场数据和标程/数据/1005.in", "r", stdin);
    freopen("05.out", "w", stdout);
//    freopen("in.txt", "r", stdin);
    while (scanf("%d%d", &n, &k) != EOF) work();
    return 0;
}
