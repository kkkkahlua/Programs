#include <cstdio>
#include <cstring>
#define maxn 50010
struct Edge {
    int from, to, ne;
    Edge(int a = 0, int b = 0, int c = 0) : from(a), to(b), ne(c) {}
}edge[maxn * 2];
int next[maxn], sz[maxn], f[maxn], ans[maxn], tot = 0, n;
inline int maxi(int a, int b) { return a > b ? a : b; }
void add(int u, int v) {
    Edge e(u, v, next[u]);
    edge[tot] = e;
    next[u] = tot++;
}
void dfs(int u, int fa) {
    sz[u] = 1; f[u] = 0;
    for (int i = next[u]; i != -1; i = edge[i].ne) {
        Edge e = edge[i];
        int v = e.to;
        if (v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
        f[u] = maxi(f[u], sz[v]);
    }
    f[u] = maxi(f[u], n - sz[u]);
}
int main() {
    scanf("%d", &n);
    memset(next, -1, sizeof(next));
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y);
        add(y, x);
    }
    dfs(1, -1);
    int id = 1, tot = 0;
    ans[tot++] = id;
//    for (int i = 1; i <= n; ++i) printf("%d ", f[i]);
//    printf("\n");
    for (int i = 2; i <= n; ++i) {
        if (f[i] > f[id]) continue;
        if (f[i] < f[id]) {
            tot = 0; id = i;
        }
        ans[tot++] = i;
    }
    printf("%d", ans[0]);
    for (int i = 1; i < tot; ++i) printf(" %d", ans[i]);
    printf("\n");
    return 0;
}
