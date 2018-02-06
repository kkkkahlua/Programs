#include <cstdio>
#define lson ((rt) << 1)
#define rson ((rt) << 1 | 1)
#define maxn 100010
inline midi(int l, int r) { return (l + r) >> 1; }
int n;
struct node {
    int l, r, val, tag;
}tree[maxn * 4];
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
void lift_up(int rt) {
    if (tree[lson].val == tree[rson].val) tree[rt].val = tree[lson].val;
}
void build(int rt, int l, int r) {
    tree[rt].l = l; tree[rt].r = r; tree[rt].val = -1;
    if (l == r) {
        scanf("%d", &tree[rt].val);
        return;
    }
    int mid = midi(l, r);
    build(lson, l, mid); build(rson, mid + 1, r);
    lift_up(rt);
}
void push_down(int rt) {
    if (tree[rt].val != -1) {
        tree[lson].val = tree[rson].val = tree[rt].val;
        tree[rt].val = -1;
    }
}
void modify1(int rt, int l, int r, int x) {
    if (tree[rt].l == l && tree[rt].r == r) {
        tree[rt].val = x;
        return;
    }
    push_down(rt);
    int mid = midi(tree[rt].l, tree[rt].r);
    if (r <= mid) modify1(lson, l, r, x);
    else if (l > mid) modify1(rson, l, r, x);
    else { modify1(lson, l, mid, x); modify1(rson, mid + 1, r, x); }
    lift_up(rt);
}
void modify2(int rt, int l, int r, int x) {
//    printf("%d %d %d\n", rt, l, r);
    if (tree[rt].l == l && tree[rt].r == r && tree[rt].val > -1) {
        if (tree[rt].val > x) tree[rt].val = gcd(tree[rt].val, x);
        return;
    }
    push_down(rt);
    int mid = midi(tree[rt].l, tree[rt].r);
    if (r <= mid) modify2(lson, l, r, x);
    else if (l > mid) modify2(rson, l, r, x);
    else { modify2(lson, l, mid, x); modify2(rson, mid + 1, r, x); }
    lift_up(rt);
}
void print(int rt, int l, int r) {
//    printf("%d %d %d\n", rt, l, r);
    if (tree[rt].val > -1) {
        for (int i = l; i <= r; ++i) printf("%d ", tree[rt].val);
        return;
    }
    int mid = midi(tree[rt].l, tree[rt].r);
    print(lson, l, mid); print(rson, mid + 1, r);
}
void work() {
    build(1, 1, n);
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int t, l, r, x;
        scanf("%d%d%d%d", &t, &l, &r, &x);
        if (t == 1) modify1(1, l, r, x);
        else modify2(1, l, r, x);
    }

    print(1, 1, n);
    printf("\n");
}
int main() {
//    freopen("4902.in", "r", stdin);
//    freopen("4902.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (scanf("%d", &n) != EOF) work();
    return 0;
}
