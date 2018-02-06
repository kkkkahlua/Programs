#include <bits/stdc++.h>
#define maxn 100010
#define lson (rt << 1)
#define rson lson | 1
using namespace std;
typedef long long LL;
struct node {
    LL val; int s, t;
    int pos; bool type; bool op;
    node(bool _op=0, LL _val=0, int _s=0, int _t=0, int _pos=0, bool _type=0) :
        op(_op), val(_val), s(_s), t(_t), pos(_pos), type(_type) {}
};
struct Tree {
    int l, r; LL w;
}tr[maxn * 4];
struct Edge {
    int to, ne;
    Edge(int _to=0, int _ne=0) : to(_to), ne(_ne) {}
}edge[maxn *2];
int dep[maxn], fa[maxn], son[maxn], ne[maxn], sz[maxn], top[maxn], le[maxn], cnt, tot, n, m;
LL val[maxn], ans[maxn];
vector<node> op;
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
    top[u] = sp, le[u] = ++cnt;
    if (son[u] == -1) return;
    dfs2(son[u], sp);
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}
bool cmp(node u, node v) { return u.val < v.val || (u.val == v.val && u.op < v.op); }
void build(int rt, int l, int r) {
    tr[rt].l = l, tr[rt].r = r, tr[rt].w = 0;
    if (l == r) return;
    int mid = l+r >> 1;
    build(lson, l, mid); build(rson, mid+1, r);
}
void modify(int rt, LL x, int p) {
    if (tr[rt].l == tr[rt].r) { tr[rt].w = x; return; }
    int mid = tr[rt].l+tr[rt].r >> 1;
    if (p <= mid) modify(lson, x, p);
    else modify(rson, x, p);
    tr[rt].w = tr[lson].w + tr[rson].w;
}
LL query(int rt, int l, int r) {
    if (tr[rt].l == l && tr[rt].r == r) return tr[rt].w;
    int mid = tr[rt].l + tr[rt].r >> 1;
    if (r <= mid) return query(lson, l, r);
    else if (l > mid) return query(rson, l, r);
    else return query(lson, l, mid) + query(rson, mid+1, r);
}
LL ask(int u, int v) {
    int fau = top[u], fav = top[v]; LL ret = 0;
    while (fau != fav) {
        if (dep[fau] < dep[fav]) swap(fau, fav), swap(u, v);
        ret += query(1, le[fau], le[u]);
        u = fa[fau], fau = top[u];
    }
    if (dep[u] < dep[v]) swap(u, v);
    ret += query(1, le[v], le[u]);
    return ret;
}
void work() {
    tot = cnt = 0; memset(ne, -1, sizeof(ne));
    op.clear();
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &val[i]);
        op.push_back(node(0, val[i], i));
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(u, v); addEdge(v, u);
    }
    dfs1(1, -1, 0);
    dfs2(1, 1);
    build(1, 1, n);
    for (int i = 0; i < m; ++i) {
        int s, t; LL a, b;
        scanf("%d%d%lld%lld", &s, &t, &a, &b);
        op.push_back(node(1, a-1, s, t, i, 0)); op.push_back(node(1, b, s, t, i, 1));
    }
    sort(op.begin(), op.end(), cmp);
    memset(ans, 0, sizeof(ans));
    for (auto nd : op) {
        if (nd.op) {
            LL ret = ask(nd.s, nd.t);
            if (nd.type) ans[nd.pos] += ret;
            else ans[nd.pos] -= ret;
        }
        else modify(1, nd.val, le[nd.s]);
    }
    printf("%lld", ans[0]);
    for (int i = 1; i < m; ++i) printf(" %lld", ans[i]); printf("\n");
}
int main() {
    freopen("多校第九场标程和数据/数据/1002.in", "r", stdin);
    freopen("02.out", "w", stdout);
//    freopen("in.txt", "r", stdin);
    while (scanf("%d%d", &n, &m) != EOF) work();
    return 0;
}
