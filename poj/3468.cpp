#include <cstdio>
#define MAX 100010
typedef long long LL;
struct node {
    int l, r, len;
    LL tag, sum;
}tree[MAX * 4];
void push_down(int rt) {
    if (tree[rt].tag) {
        LL tag = tree[rt].tag;
        tree[rt * 2].tag += tag;
        tree[rt * 2 + 1].tag += tag;
        tree[rt * 2].sum += tag * tree[rt * 2].len;
        tree[rt * 2 + 1].sum += tag * tree[rt * 2 + 1].len;
        tree[rt].tag = 0;
    }
}
void lift_up(int rt) {
    tree[rt].sum = tree[rt * 2].sum + tree[rt * 2 + 1].sum;
}
void build(int rt, int l, int r) {
    tree[rt].l = l; tree[rt].r = r; tree[rt].len = r - l + 1;
    if (l == r) {
        scanf("%lld", &tree[rt].sum);
        return;
    }
    int mid = (l + r) / 2;
    build(rt * 2, l, mid);
    build(rt * 2 + 1, mid + 1, r);
    lift_up(rt);
}
void update(int rt, int l, int r, LL val) {
    if (l == tree[rt].l && r == tree[rt].r) {
        tree[rt].sum += (LL)tree[rt].len * val;
        tree[rt].tag += val;
        return;
    }
    push_down(rt);
    int mid = (tree[rt].l + tree[rt].r) / 2;
    if (r <= mid) update(rt * 2, l, r, val);
    else if (l > mid) update(rt * 2 + 1, l, r, val);
    else {
        update(rt * 2, l, mid, val);
        update(rt * 2 + 1, mid + 1, r, val);
    }
    lift_up(rt);
}
LL query(int rt, int l, int r) {
    if (l == tree[rt].l && r == tree[rt].r) {
        return tree[rt].sum;
    }
    push_down(rt);
    int mid = (tree[rt].l + tree[rt].r) / 2;
    if (r <= mid) return query(rt * 2, l, r);
    else if (l > mid) return query(rt * 2 + 1, l, r);
    else return query(rt * 2, l, mid) + query(rt * 2 + 1, mid + 1, r);
}
int main() {
//    freopen("3468.in", "r", stdin);
//    freopen("3468.out", "w", stdout);
    int n, q;
    scanf("%d%d\n", &n ,&q);
    build(1, 1, n);
    scanf("\n");
    for (int i = 0; i < q; ++i) {
        char ch; int l, r;
        scanf("%c", &ch);
        if (ch == 'Q') {
            scanf("%d%d\n", &l, &r);
            printf("%lld\n", query(1, l, r));
        }
        else {
            int val;
            scanf("%d%d%d\n", &l, &r, &val);
            update(1, l, r, val);
        }
    }
    return 0;
}
