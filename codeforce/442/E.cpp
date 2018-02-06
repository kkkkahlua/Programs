#include <bits/stdc++.h>
#define maxn 200010
#define lson (rt<<1)
#define rson (rt<<1|1)
struct node { int l, r, c, tag; }tr[maxn * 4];
struct Edge { int to, ne; }edge[maxn];
int c[maxn], l[maxn], r[maxn], cnt, tot, ne[maxn];
using namespace std;
typedef long long LL;
void add(int u, int v) {
    edge[tot] = {v, ne[u]};
    ne[u] = tot++;
}
void dfs(int u) {
    l[u] = ++cnt;
    for (int i = ne[u]; ~i; i = edge[i].ne) dfs(edge[i].to);
    r[u] = cnt;
}
void push_up(int rt) { tr[rt].c = tr[lson].c + tr[rson].c; }
void build(int rt, int l, int r) {
    tr[rt].l = l, tr[rt].r = r, tr[rt].tag = 0;
    if (l==r) { tr[rt].c = c[l]; return; }
    int mid = l+r >> 1;
    build(lson, l, mid), build(rson, mid+1, r);
    push_up(rt);
}
void push_down(int rt) {
    if (tr[rt].tag) {
        tr[lson].c = tr[lson].r-tr[lson].l+1-tr[lson].c;
        tr[rson].c = tr[rson].r-tr[rson].l+1-tr[rson].c;
        tr[lson].tag ^= 1, tr[rson].tag ^= 1;
        tr[rt].tag = 0;
    }
}
int query(int rt, int l, int r) {
    if (tr[rt].l==l && tr[rt].r==r) return tr[rt].c;
    push_down(rt);
    int mid = tr[rt].l + tr[rt].r >> 1;
    if (r <= mid) return query(lson, l, r);
    else if (l > mid) return query(rson, l, r);
    else return query(lson, l, mid) + query(rson, mid+1, r);
}
void modify(int rt, int l, int r) {
    if (tr[rt].l==l && tr[rt].r==r) {
        tr[rt].c = tr[rt].r-tr[rt].l+1-tr[rt].c, tr[rt].tag ^= 1;
        return;
    }
    push_down(rt);
    int mid = tr[rt].l+tr[rt].r>>1;
    if (r<=mid) modify(lson, l, r);
    else if (l > mid) modify(rson, l, r);
    else modify(lson, l, mid), modify(rson, mid+1, r);
    push_up(rt);
}
int main() {
    int n, x;
    scanf("%d", &n);
    memset(ne, -1, sizeof(ne));
    for (int i = 2; i <= n; ++i) {
        scanf("%d", &x);
        add(x, i);
    }
    dfs(1);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x);
        c[l[i]] = x;
    }
    build(1, 1, n);
    int m;
    scanf("%d", &m);
    char s[5];
    while (m--) {
        scanf("%s%d", s, &x);
        if (s[0]=='g') printf("%d\n", query(1,l[x], r[x]));
        else modify(1,l[x], r[x]);
    }
    return 0;
}
