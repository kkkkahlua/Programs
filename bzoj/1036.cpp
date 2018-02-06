#include <bits/stdc++.h>
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define inf 0x3f3f3f3f
#define maxn 30010
typedef long long LL;
using namespace std;
int sz[maxn], top[maxn], son[maxn], dep[maxn], fa[maxn], le[maxn], ne[maxn], tot, cnt;
LL w[maxn], val[maxn];
struct Edge {
    int to, ne;
    Edge(int a = 0, int b = 0) : to(a), ne(b) {}
}edge[maxn * 2];
void add(int u, int v) {
    edge[tot] = Edge(v, ne[u]);
    ne[u] = tot++;
}
struct node {
    int l, r; LL mx, w;
}tr[maxn * 4];
void dfs1(int u, int f, int d) {
    sz[u] = 1, fa[u] = f, dep[u] = d;
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (v == f) continue;
        dfs1(v, u, d + 1);
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
void push_up(int rt) {
    tr[rt].w = tr[lson].w + tr[rson].w;
    tr[rt].mx = max(tr[lson].mx, tr[rson].mx);
}
void build(int rt, int l, int r) {
    tr[rt].l = l, tr[rt].r = r;
    if (l == r) { tr[rt].w = tr[rt].mx = w[l]; return; }
    int mid = l + r >> 1;
    build(lson, l, mid); build(rson, mid + 1, r);
    push_up(rt);
}
void modify(int rt, int x, LL w) {
    if (tr[rt].l == tr[rt].r) { tr[rt].w = tr[rt].mx = w; return; }
    int mid = tr[rt].l + tr[rt].r >> 1;
    if (x <= mid) modify(lson, x, w);
    else modify(rson, x, w);
    push_up(rt);
}
LL query(int rt, int l, int r, int type) {
    if (tr[rt].l == l && tr[rt].r == r) return type ? tr[rt].w : tr[rt].mx;
    int mid = tr[rt].l + tr[rt].r >> 1;
    if (r <= mid) return query(lson, l, r, type);
    else if (l > mid) return query(rson, l, r, type);
    else return type ? query(lson, l, mid, type) + query(rson, mid + 1, r, type) :
            max(query(lson, l, mid, type), query(rson, mid + 1, r, type));
}
LL ask(int u, int v, int type) {
    int fau = top[u], fav = top[v];
    LL ans = type ? 0 : -inf;
    while (fau != fav) {
        if (dep[fau] < dep[fav]) swap(fau, fav), swap(u, v);
        if (type) ans += query(1, le[fau], le[u], type);
        else ans = max(ans, query(1, le[fau], le[u], type));
        u = fa[fau], fau = top[u];
    }
    if (dep[u] < dep[v]) swap(u, v);
    if (type) ans += query(1, le[v], le[u], type);
    else ans = max(ans, query(1, le[v], le[u], type));
    return ans;
}
int n;
void work() {
    memset(ne, -1, sizeof ne); memset(son, -1, sizeof son);
    tot = cnt = 0;
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v); add(v, u);
    }
    dfs1(1, -1, 0);
    dfs2(1, 1);
    for (int i = 1; i <= n; ++i) scanf("%lld", &val[i]);
    for (int i = 1; i <= n; ++i) w[le[i]] = val[i];
//    for (int i = 1; i <= n; ++i) printf("%d ", le[i]); printf("\n");
//    for (int i = 1; i <= n; ++i) printf("%d ", top[i]); printf("\n");
//    for (int i = 1; i <= n; ++i) printf("%lld ", w[i]); printf("\n");
    build(1, 1, n);
    int q;
    scanf("%d", &q);
    while (q--) {
        char s[10]; int u, v;
        scanf("%s%d%d", s, &u, &v);
        if (s[0] == 'C') modify(1, le[u], v);
        else if (s[1] == 'M') printf("%lld\n", ask(u, v, 0));
        else printf("%lld\n", ask(u, v, 1));
    }
}
int main() {
    freopen("in.txt", "r", stdin);
    while (scanf("%d", &n) != EOF) work();
    return 0;
}
