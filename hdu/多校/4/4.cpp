#include <bits/stdc++.h>
#define maxn 60010
#define inf 0x3f3f3f3f
#define eps 1e-5
#define lson (rt << 1)
#define rson (rt << 1 | 1)
struct tree {
    int l, r, tag;
    double val;
}tr[maxn * 4];
double v;
int n, pre[maxn], pos[maxn];
inline int midi(int a, int b) { return a + b >> 1; }
inline double min(double a, double b) { return a < b ? a : b; }
void build(int rt, int l, int r, double x) {
    tr[rt].l = l; tr[rt].r = r; tr[rt].val = x * l; tr[rt].tag = 0;
    if (l == r) return;
    int mid = midi(l, r);
    build(lson, l, mid, x); build(rson, mid + 1, r, x);
}
inline void push_up(int rt) {
    tr[rt].val = min(tr[lson].val, tr[rson].val);
}
inline void push_down(int rt) {
    if (tr[rt].tag) {
        tr[lson].tag += tr[rt].tag; tr[lson].val += tr[rt].tag;
        tr[rson].tag += tr[rt].tag; tr[rson].val += tr[rt].tag;
        tr[rt].tag = 0;
    }
}
void modify(int rt, int l, int r, int r0) {
    if (tr[rt].l == l && tr[rt].r == r) {
        tr[rt].tag += 1;
        tr[rt].val += 1;
        return;
    }
    push_down(rt);
    int mid = midi(tr[rt].l, tr[rt].r);
    if (r <= mid) modify(lson, l, r, r0);
    else if (l > mid) modify(rson, l, r, r0);
    else { modify(lson, l, mid, r0); modify(rson, mid + 1, r, r0); }
    push_up(rt);
}
void query(int rt, int r) {
    if (tr[rt].r <= r) { v = min(v, tr[rt].val); return; }
    if (tr[rt].l == tr[rt].r) return;
    push_down(rt);
    int mid = midi(tr[rt].l, tr[rt].r);
    query(lson, r);
    if (r > mid) query(rson, r);
    push_up(rt);
}
bool check(double x) {
//    printf("x : %.3f\n", x);
    build(1, 1, n, x);
    for (int r = 1; r <= n; ++r) {
        modify(1, pre[r] + 1, r, r);
        v = inf;
        query(1, r);
        if (v <= (r + 1) * x) {
//            printf("%d\n", r);
            return true;
        }
    }
    return false;
}
void work() {
    memset(pos, 0, sizeof(pos));
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        pre[i] = pos[x];
        pos[x] = i;
    }
    double l = 0, r = 1.0, mid;
    while (r - l > eps) {
        mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    printf("%.10f\n", mid);
}
int main() {
//    freopen("多校第四场标程和数据/数据/1004.in", "r", stdin);
//    freopen("04.out", "w", stdout);
//    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
