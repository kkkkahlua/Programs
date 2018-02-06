#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
typedef long long LL;
struct node {
    LL a, b;
    int pos; bool type;
    node(LL _a=0, LL _b=0, int _p=0, bool _t=0) : a(_a), b(_b), pos(_p), type(_t) {}
};
struct Edge {
    int to, ne;
    Edge(int _to=0, int _ne=0) : to(_to), ne(_ne) {}
}edge[maxn *2];
int dep[maxn], fa[maxn], son[maxn], ne[maxn], sz[maxn], top[maxn], q, tot, n, m;
LL val[maxn], g[maxn], ret[maxn], c[maxn];
vector<node> que[maxn];
vector<LL> ans[maxn];
void addEdge(int u, int v) {
    edge[tot] = Edge(v, ne[u]);
    ne[u] = tot++;
}
void dfs1(int u, int f, int depth) {
    dep[u] = depth, fa[u] = f, son[u] = -1, sz[u] = 1;
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (v == f) continue;
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
        if (v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}
int LCA(int u, int v) {
    int fau = top[u], fav = top[v];
    while (fau != fav) {
        if (dep[fau] < dep[fav]) swap(fau, fav), swap(u, v);
        u = fa[fau], fau = top[u];
    }
    return dep[u] < dep[v] ? u : v;
}
int lowbit(int x) { return x & (-x); }
void add(int x, LL w) { while (x <= q) c[x] += w, x += lowbit(x); }
LL query(int x) { LL ret = 0; while (x) ret += c[x], x -= lowbit(x); return ret; }
LL calc(LL a, LL b) {
    LL ret = 0;
    int p = upper_bound(g+1, g+1+q, b) - (g+1);
    if (p) ret += query(p);
    p = upper_bound(g+1, g+1+q, a-1) - (g+1);
    if (p) ret -= query(p);
    return ret;
}
void dfs(int u) {
    vector<int> v;
    add(upper_bound(g+1, g+1+q, val[u])-(g+1), val[u]);
    if (!que[u].empty()) {
        for (auto x : que[u]) {
            ans[u].push_back(calc(x.a, x.b));
        }
    }
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (v == fa[u]) continue;
        dfs(v);
    }
    add(upper_bound(g+1, g+1+q, val[u])-(g+1), -val[u]);
}
void work() {
    for (int i = 1; i <= n; ++i) ans[i].clear(), que[i].clear();
    tot = 0; memset(ne, -1, sizeof(ne));
    memset(c, 0, sizeof c);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &val[i]);
        g[i] = val[i];
    }
    sort(g+1, g+1+n);
    q = unique(g+1, g+1+n) - (g+1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(u, v); addEdge(v, u);
    }
    dfs1(1, -1, 0);
    dfs2(1, 1);
    for (int i = 0; i < m; ++i) {
        int s, t; LL a, b;
        scanf("%d%d%lld%lld", &s, &t, &a, &b);
        int lca = LCA(s, t);
        que[s].push_back(node(a, b, i, 1)), que[t].push_back(node(a, b, i, 1)), que[lca].push_back(node(a, b, i, 0));
        if (lca != 1) que[fa[lca]].push_back(node(a, b, i, 0));
    }

    dfs(1);

    memset(ret, 0, sizeof ret);
    for (int i = 1; i <= n; ++i) {
        if (que[i].empty()) continue;
        int sz = que[i].size();
        for (int j = 0; j < sz; ++j) {
            int p = que[i][j].pos;
            if (que[i][j].type) ret[p] += ans[i][j];
            else ret[p] -= ans[i][j];
        }
    }
    printf("%lld", ret[0]);
    for (int i = 1; i < m; ++i) printf(" %lld", ret[i]); printf("\n");
}
int main() {
    freopen("多校第九场标程和数据/数据/1002.in", "r", stdin);
    freopen("02.out", "w", stdout);
    while (scanf("%d%d", &n, &m) != EOF) work();
    return 0;
}
