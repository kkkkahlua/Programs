#include <bits/stdc++.h>
#define maxn 100010
#define lson (rt << 1)
#define rson (rt << 1 | 1)
struct Edge {
    int to, ne;
    Edge(int a = 0, int b = 0) : to(a), ne(b) {}
}edge[maxn * 2];
struct node { int l, r, c; }tr[maxn * 4];
inline int midi(int l, int r) { return l + r >> 1; }
int le[maxn], ri[maxn], tot, cnt, ne[maxn], depth[maxn];
void add(int u, int v) {
    edge[tot] = Edge(v, ne[u]);
    ne[u] = tot++;
}
void dfs(int u, int fa, int dep) {
    le[u] = ++cnt; depth[u] = dep;
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (v == fa) continue;
        dfs(v, u, dep + 1);
    }
    ri[u] = cnt;
}
void build(int rt, int l, int r) {
    tr[rt].l = l, tr[rt].r = r; tr[rt].c = 0;
    if (l == r) { tr[rt].c = 1; return; }
    int mid = midi(l, r);
    build(lson, l, mid); build(rson, mid + 1, r);
}
inline void push_down(int rt) {
    if (tr[rt].c) {
        tr[lson].c = depth[tr[rt].c] > depth[tr[lson].c] ? tr[rt].c : tr[lson].c;
        tr[rson].c = depth[tr[rt].c] > depth[tr[rson].c] ? tr[rt].c : tr[rson].c;
        tr[rt].c = 0;
    }
}
void modify(int rt, int l, int r, int c) {
    if (tr[rt].l == l && tr[rt].r == r) {
        tr[rt].c = depth[c] > depth[tr[rt].c] ? c : tr[rt].c;
        return;
    }
    push_down(rt);
    int mid = midi(tr[rt].l, tr[rt].r);
    if (r <= mid) modify(lson, l, r, c);
    else if (l > mid) modify(rson, l, r, c);
    else { modify(lson, l, mid, c); modify(rson, mid + 1, r, c); }
}
int query(int rt, int x) {
    if (tr[rt].l == tr[rt].r) return tr[rt].c;
    push_down(rt);
    int mid = midi(tr[rt].l, tr[rt].r);
    if (x <= mid) return query(lson, x);
    else if (x > mid) return query(rson, x);
}
int n, q;
void work() {
    tot = cnt = 0; memset(ne, -1, sizeof(ne));
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v); add(v, u);
    }
    dfs(1, -1, 0);
    build(1, 1, n);
    while (q--) {
        int x;
        char c;
        scanf("\n%c%d", &c, &x);
        if (c == 'Q') printf("%d\n", query(1, le[x]));
        else {
            modify(1, le[x], ri[x], x);
        }
    }
}
int main() {
    freopen("in.txt", "r", stdin);
    while (scanf("%d%d", &n, &q) != EOF) work();
    return 0;
}
