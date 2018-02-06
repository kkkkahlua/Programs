#include <bits/stdc++.h>
#define maxn 50010
#pragma comment(linker, "/STACK:1024000000,1024000000");
using namespace std;
typedef long long LL;
int sz[maxn], dep[maxn], le[maxn], top[maxn], son[maxn], ne[maxn], tot, cnt, n, m, p, f[maxn];
LL a[maxn], c[maxn];
struct Edge {
    int from, to, ne;
    Edge(int c = 0, int a = 0, int b = 0) : from(c), to(a), ne(b) {}
}edge[maxn * 2];
void addEdge(int u, int v) {
    edge[tot] = Edge(u, v, ne[u]);
    ne[u] = tot++;
}
void dfs1(int u, int fa, int depth) {
    sz[u] = 1; dep[u] = depth; f[u] = fa;
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (v == fa) continue;
        dfs1(v, u, depth + 1);
        sz[u] += sz[v];
        if (son[u] == -1 || sz[son[u]] < sz[v]) son[u] = v;
    }
}
void dfs2(int u, int fa, int sp) {
    top[u] = sp;
    le[u] = ++cnt;
    if (son[u] == -1) return;
    dfs2(son[u], u, sp);
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (v == fa || v == son[u]) continue;
        dfs2(v, u, v);
    }
}
inline int lowbit(int x) { return x & (-x); }
inline void add(int x, LL w) { while (x <= n) c[x] += w, x += lowbit(x); }
inline LL query(int x) { LL ret = 0; while (x) ret += c[x], x -= lowbit(x); return ret; }
void update(int u, int v, LL x) {
    int fau = top[u], fav = top[v];
    while (fau != fav) {
        if (dep[fau] < dep[fav]) { swap(u, v); swap(fau, fav); }
        add(le[fau], x); add(le[u]+1, -x);
        u = f[fau], fau = top[u];
    }
    if (dep[u] < dep[v]) swap(u, v);
    add(le[v], x); add(le[u]+1, -x);
}
void work() {
    memset(c, 0, sizeof(c)); memset(ne, -1, sizeof(ne));
    memset(son, -1, sizeof(son));
    tot = cnt = 0;
    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(u, v); addEdge(v, u);
    }
    dfs1(1, -1, 0);
    dfs2(1, -1, 1);
//    for (int i = 1; i <= n; ++i) printf("%d ", le[i]); printf("\n");
    while (p--) {
        char c; int u, v; LL x;
        scanf("\n%c", &c);
        if (c == 'I') {
            scanf("%d%d%lld", &u, &v, &x);
            update(u, v, x);
        }
        else if (c == 'D') {
            scanf("%d%d%lld", &u, &v, &x);
            update(u, v, -x);
        }
        else {
            scanf("%d", &u);
            printf("%lld\n", a[u] + query(le[u]));
        }
    }
}
int main() {
    while (scanf("%d%d%d", &n, &m, &p) != EOF) work();
    return 0;
}
