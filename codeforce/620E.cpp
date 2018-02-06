#include <bits/stdc++.h>
#define maxn 400010
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
typedef long long LL;
int col[maxn], c[maxn], le[maxn], ri[maxn], tot, cnt, ne[maxn];
struct Edge {
    int to, ne;
    Edge(int a = 0, int b = 0): to(a), ne(b) {}
}edge[maxn * 2];
struct node {
    int l, r; LL tag, mask;
}tr[maxn * 4];
inline int midi(int l, int r) { return l + r >> 1; }
void add(int u, int v) {
    edge[tot] = Edge(v, ne[u]);
    ne[u] = tot++;
}
void dfs(int u, int fa) {
    le[u] = ri[u] = ++cnt;
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (v == fa) continue;
        dfs(v, u);
        ri[u] = max(ri[u], ri[v]);
    }
}
inline void push_up(int rt) {
    tr[rt].mask = tr[lson].mask | tr[rson].mask;
}
inline void push_down(int rt) {
    if (tr[rt].tag) {
        tr[lson].mask = tr[rson].mask = tr[lson].tag = tr[rson].tag = tr[rt].tag;
        tr[rt].tag = 0;
    }
}
int count(LL x) {
    int ret = 0;
    while (x) {
        ++ret;
        x &= (x - 1);
    }
    return ret;
}
void build(int rt, int l, int r) {
    tr[rt].l = l, tr[rt].r = r, tr[rt].tag = 0;
    if (l == r) { tr[rt].mask = (1LL << c[l]); return; }
    push_up(rt);
    int mid = midi(l, r);
    build(lson, l, mid); build(rson, mid +1, r);
    push_up(rt);
}
void modify(int rt, int l, int r, int c) {
    if (tr[rt].l == l && tr[rt].r == r) {
        tr[rt].mask = (1LL << c);
        tr[rt].tag = (1LL << c);
        return;
    }
    push_down(rt);
    int mid = midi(tr[rt].l, tr[rt].r);
    if (r <= mid) modify(lson, l, r, c);
    else if (l > mid) modify(rson, l, r, c);
    else { modify(lson, l, mid, c); modify(rson, mid + 1, r, c); }
    push_up(rt);
}
LL query(int rt, int l, int r) {
    if (count(tr[rt].mask) == 1) return tr[rt].mask;
    if (tr[rt].l == l && tr[rt].r == r) return tr[rt].mask;
    push_down(rt);
    int mid = midi(tr[rt].l, tr[rt].r);
    if (r <= mid) return query(lson, l, r);
    else if (l > mid) return query(rson, l, r);
    else return query(lson, l, mid) | query(rson, mid + 1, r);
    push_up(rt);
}
int n, m;
void work() {
    tot = cnt = 0; memset(ne, -1, sizeof(ne));
    for (int i = 1; i <= n; ++i) scanf("%d", &col[i]);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v); add(v, u);
    }
    dfs(1, -1);
    for (int i = 1; i <= n; ++i) c[le[i]] = col[i] - 1;
    build(1, 1, n);
//    for (int i = 1; i <= n; ++i) printf("%d %d\n", le[i], ri[i]);
    while (m--) {
        int t, v, c;
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d%d", &v, &c);
            modify(1, le[v], ri[v], c - 1);
        }
        else {
            scanf("%d", &v);
            printf("%d\n", count(query(1, le[v], ri[v])));
        }
    }
}
int main() {
    freopen("in.txt", "r", stdin);
    while (scanf("%d%d", &n, &m) != EOF) work();
    return 0;
}
