#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define maxn 100010
typedef long long LL;
using namespace std;
struct Edge {
    int to, ne; LL w;
    Edge(int a = 0, int b = 0, LL c = 0) : to(a), ne(b), w(c) {}
}edge[maxn * 2];
struct node {
    int u, v;
    node(int a = 0, int b = 0) : u(a), v(b) {}
}e[maxn];
int le[maxn], sz[maxn], fa[maxn], dep[maxn], son[maxn], top[maxn], tot, cnt, n, q, s, ne[maxn], p[maxn];
LL val[maxn], c[maxn];
void addEdge(int u, int v, LL w) {
    edge[tot] = Edge(v, ne[u], w);
    ne[u] = tot++;
}
void dfs1(int u, int f, int d) {
    le[u] = ++cnt, sz[u] = 1, fa[u] = f, dep[u] = d;
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (v == f) continue;
        val[v] = edge[i].w;
        dfs1(v, u, d + 1);
        sz[v] += sz[u];
        if (son[u] == -1 || sz[son[u]] < sz[v]) son[u] = v;
    }
}
void dfs2(int u, int sp) {
    top[u] = sp;
    if (son[u] == -1) return;
    dfs2(son[u], sp);
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}
int lowbit(int x) { return x & (-x); }
void add(int x, LL w) { while (x <= n) c[x] += w, x += lowbit(x); }
LL query(int x) { LL ret = 0; while (x) ret += c[x], x -= lowbit(x); return ret; }
LL ask(int u, int v) {
    int fau = top[u], fav = top[v];
    LL ret = 0;
    while (fau != fav) {
        if (dep[fau] < dep[fav]) swap(u, v), swap(fau, fav);
        ret += query(le[u]) - query(le[fau]-1);
        u = fa[fau], fau = top[u];
    }
    if (u == v) return ret;
    if (dep[u] < dep[v]) swap(u, v);
    ret += query(le[u]) - query(le[v]);
    return ret;
}
void work() {
    memset(ne, -1, sizeof(ne)); memset(son, -1, sizeof(son)); memset(c, 0, sizeof(c));
    tot = cnt = 0;
    for (int i = 1; i < n; ++i) {
        int u, v; LL w;
        scanf("%d%d%lld", &u, &v, &w);
        addEdge(u, v, w); addEdge(v, u, w);
        e[i] = node(u, v);
    }
    dfs1(1, -1, 1);
    dfs2(1, 1);
    for (int i = 1; i < n; ++i) p[i] = dep[e[i].u] > dep[e[i].v] ? e[i].u : e[i].v;
    for (int i = 1; i <= n; ++i) add(le[i], val[i]);
//    for (int i = 1; i <= n; ++i) printf("%d ", le[i]); printf("\n");
    while (q--) {
        int x, u, i; LL w;
        scanf("%d", &x);
        if (x == 0) {
            scanf("%d", &u);
            printf("%lld\n", ask(s, u));
            s = u;
        }
        else {
            scanf("%d%lld", &i, &w);
            add(le[p[i]], w-val[p[i]]);
            val[p[i]] = w;
//            for (int i = 1; i <= n; ++i) printf("%lld ", c[i]); printf("\n");
        }
    }
}
int main() {
    while (scanf("%d%d%d", &n, &q, &s) != EOF) work();
    return 0;
}
