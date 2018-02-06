#include <stdio.h>
#include <string.h>
#include <algorithm>
#define maxn 10010
using namespace std;
typedef long long LL;
struct Edge {
    int to, ne;
}edge[maxn];
int fa[maxn], son[maxn], dep[maxn], sz[maxn], ne[maxn], top[maxn], tot, in[maxn];
void add(int u, int v) {
    edge[tot] = {v, ne[u]};
    ne[u] = tot++;
}
void dfs1(int u, int f, int depth) {
//    printf("%d\n", u);
    dep[u] = depth, fa[u] = f, son[u] = -1, sz[u] = 1;
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        dfs1(v, u, depth+1);
        sz[u] += sz[v];
        if (son[u] == -1 || sz[son[u]] < sz[v]) son[u] = v;
    }
}
void dfs2(int u, int sp) {
    top[u] = sp;
    if (son[u] == -1) return;
    dfs2(son[u], sp);
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (v == son[u]) continue;
        dfs2(v, v);
    }
}
int lca(int u, int v) {
    int fau = top[u], fav = top[v];
    while (fau != fav) {
        if (dep[fau] < dep[fav]) swap(fau, fav), swap(u, v);
        u = fa[fau], fau = top[u];
    }
    return dep[u] < dep[v] ? u : v;
}
void work() {
    tot = 0; memset(ne, -1, sizeof ne); memset(in, 0, sizeof in);
    int n, u, v;
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &u, &v);
        add(u, v);
        ++in[v];
    }
    int i = 1;
    for (;i <= n; ++i) if (!in[i]) break;
    dfs1(i, -1, 0);
    dfs2(i, i);
    scanf("%d%d", &u,&v);
    printf("%d\n", lca(u, v));
}
int main() {
//    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
