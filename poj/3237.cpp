#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define maxn 100010
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;
struct Edge {
    int to, ne, w;
    Edge(int a = 0, int b = 0, int c = 0) : to(a), ne(b), w(c) {}
}edge[maxn * 2];
struct node {
    int l, r, mx, mn, flag;
}tr[maxn * 4];
struct E {
    int u, v;
    E(int a = 0, int b = 0) : u(a), v(b) {}
}e[maxn];
int fa[maxn], dep[maxn], ne[maxn], son[maxn], sz[maxn], val[maxn], top[maxn], le[maxn], tot, cnt, p[maxn], w[maxn];
void add(int u, int v, int w) {
    edge[tot] = Edge(v, ne[u], w);
    ne[u] = tot++;
}
void dfs1(int u, int f, int d) {
    fa[u] = f, dep[u] = d, sz[u] = 1;
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (v == f) continue;
        val[v] = edge[i].w;
        dfs1(v, u, d + 1);
        sz[u] += sz[v];
        if (son[u] == -1 || sz[son[u]] < sz[v]) son[u] = v;
    }
}
void dfs2(int u, int sp) {
    top[u] = sp; le[u] = ++cnt;
    if (son[u] == -1) return;
    dfs2(son[u], sp);
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}
void swapp(int& mx, int& mn) {
    int temp = mx;
    mx = -mn;
    mn = -temp;
}
void push_up(int rt) {
    tr[rt].mx = max(tr[lson].mx, tr[rson].mx);
    tr[rt].mn = min(tr[lson].mn, tr[rson].mn);
}
void push_down(int rt) {
    if (tr[rt].flag) {
        tr[lson].flag ^= 1, tr[rson].flag ^= 1;
        swapp(tr[lson].mx, tr[lson].mn), swapp(tr[rson].mx, tr[rson].mn);
        tr[rt].flag = 0;
    }
}
void build(int rt, int l, int r) {
    tr[rt].l = l, tr[rt].r = r; tr[rt].flag = 0;
    if (l == r) { tr[rt].mx = tr[rt].mn = w[l]; return; }
    int mid = l + r >> 1;
    build(lson, l, mid); build(rson, mid + 1, r);
    push_up(rt);
}
void modify1(int rt, int l, int r) {
    if (tr[rt].l == l && tr[rt].r == r) {
        tr[rt].flag ^= 1;
        swapp(tr[rt].mx, tr[rt].mn);
        return;
    }
    push_down(rt);
    int mid = tr[rt].l + tr[rt].r >> 1;
    if (r <= mid) modify1(lson, l, r);
    else if (l > mid) modify1(rson, l, r);
    else { modify1(lson, l, mid); modify1(rson, mid + 1, r); }
    push_up(rt);
}
void modify2(int rt, int x, int w) {
    if (tr[rt].l == tr[rt].r) {
        tr[rt].mx = tr[rt].mn = w;
        return;
    }
    push_down(rt);
    int mid = tr[rt].l + tr[rt].r >> 1;
    if (x <= mid) modify2(lson, x, w);
    else modify2(rson, x, w);
    push_up(rt);
}
int query(int rt, int l, int r) {
    if (tr[rt].l == l && tr[rt].r == r) return tr[rt].mx;
    push_down(rt);
    int mid = tr[rt].l + tr[rt].r >> 1;
    if (r <= mid) return query(lson, l, r);
    else if (l > mid) return query(rson, l, r);
    else return max(query(lson, l, mid), query(rson, mid + 1, r));
}
int ask(int u, int v) {
    int fau = top[u], fav = top[v], ans = -inf;
    while (fau != fav) {
        if (dep[fau] < dep[fav]) swap(u, v), swap(fau, fav);
        ans = max(ans, query(1, le[fau], le[u]));
        u = fa[fau], fau = top[u];
    }
    if (u == v) return ans;
    if (dep[u] < dep[v]) swap(u, v);
    ans = max(ans, query(1, le[v]+1, le[u]));
    return ans;
}
void change(int u, int v) {
    int fau = top[u], fav = top[v];
    while (fau != fav) {
        if (dep[fau] < dep[fav]) swap(u, v), swap(fau, fav);
        modify1(1, le[fau], le[u]);
        u = fa[fau], fau = top[u];
    }
    if (u == v) return;
    if (dep[u] < dep[v]) swap(u, v);
    modify1(1, le[v]+1, le[u]);
}
void work() {
    tot = cnt = 0; memset(ne, -1, sizeof ne); memset(son, -1, sizeof son);
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int w;
        scanf("%d%d%d", &e[i].u, &e[i].v, &w);
        add(e[i].u, e[i].v, w); add(e[i].v, e[i].u, w);
    }
    dfs1(1, -1, 0); dfs2(1, 1);
    for (int i = 1; i <= n; ++i) w[le[i]] = val[i];
    for (int i = 1; i < n; ++i) p[i] = dep[e[i].u] > dep[e[i].v] ? e[i].u : e[i].v;
    build(1, 1, n);
    char s[10];
    while (scanf("%s", s) && s[0] != 'D') {
        int u, v;
        scanf("%d%d", &u, &v);
        if (s[0] == 'Q') printf("%d\n", ask(u, v));
        else if (s[0] == 'N') change(u, v);
        else modify2(1, le[p[u]], v);
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
