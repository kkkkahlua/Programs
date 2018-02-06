#include <cstdio>
#define lson ((rt) << 1)
#define rson ((rt) << 1 | 1)
#define maxn 100010
inline max(int a, int b) { return a > b ? a : b; }
inline min(int a, int b) { return a < b ? a : b; }
inline midi(int a, int b) { return (a + b) >> 1; }
inline swap(int& a, int& b) { int temp = a; a = b; b = temp; }
int n, m;
struct node {
    int l, r, num, l1, l0, r1, r0, t1, t0, len, flag1, flag2;
}tree[maxn * 4];
void lift_up(int rt) {
    tree[rt].num = tree[lson].num + tree[rson].num;
    tree[rt].l1 = tree[lson].l1; tree[rt].r1 = tree[rson].r1;
    if (tree[rt].l1 == tree[lson].len) tree[rt].l1 += tree[rson].l1;
    if (tree[rt].r1 == tree[rson].len) tree[rt].r1 += tree[lson].r1;
    tree[rt].l0 = tree[lson].l0; tree[rt].r0 = tree[rson].r0;
    if (tree[rt].l0 == tree[lson].len) tree[rt].l0 += tree[rson].l0;
    if (tree[rt].r0 == tree[rson].len) tree[rt].r0 += tree[lson].r0;
    tree[rt].t1 = max(max(tree[lson].t1, tree[rson].t1), tree[lson].r1 + tree[rson].l1);
    tree[rt].t0 = max(max(tree[lson].t0, tree[rson].t0), tree[lson].r0 + tree[rson].l0);
}
void push_down(int rt) {
    if (tree[rt].flag2 != -1) {
        tree[lson].l1 = tree[lson].r1 = tree[lson].t1 = tree[lson].num = tree[rt].flag2 * tree[lson].len;
        tree[lson].l0 = tree[lson].r0 = tree[lson].t0 = (1 - tree[rt].flag2) * tree[lson].len;
        tree[rson].l1 = tree[rson].r1 = tree[rson].t1 = tree[rson].num = tree[rt].flag2 * tree[rson].len;
        tree[rson].l0 = tree[rson].r0 = tree[rson].t0 = (1 - tree[rt].flag2) * tree[rson].len;
        tree[lson].flag2 = tree[rson].flag2 = tree[rt].flag2;
        tree[rt].flag2 = -1; tree[rt].flag1 = 0;
        return;
    }
    if (tree[rt].flag1) {
        swap(tree[lson].l1, tree[lson].l0); swap(tree[lson].r1, tree[lson].r0);
        swap(tree[lson].t1, tree[lson].t0); tree[lson].num = tree[lson].len - tree[lson].num;
        swap(tree[rson].l1, tree[rson].l0); swap(tree[rson].r1, tree[rson].r0);
        swap(tree[rson].t1, tree[rson].t0); tree[rson].num = tree[rson].len - tree[rson].num;
        if (tree[lson].flag2 != -1) tree[lson].flag2 = 1 - tree[lson].flag2;
        else tree[lson].flag1 ^= 1;
        if (tree[rson].flag2 != -1) tree[rson].flag2 = 1 - tree[rson].flag2;
        else tree[rson].flag1 ^= 1;
        tree[rt].flag2 = -1; tree[rt].flag1 = 0;
    }

}
void build(int rt, int l, int r) {
    tree[rt].l = l; tree[rt].r = r; tree[rt].len = r - l + 1; tree[rt].flag1 = 0; tree[rt].flag2 = -1;
    if (l == r) {
        int x;
        scanf("%d", &x);
        tree[rt].num = tree[rt].l1 = tree[rt].r1 = tree[rt].t1 = x;
        tree[rt].l0 = tree[rt].r0 = tree[rt].t0 = 1 - x;
        return;
    }
    int mid = midi(l, r);
    build(lson, l, mid); build(rson, mid + 1, r);
    lift_up(rt);
}
void modify(int rt, int l, int r, int x) {
//    printf("%d\n", rt);
    if (tree[rt].l == l && tree[rt].r == r) {
        if (x == 0 || x == 1) {
            tree[rt].num = tree[rt].l1 = tree[rt].r1 = tree[rt].t1 = x * tree[rt].len;
            tree[rt].l0 = tree[rt].r0 = tree[rt].t0 = (1 - x) * tree[rt].len;
            tree[rt].flag2 = x; tree[rt].flag1 = 0;
        }
        else {
            tree[rt].num = tree[rt].len - tree[rt].num;
            swap(tree[rt].l1, tree[rt].l0); swap(tree[rt].r1, tree[rt].r0);
            swap(tree[rt].t1, tree[rt].t0);
            if (tree[rt].flag2 != -1) tree[rt].flag2 = 1 - tree[rt].flag2;
            else tree[rt].flag1 ^= 1;
        }
        return;
    }
    push_down(rt);
    int mid = midi(tree[rt].l, tree[rt].r);
    if (r <= mid) modify(lson, l, r, x);
    else if (l > mid) modify(rson, l, r, x);
    else { modify(lson, l, mid, x); modify(rson, mid + 1, r, x); }
    lift_up(rt);
}
int query(int rt, int l, int r, int x) {
//    printf("%d\n", rt);
    if (tree[rt].l == l && tree[rt].r == r) {
        if (x == 0) return tree[rt].num;
        return tree[rt].t1;
    }
    push_down(rt);
    int mid = midi(tree[rt].l, tree[rt].r);
    if (r <= mid) return query(lson, l, r, x);
    else if (l > mid) return query(rson, l, r, x);
    else {
        if (x == 0) return query(lson, l, mid, x) + query(rson, mid + 1, r, x);
        else {
            int ans1 = query(lson, l, mid, x), ans2 = query(rson, mid + 1, r, x),
                ans3 = min(mid - l + 1, tree[lson].r1) + min(r - mid, tree[rson].l1);
            return max(max(ans1, ans2), ans3);
        }
    }
}
void work() {
    build(1, 1, n);
    for (int i = 0; i < m; ++i) {
        int op, l, r;
        scanf("%d%d%d", &op, &l, &r); ++l; ++r;
        switch (op) {
            case 0:
            case 1:
            case 2: modify(1, l, r, op);
                    break;
            case 3:
            case 4: printf("%d\n", query(1, l, r, op - 3)); break;
        }
    }
}
int main() {
    freopen("3397.in", "r", stdin);
    int T;
    scanf("%d", &T);
    while (scanf("%d%d", &n, &m) != EOF) work();
    return 0;
}
