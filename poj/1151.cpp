#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#define maxn 210
#define lson (rt<<1)
#define rson (lson|1)
using namespace std;
typedef long long LL;
struct node {
    int l, r; double len, sum, c;
}tr[maxn * 4];
struct Seg {
    double x1, x2, y; int t;
    Seg(double _x1=0, double _x2=0, double _y=0, int _t=0) : x1(_x1), x2(_x2), y(_y), t(_t) {}
    bool operator < (const Seg& s) const { return y < s.y; }
}seg[maxn];
int n, m;
double q[maxn];
void build(int rt, int l, int r) {
    tr[rt].l = l, tr[rt].r = r; tr[rt].c = 0;
    if (l == r) { tr[rt].len = q[l] - q[l-1]; return; }
    int mid = l+r >> 1;
    build(lson, l, mid), build(rson, mid+1, r);
    tr[rt].len = tr[lson].len + tr[rson].len;
}
void push_up(int rt) {
    if (tr[rt].c) tr[rt].sum = tr[rt].len;
    else tr[rt].sum = tr[lson].sum + tr[rson].sum;
}
void modify(int rt, int l, int r, int d) {
    if (tr[rt].l == l && tr[rt].r == r) {
        tr[rt].c += d;
        push_up(rt);
        return;
    }
    int mid = tr[rt].l + tr[rt].r >> 1;
    if (r <= mid) modify(lson, l, r, d);
    else if (l > mid) modify(rson, l, r, d);
    else modify(lson, l, mid, d), modify(rson, mid+1, r, d);
    push_up(rt);
}
int kas;
void work() {
    memset(tr, 0, sizeof tr);
    double x1, y1, x2, y2;
    for (int i = 0; i < n; ++i) {
        scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
        seg[i<<1] = Seg(x1, x2, y1, 1);
        seg[i<<1|1] = Seg(x1, x2, y2, -1);
        q[i<<1] = x1, q[i<<1|1] = x2;
    }
    n <<= 1;
    sort(q, q+n);
    m = unique(q, q+n) - q;
    build(1, 1, m-1);
    sort(seg, seg+n);

    double ans = 0;
    for (int i = 0; i < n-1; ++i) {
        int l = lower_bound(q, q+m, seg[i].x1) - q + 1, r = lower_bound(q, q+m, seg[i].x2) - q;
        modify(1, l, r, seg[i].t);
        ans += tr[1].sum * (seg[i+1].y - seg[i].y);
    }
    printf("Test case #%d\n", ++kas);
    printf("Total explored area: %.2f\n\n", ans);
}
int main() {
    freopen("in.txt", "r", stdin);
    while (scanf("%d", &n) != EOF && n) work();
    return 0;
}
