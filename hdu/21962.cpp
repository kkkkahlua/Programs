#include <cstdio>
#include <cstring>
#define maxn 10010
struct Edge {
    int u, v, dist, ne;
    Edge(int xx = 0, int yy = 0, int dd = 0, int nn = 0): u(xx), v(yy), dist(dd), ne(nn) {}
}edge[maxn * 2];
int f[maxn][3], next[maxn], adj[maxn], tot, n;
bool vis[maxn];
inline max(int a, int b) { return a > b ? a : b; }
void add(int x, int y, int dist) {
    Edge e(x, y, dist, next[x]);
    edge[tot] = e;
    next[x] = tot++;
}
void dfs(int u) {
    vis[u] = true; f[u][0] = f[u][1] = 0;
    int num = next[u];
    while (num != -1) {
        Edge e = edge[num];
        int v = e.v;
        num = e.ne;
        if (vis[v]) continue;
        dfs(v);
        if (e.dist + f[v][0] > f[u][0]) {
            f[u][1] = f[u][0];
            f[u][0] = e.dist + f[v][0];
            adj[u] = v;
        }
        else if (e.dist + f[v][0] > f[u][1]) f[u][1] = e.dist + f[v][0];
    }
}
void dfs2(int u) {
    vis[u] = true;
    int num = next[u];
    while (num != -1) {
        Edge e = edge[num];
        int v = e.v;
        num = e.ne;
        if (vis[v]) continue;
        if (adj[u] == v) f[v][2] = f[u][1] > f[u][2] ? f[u][1] + e.dist : f[u][2] + e.dist;
        else f[v][2] = f[u][0] > f[u][2] ? f[u][0] + e.dist : f[u][2] + e.dist;
        dfs2(v);
    }
}
void work() {
    tot = 0;
    memset(next, -1, sizeof(next));
    for (int i = 2; i <= n; ++i) {
        int y, d;
        scanf("%d%d", &y, &d);
        add(i, y, d);
        add(y, i, d);
    }
    memset(vis, 0, sizeof(vis));
    dfs(1);

    memset(vis, 0, sizeof(vis));
    dfs2(1);
//    for (int i = 1; i <= n; ++i) {
//        printf("%d ", f[i][2]);
//    }
//    printf("\n");
    for (int i = 1; i <= n; ++i) printf("%d\n", max(f[i][0], f[i][2]));
}
int main() {
    freopen("2196.in", "r", stdin);
    while (scanf("%d", &n) != EOF) work();
    return 0;
}
