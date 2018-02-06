#include <cstdio>
#include <cstring>
#define maxn 10010
struct Edge {
    int u, v, dist, ne;
    Edge(int xx = 0, int yy = 0, int dd = 0, int nn = 0): u(xx), v(yy), dist(dd), ne(nn) {}
}edge[maxn * 2];
int depth[maxn], depth2[maxn], next[maxn], tot, n;
bool vis[maxn];
inline max(int a, int b) { return a > b ? a : b; }
void add(int x, int y, int dist) {
    Edge e(x, y, dist, next[x]);
    edge[tot] = e;
    next[x] = tot++;
}
void dfs(int x, int dep, int* depth) {
    vis[x] = true;
    depth[x] = dep;
    int num = next[x];
    while (num != -1) {
        Edge e = edge[num];
        if (!vis[e.v]) dfs(e.v, dep + e.dist, depth);
        num = e.ne;
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
    dfs(1, 0, depth);
    int mmax = 1;
    for (int i = 2; i <= n; ++i) {
        mmax = depth[mmax] > depth[i] ? mmax : i;
    }
    int l = mmax;
    memset(vis, 0, sizeof(vis));
    memset(depth, 0, sizeof(depth));
    dfs(l, 0, depth);
    mmax = 1;
    for (int i = 2; i <= n; ++i) {
        mmax = depth[mmax] > depth[i] ? mmax : i;
    }
    int r = mmax;
//    printf("%d %d\n", l, r);
    memset(vis, 0, sizeof(vis));
    memset(depth2, 0, sizeof(depth));
    dfs(r, 0, depth2);
//    for (int i = 1; i <= n; ++i) {
//        printf("%d ", depth[i]);
//    }
//    for (int i = 1; i <= n; ++i) {
//        printf("%d ", depth2[i]);
//    }
    for (int i = 1; i <= n; ++i) {
        printf("%d\n", max(depth[i], depth2[i]));
    }
}
int main() {
//    freopen("2196.in", "r", stdin);
    while (scanf("%d", &n) != EOF) work();
    return 0;
}
