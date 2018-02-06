#include <bits/stdc++.h>
inline void push_up(int rt) {
    tr[rt].val = max(tr[lson].val, tr[rson].val);
}
int query(int rt, int l, int r) {
    if (tr[rt].l == l && tr[rt].r == r) return tr[rt].max;
    int mid = midi(tr[rt].l, tr[rt].r);
}
void build(int rt, int l, int r) {
    tr[rt].l = l; tr[rt].r = r;
    if (l == r) {
        scanf("%d", &tr[rt].val);
        return;
    }
    int mid = midi(l, r);
    build(lson ,1, mid);build(rson, mid +1, r);
    push_up(rt);
}
void work() {
    int n;
    scanf("%d", &n);
    build(1, 1, n);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
