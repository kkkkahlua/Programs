#include <cstdio>
#include <cstring>
#define lson ((rt) << 1)
#define rson ((rt) << 1 | 1)
#define maxn 100010
int ans[50];
inline int midi(int l, int r) { return (l + r) >> 1; }
struct node {
    int l, r, color;
}tree[maxn * 4];
void build(int rt, int l, int r) {
    tree[rt].l = l; tree[rt].r = r; if (rt != 1) tree[rt].color = 0;
    if (l == r) return;
    int mid = midi(l, r);
    build(lson, l, mid); build(rson, mid + 1, r);
}
void lift_up(int rt) {
    if (tree[lson].color == tree[rson].color) tree[rt].color = tree[lson].color;
}
void push_down(int rt) {
    if (tree[rt].color) {
        tree[lson].color = tree[rson].color = tree[rt].color;
        tree[rt].color = 0;
    }
}
void modify(int rt, int l, int r, int c) {
    if (tree[rt].l == l && tree[rt].r == r) {
        tree[rt].color = c;
        return;
    }
    push_down(rt);
    int mid = midi(tree[rt].l, tree[rt].r);
    if (r <= mid) modify(lson, l, r, c);
    else if (l > mid) modify(rson, l, r, c);
    else { modify(lson, l, mid, c); modify(rson, mid + 1, r, c); }
    lift_up(rt);
}
void query(int rt, int l, int r) {
//    printf("%d %d\n", rt, tree[rt].color);
    if (tree[rt].color) {
        ans[tree[rt].color] = true;
        return;
    }
    int mid = midi(tree[rt].l, tree[rt].r);
    if (r <= mid) query(lson, l, r);
    else if (l > mid) query(rson, l, r);
    else { query(lson, l, mid); query(rson, mid + 1, r); }
}
int main() {
    int n, t, o;
    scanf("%d%d%d", &n, &t, &o);
    tree[1].color = 1;
    build(1, 1, n);
    for (int i = 0; i < o; ++i) {
        char ch;
        scanf("\n%c", &ch);
        int l, r;
        if (ch == 'C') {
            int c;
            scanf("%d%d%d", &l, &r, &c);
            modify(1, l, r, c);
//            for (int i = 1; i <= 3; ++i) printf("%d %d %d\n", tree[i].l, tree[i].r, tree[i].color);
        }
        else {
            memset(ans, 0, sizeof(ans));
            scanf("%d%d", &l, &r);
            query(1, l, r);
            int tot = 0;
            for (int k = 1; k <= t; ++k) if (ans[k]) ++tot;
            printf("%d\n", tot);
        }
    }
    return 0;
}
