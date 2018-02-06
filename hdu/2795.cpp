#include <bits/stdc++.h>
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define maxn 200010
struct node {
    int l, r, max, id;
}tr[maxn * 4];
int h, w, n, tot;
inline max(int a, int b) { return a > b ? a : b; }
void push_up(int rt) {
    tr[rt].max = max(tr[lson].max, tr[rson].max);
}
void build(int rt, int l, int r) {
    tr[rt].l = l; tr[rt].r = r; tr[rt].max = w;
    if (l == r) { tr[rt].id = ++tot; return; }
    int mid = l + r >> 1;
    build(lson, l, mid); build(rson, mid + 1, r);
}
void query(int rt, int x) {
    if (tr[rt].l == tr[rt].r) {
        printf("%d\n", tr[rt].id);
        tr[rt].max -= x;
        return;
    }
    if (tr[lson].max >= x) query(lson, x);
    else query(rson, x);
    push_up(rt);
}
void work() {
    h = h < n ? h : n;
    tot = 0;
    build(1, 1, h);
    for (int i = 0; i < n; ++i) {
//        printf("i : %d\n", i);
//        for (int j = 1; j <= 9; ++j) {
//            printf("%d %d %d %d %d\n", j, tr[j].l, tr[j].r, tr[j].max, tr[j].id);
//        }
        int x;
        scanf("%d", &x);
        if (tr[1].max < x) { printf("-1\n"); continue; }
        query(1, x);
    }
}
int main() {
    freopen("in.txt", "r", stdin);
    while (scanf("%d%d%d", &h, &w, &n) != EOF) work();
    return 0;
}
