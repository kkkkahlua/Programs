#include <bits/stdc++.h>
#define maxn 100010
#define lson (rt <<1)
#define rson (rt << 1 | 1)
typedef long long LL;
using namespace std;
int fa[maxn], sz[maxn], top[maxn], son[maxn], ne[maxn], c[maxn], col[maxn], tot, dep[maxn], le[maxn], cnt;
struct Edge {
    int to, ne;
    Edge(int _to = 0, int _ne = 0) : to(_to), ne(_ne) {}
}edge[maxn * 2];
void add(int u, int v) {
    edge[tot] = Edge(v, ne[u]);
    ne[u] = tot++;
}
struct node { int l, r, lc, rc, tag; LL num; }tr[maxn * 4];
void dfs1(int u, int f, int d) {
//    printf("%d %d %d\n", u, f, d);
    fa[u] = f, dep[u] = d, sz[u] = 1;
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (v == f) continue;
        dfs1(v, u, d+1);
        sz[u] += sz[v];
        if (son[u] == -1 || sz[son[u]] < sz[v]) son[u] = v;
    }
}
void dfs2(int u, int tp) {
//    printf("%d %d\n", u, tp);
    top[u] = tp, le[u] = ++cnt;
    if (son[u] == -1) return;
    dfs2(son[u], tp);
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}
void push_up(int rt) {
    tr[rt].lc = tr[lson].lc, tr[rt].rc = tr[rson].rc;
    tr[rt].num = tr[lson].num + tr[rson].num - (tr[lson].rc == tr[rson].lc);
}
void push_down(int rt) {
    if (tr[rt].tag != -1) {
        tr[lson].lc = tr[rson].rc = tr[rson].lc = tr[rson].rc = tr[lson].tag = tr[rson].tag = tr[rt].tag;
        tr[lson].num = tr[rson].num = 1;
        tr[rt].tag = -1;
    }
}
void build(int rt, int l, int r) {
    tr[rt].l = l, tr[rt].r = r, tr[rt].tag = -1;
    if (l == r) {
        tr[rt].lc = tr[rt].rc = col[l];
        tr[rt].num = 1;
        return;
    }
    int mid = l+r >>1;
    build(lson, l, mid); build(rson, mid+1, r);
    push_up(rt);
}
void modify(int rt, int l, int r, int c) {
    if (tr[rt].l == l && tr[rt].r == r) {
        tr[rt].lc = tr[rt].rc = tr[rt].tag = c;
        tr[rt].num = 1;
        return;
    }
    push_down(rt);
    int mid = tr[rt].l + tr[rt].r >>1;
    if (r <= mid) modify(lson, l, r, c);
    else if (l > mid) modify(rson, l, r, c);
    else { modify(lson, l, mid, c); modify(rson, mid+1, r, c); }
    push_up(rt);
}
LL query1(int rt, int l, int r) {
    if (tr[rt].l == l && tr[rt].r == r) {
        return tr[rt].num;
    }
    push_down(rt);
    int mid = tr[rt].l+tr[rt].r >>1;
    if (r <= mid) return query1(lson, l, r);
    else if (l > mid) return query1(rson, l, r);
    else return query1(lson, l, mid) + query1(rson, mid+1, r) - (tr[lson].rc==tr[rson].lc);
}
int query2(int rt, int x) {
    if (tr[rt].l == x) return tr[rt].lc;
    if (tr[rt].r == x) return tr[rt].rc;
    push_down(rt);
    int mid = tr[rt].l+tr[rt].r >> 1;
    if (x <= mid) return query2(lson, x);
    else return query2(rson, x);
}
int lca(int u, int v) {
    int fau = top[u], fav = top[v];
    while (fau != fav) {
//        printf("%d %d %d %d\n", u ,v, fau, fav);
        if (dep[fau] < dep[fav]) swap(fau, fav), swap(u, v);
        u = fa[fau]; fau = top[u];
    }
    if (dep[u] < dep[v]) swap(u, v);
    return v;
}
void change(int u, int f, int d) {
    int fau = top[u], faf = top[f];
    while (fau != faf) {
        modify(1, le[fau], le[u], d);
        u = fa[fau], fau = top[u];
    }
    modify(1, le[f], le[u], d);
}
LL ask(int u, int f) {
//    printf("%d %d: \n", u, f);
    LL ans = 0;
    int fau = top[u], faf = top[f];
    while (fau != faf) {
        ans += query1(1, le[fau], le[u]);
        int uc = query2(1, le[fa[fau]]), dc = query2(1, le[fau]);
//        printf("%d ", ans);
//        printf("uc dc : %d %d ", uc, dc);
        if (uc == dc) --ans;
        u = fa[fau], fau = top[u];
//        printf("%d ", ans);
    }
    ans += query1(1, le[f], le[u]);
//    printf("%d\n", ans);
    return ans;
}
int n, m;
int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &c[i]);
    tot = 0; memset(ne, -1, sizeof(ne)); memset(son, -1, sizeof(son));
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v); add(v, u);
    }
    dfs1(1, -1, 0);
    dfs2(1, 1);

//    for (int i = 1; i <= n; ++i) printf("%d ", top[i]);

    for (int i = 1; i <= n; ++i) col[le[i]] = c[i];
//    for (int i = 1; i <= n; ++i) printf("%d ", col[i]); printf("\n");

    build(1, 1, n);

//    for (int i = 1; i <= 13; ++i) {
//        printf("%d %d %d %d %lld\n", tr[i].l, tr[i].r, tr[i].lc, tr[i].rc, tr[i].num);
//    }

    char ch; int a, b, d;
    while (scanf("\n%c%d%d", &ch, &a, &b) != EOF) {
//        printf("%c\n", ch);
        if (ch == 'C') {
            scanf("%d", &d);
            int grand = lca(a, b);
//            printf("lca : %d\n", grand);
            change(a, grand, d);
            change(b, grand, d);
        }
        else {
            int grand = lca(a, b);
//            printf("lca : %d\n", grand);
            LL ans1 = ask(a, grand), ans2 = ask(b, grand);
            printf("%lld\n", ans1+ans2-1);
        }
    }
    return 0;
}
