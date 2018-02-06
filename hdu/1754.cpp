#include <cstdio>
#define maxn 200010
inline int max(int a, int b) { return a > b ? a : b; }
int n, m;
struct node {
    int l, r, val;
}tree[maxn * 4];
void lift_up(int rt) {
    tree[rt].val = max(tree[rt << 1].val, tree[rt << 1 | 1].val);
}
void build(int rt, int l, int r) {
    tree[rt].l = l; tree[rt].r = r;
    if (l == r) {
        scanf("%d", &tree[rt].val);
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    lift_up(rt);
}
int query(int rt, int l, int r) {
    if (tree[rt].l == l && tree[rt].r == r) return tree[rt].val;
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    if (r <= mid) return query(rt << 1, l, r);
    else if (l > mid) return query(rt << 1 | 1, l, r);
    else return max(query(rt << 1, l, mid), query(rt << 1 | 1, mid + 1, r));
}
void modify(int rt, int id, int x) {
    if (tree[rt].l == tree[rt].r) {
        tree[rt].val = x;
        return;
    }
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    if (id <= mid) modify(rt << 1, id, x);
    else if (id > mid) modify(rt << 1 | 1, id, x);
    lift_up(rt);
}
void work() {
    build(1, 1, n);
//    for (int i = 1; i <= 9; ++i) printf("%d %d %d\n", tree[i].l, tree[i].r, tree[i].val);
//    scanf("\n");
    for (int i = 0; i < m; ++i) {
        char ch; int l, r;
        scanf("\n%c%d%d", &ch, &l, &r);
//        printf("%c\n", ch);
        if (ch == 'Q') printf("%d\n", query(1, l, r));
        else modify(1, l, r);
    }
}
int main() {
    freopen("1754.in", "r", stdin);
//    freopen("1754.out", "w", stdout);
    while (scanf("%d%d", &n, &m) != EOF) work();
    return 0;
}
