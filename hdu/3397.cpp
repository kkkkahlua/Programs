#include <cstdio>
#include <algorithm>
#define MAX 100010
using namespace std;
struct node {
    int id, l, r, num, l1, r1, l0, r0, max, tag = -1;
}tree[MAX * 4];
int a[MAX], n, m;
int tot = 0;
void build(int id, int l, int r) {
    printf("%d %d %d\n", id, l, r);

    if (l == r) {
        tree[id].l = l; tree[id].r = r;
        if (a[tot++] == 1) {
            tree[id].num = 1;
            tree[id].l1 = tree[id].r1 = tree[id].max = 1;
        }
        else {
            tree[id].l0 = tree[id].r0 = 1;
        }
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    tree[id].num = tree[id * 2].num + tree[id * 2 + 1].num;
    int max1 = tree[id * 2].r1 + tree[id * 2 + 1].l1,
        max2 = tree[id * 2].max, max3 = tree[id * 2 + 1].max;
    tree[id].max = max(max(max1, max2), max3);
    tree[id].l1 = tree[id * 2].l1; tree[id].r1 = tree[id * 2 + 1].r1;
    if (tree[id * 2].l1 == tree[id * 2].r - tree[id * 2].l + 1) tree[id].l1 = tree[id * 2].l1 + tree[id * 2 + 1].l1;
    if (tree[id * 2 + 1].r1 == tree[id * 2 + 1].r - tree[id * 2 + 1].l + 1) tree[id].r1 = tree[id * 2 + 1].r1 + tree[id * 2].r1;
    tree[id].l0 = tree[id * 2].l0; tree[id].r0 = tree[id * 2 + 1].r0;
    if (tree[id * 2].l0 == tree[id * 2].r - tree[id * 2].l + 1) tree[id].l0 = tree[id * 2].l0 + tree[id * 2 + 1].l0;
    if (tree[id * 2 + 1].r0 == tree[id * 2 + 1].r - tree[id * 2 + 1].l + 1) tree[id].r0 = tree[id * 2 + 1].r0 + tree[id * 2].r0;
}
void change(int id, int tag) {
    if (tree[id].tag == -1) tree[id].tag = tag;
    else if (tag == 0) tree[id].tag = 0;
    else if (tag == 1) tree[id].tag = 1;
    else if (tag == 2) {
        if (tree[id].tag != 2) tree[id].tag = 1 - tree[id].tag;
        else tree[id].tag = -1;
    }
}
void modify(int id, int l, int r, int left, int right, int tag) {
    if (l == left && r == right) {
        change(id, tag);
        printf("%d %d %d\n", l, r, tree[id].tag);
        return;
    }
    int mid = (l + r) / 2;
    if (right <= mid) modify(id * 2, l, mid, left, right, tag);
    else if (left > mid) modify(id * 2 + 1, mid + 1, r, left, right, tag);
    else {
        modify(id * 2, l, mid, left, mid, tag);
        modify(id * 2 + 1, mid + 1, r, mid + 1, right, tag);
    }
}
int query1(int id, int l, int r, int left, int right) {
    if (l == left && r == right) {
        printf("%d %d %d\n", l, r, tree[id].tag);
        if (tree[id].tag == 0) return 0;
        else if (tree[id].tag == 1) return l - r + 1;
        else if (tree[id].tag == 2) return l - r + 1 - tree[id].num;
        else return tree[id].num;
    }
    int mid = (l + r) / 2;
    change(id * 2, tree[id].tag);
    change(id * 2 + 1, tree[id].tag);
    if (right <= mid) return query1(id * 2, l, mid, left, right);
    else if (left > mid) return query1(id * 2 + 1, mid + 1, r, left, right);
    else return query1(id * 2, l, mid, left, mid) + query1(id * 2 + 1, mid + 1, r, mid + 1, right);
}
//int query(int id, int l, int r, int t) {
//    if (l == r) {
//
//    }
//}
void work() {
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    build(1, 1, n);
    for (int i = 0; i < m; ++i) {
        int id, le, ri;
        scanf("%d%d%d", &id, &le, &ri);
        ++le; ++ri;
        switch (id) {
            case 0: modify(1, 1, n, le, ri, 0); break;
            case 1: modify(1, 1, n, le, ri, 1); break;
            case 2: modify(1, 1, n, le, ri, 2); break;
            case 3: printf("%d\n", query1(1, 1, n, le, ri)); break;
//            case 4: printf("%d\n", query(1, 1, n, 4));
        }
    }
}
int main() {
    freopen("3397.in", "r", stdin);
//    freopen("3397.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (scanf("%d%d", &n, &m) != EOF) work();
    return 0;
}
