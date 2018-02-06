#include <cstdio>
#define lson ((rt) << 1)
#define rson ((rt) << 1 | 1)
#define maxn 100010
inline max(int a, int b) { return a > b ? a : b; }
inline min(int a, int b) { return a < b ? a : b; }
inline midi(int a, int b) { return (a + b) >> 1; }
inline swap(int& a, int& b) { int temp = a; a = b; b = temp; }
struct node {
    int l1, l0, r1, r0, t1, t0, len, l, r;
    bool flag;
}tree[maxn * 4];
int n, m;
void lift_up(int rt) {
    tree[rt].l1 = tree[lson].l1; tree[rt].l0 = tree[lson].l0;
    if (tree[rt].l1 == tree[lson].len) tree[rt].l1 += tree[rson].l1;
    if (tree[rt].l0 == tree[lson].len) tree[rt].l0 += tree[rson].l0;
    tree[rt].r1 = tree[rson].r1; tree[rt].r0 = tree[rson].r0;
    if (tree[rt].r1 == tree[rson].len) tree[rt].r1 += tree[lson].r1;
    if (tree[rt].r0 == tree[rson].len) tree[rt].r0 += tree[lson].r0;
    tree[rt].t1 = max(max(tree[lson].t1, tree[rson].t1), tree[lson].r1 + tree[rson].l1);
    tree[rt].t0 = max(max(tree[lson].t0, tree[rson].t0), tree[lson].r0 + tree[rson].l0);
}
void build(int rt, int l, int r) {
    tree[rt].l = l; tree[rt].r = r; tree[rt].len = r - l + 1; tree[rt].flag = 0;
    if (l == r) {
        int x;
        scanf("%d", &x);
        tree[rt].l1 = tree[rt].r1 = tree[rt].t1 = x;
        tree[rt].l0 = tree[rt].r0 = tree[rt].t0 = 1 - x;
        return;
    }
    int mid = midi(l, r);
    build(lson, l, mid); build(rson, mid + 1, r);
    lift_up(rt);
}
void push_down(int rt) {
    if (tree[rt].flag) {
        swap(tree[lson].l1, tree[lson].l0); swap(tree[lson].r1, tree[lson].r0);
        swap(tree[lson].t1, tree[lson].t0);
        swap(tree[rson].l1, tree[rson].l0); swap(tree[rson].r1, tree[rson].r0);
        swap(tree[rson].t1, tree[rson].t0);
        tree[lson].flag ^= 1;
        tree[rson].flag ^= 1;
        tree[rt].flag = 0;
    }
}
int query(int rt, int l, int r) {
    if (tree[rt].l == l && tree[rt].r == r) return tree[rt].t1;
    push_down(rt);
    int mid = midi(tree[rt].l, tree[rt].r);
    if (r <= mid) return query(lson, l, r);
    else if (l > mid) return query(rson, l, r);
    else {
        int ans1 = query(lson, l, mid), ans2 = query(rson, mid + 1, r),
            ans3 = min(mid - l + 1, tree[lson].r1) + min(r - mid, tree[rson].l1);
        return max(max(ans1, ans2), ans3);
    }
}
void modify(int rt, int l, int r) {
    if (tree[rt].l == l && tree[rt].r == r) {
        swap(tree[rt].l1, tree[rt].l0); swap(tree[rt].r1, tree[rt].r0);
        swap(tree[rt].t1, tree[rt].t0);
        tree[rt].flag ^= 1;
        return;
    }
    push_down(rt);
    int mid = midi(tree[rt].l, tree[rt].r);
    if (r <= mid) modify(lson, l, r);
    else if (l > mid) modify(rson, l, r);
    else { modify(lson, l, mid); modify(rson, mid + 1, r); }
    lift_up(rt);
}
void work() {
    build(1, 1, n);
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int x, l, r;
        scanf("%d%d%d", &x, &l, &r);
        if (x == 0) printf("%d\n", query(1, l, r));
        else modify(1, l, r);
//        for (int i = 1; i <= 7; ++i) {
//            printf("%d %d %d %d %d %d %d %d %d\n", tree[i].l, tree[i].r, tree[i].flag, tree[i].l1, tree[i].t1, tree[i].r1, tree[i].l0, tree[i].t0, tree[i].r0);
//        }
    }
}
int main() {
    while (scanf("%d", &n) != EOF) work();
    return 0;
}
