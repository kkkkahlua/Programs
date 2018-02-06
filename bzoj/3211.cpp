#include <bits/stdc++.h>
#define maxn 100010
#define lson (rt << 1)
#define rson (rt << 1 | 1)
typedef long long LL;
struct node {
    int l, r;
    bool flag;
    LL sum;
}tr[maxn * 4];
inline void push_up(int rt) {
    tr[rt].sum = tr[lson].sum + tr[rson].sum;
    tr[rt].flag = tr[lson].flag & tr[rson].flag;
}
inline int midi(int a, int b) { return a + b >> 1; }
void build(int rt, int l, int r) {
    tr[rt].l = l, tr[rt].r = r, tr[rt].flag = 0;
    if (l == r) {
        scanf("%lld", &tr[rt].sum);
        if (tr[rt].sum == 0 || tr[rt].sum == 1) tr[rt].flag = 1;
        return;
    }
    int mid = midi(l,r);
    build(lson, l, mid);
    build(rson, mid + 1, r);
    push_up(rt);
}
void modify(int rt, int l, int r) {
    if (tr[rt].flag) return;
    if (tr[rt].l == tr[rt].r) {
        tr[rt].sum = sqrt(tr[rt].sum);
        if (tr[rt].sum == 1 || tr[rt].sum == 0) tr[rt].flag = 1;
        return;
    }
    int mid = midi(tr[rt].l, tr[rt].r);
    if (r <= mid) modify(lson, l, r);
    else if (l > mid) modify(rson, l, r);
    else { modify(lson, l, mid); modify(rson, mid + 1, r); }
    push_up(rt);
}
LL query(int rt, int l, int r) {
    if (tr[rt].l == l && tr[rt].r == r) return tr[rt].sum;
    int mid = midi(tr[rt].l, tr[rt].r);
    if (r <= mid) return query(lson, l, r);
    else if (l > mid) return query(rson, l, r);
    else return query(lson, l, mid) + query(rson, mid + 1, r);
}
int n, q;
void work() {
    build(1, 1, n);
    scanf("%d", &q);
    while (q--) {
        int x, l, r;
        scanf("%d%d%d",&x,&l,&r);
        if (x == 1) printf("%lld\n", query(1, l, r));
        else modify(1, l, r);
    }
}
int main() {
    while (scanf("%d", &n) != EOF) work();
    return 0;
}
