#include <bits/stdc++.h>
typedef long long LL;
inline void push_up(int rt) { tr[rt].sum = tr[lson].sum + tr[rson].sum; }
inline void push_down(int rt) {
    if (tr[rt].tag2) {

    }
}
void build(int rt, int l, int r) {
    tr[rt].l = l; tr[rt].r = r; tr[rt].tag1 = 0; tr[rt].tag2 = 0;
    if (l == r) {
        scanf("%lld", &tr[rt].sum);
        return;
    }
    int mid = midi(l, r);
    build(lson, l, mid); build(rson, mid + 1, r);
    push_up(rt);
}
void modify(int rt, int l, int r) {
    if (tr[rt].l == l && tr[rt].r == r) {
        if (op == 1) {
            tr[rt].sum = ssum[r] - ssum[l - 1];
            tr[rt].tag2 = 1;
            tr[rt].tag1 = 0;
        }
        else {
            tr[rt].sum -= (r - l + 1) *
        }
        return;
    }
    push_down(rt);
    int mid = midi(tr[rt].l, tr[rt].r);
    if (r <= mid) modify(lson, l, r);
    else if (l > mid) modify(rson, l, r);
    else { modify(lson, l, mid); modify(rson, mid + 1, r); }
    push_up(rt);
}
LL query(int rt, int l, int r) {
    if (tr[rt].l == tr[rt].r) {
        if (tr[rt].tag2) return ssum[r] - ssum[l - 1];
        return tr[rt].sum;
    }
    push_down(rt);
    int mid = midi(tr[rt].l, tr[rt].r);
    if (r <= mid) return query(lson, l, r);
    else if (l > mid) return query(rson, l, r);
    else return query(lson, l, mid) + query(rson, mid + 1, r);
}
int main() {
    scanf("%d%d", &n, &m);
    build(1, 1, n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &idx, &l, &r);
        if (idx == 1) {
            printf("%lld\n", query(1, l, r));
        }
        else if (idx == 2) {
            scanf("%d", &k);
            LL rep = query(1, )
            modify(1, l, r, 0, query(1, l, r, ));
        else modify(1, l, r, 1);
    }
}
