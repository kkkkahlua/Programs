#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define maxn 100010
typedef long long LL;
int le[maxn], ri[maxn], ne[maxn], tot, cnt, kas;
LL val[maxn], p[maxn], a[maxn];
struct node {
    int l, r; LL val, tag;
}tr[maxn * 4];
struct Edge {
    int to, ne;
    Edge(int a = 0, int b = 0): to(a), ne(b) {}
}edge[maxn * 2];
void add(int u, int v) {
    edge[tot] = Edge(v, ne[u]);
    ne[u] = tot++;
}
void init() {
    tot = cnt = 0;
    memset(ne, -1, sizeof(ne));
}
inline LL max(LL a, LL b) { return a > b ? a : b; }
inline int midi(int l, int r) { return l + r >> 1; }
inline void push_up(int rt) { tr[rt].val = max(tr[lson].val, tr[rson].val); }
inline void push_down(int rt) {
    if (tr[rt].tag) {
        tr[lson].tag += tr[rt].tag; tr[rson].tag += tr[rt].tag;
        tr[lson].val += tr[rt].tag; tr[rson].val += tr[rt].tag;
        tr[rt].tag = 0;
    }
}
void build(int rt, int l, int r) {
    tr[rt].l = l; tr[rt].r = r; tr[rt].tag = 0;
    if (l == r) { tr[rt].val = a[l]; return; }
    int mid = midi(l, r);
    build(lson, l, mid); build(rson, mid + 1, r);
    push_up(rt);
}
void dfs(int u, int fa, LL w) {
    le[u] = ri[u] = ++cnt;
    p[u] = w;
    for (int i = ne[u]; i != -1; i = edge[i].ne) {
        int v = edge[i].to;
        if (v == fa) continue;
        dfs(v, u, w + val[v]);
        ri[u] = max(ri[u], ri[v]);
    }
}
void modify(int rt, int l, int r, LL add) {
    if (tr[rt].l == l && tr[rt].r == r) {
        tr[rt].tag += add;
        tr[rt].val += add;
        return;
    }
    push_down(rt);
    int mid = midi(tr[rt].l, tr[rt].r);
    if (r <= mid) modify(lson, l, r, add);
    else if (l > mid) modify(rson, l, r, add);
    else { modify(lson, l, mid, add); modify(rson, mid + 1, r, add); }
    push_up(rt);
}
LL query(int rt, int l, int r) {
    if (tr[rt].l == l && tr[rt].r == r) return tr[rt].val;
    push_down(rt);
    int mid = midi(tr[rt].l, tr[rt].r);
    if (r <= mid) return query(lson, l, r);
    else if (l > mid) return query(rson, l, r);
    else return max(query(lson, l, mid), query(rson, mid + 1, r));
}
void work() {
    printf("Case #%d:\n", ++kas);
    init();
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v); add(v, u);
    }
    for (int i = 0; i < n; ++i) scanf("%lld", &val[i]);
    dfs(0, -1, val[0]);
//    for (int i = 0; i < n; ++i) {
//        printf("%d %d\n", le[i], ri[i]);
//    }
    for (int i = 0; i < n; ++i) a[le[i]] = p[i];
//    for (int i = 1; i <= n; ++i) printf("%lld ", a[i]); printf("\n");
    build(1, 1, n);
//    for (int i = 1; i <= 13; ++i) printf("%d %d %lld\n", tr[i].l ,tr[i].r, tr[i].val);
    while (m--) {
        int x, u; LL w;
        scanf("%d", &x);
        if (x == 0) {
            scanf("%d%lld", &u, &w);
            modify(1, le[u], ri[u], w - val[u]);
            val[u] = w;
        }
        else {
            scanf("%d", &u);
//            printf("query : %d %d\n", le[u], ri[u]);
            printf("%lld\n", query(1, le[u], ri[u]));
        }
    }
}
int main() {
    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
