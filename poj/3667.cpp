#include <cstdio>
#include <iostream>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define maxn 50010
using namespace std;
struct node {
    int l, r, mx, ml, mr, p, flag, len;
}tr[maxn * 4];
void build(int rt, int l, int r) {
    tr[rt].l = l, tr[rt].r = r, tr[rt].len = tr[rt].ml = tr[rt].mr = tr[rt].mx = r-l+1;
    tr[rt].flag = -1;
    if (l == r) return;
    int mid = l + r >> 1;
    build(lson, l, mid); build(rson, mid+1, r);
}
void push_down(int rt) {
    if (tr[rt].flag != -1) {
        tr[lson].flag = tr[rson].flag = tr[rt].flag;
        tr[lson].ml = tr[lson].mr = tr[lson].mx = tr[lson].flag * tr[lson].len;
        tr[rson].ml = tr[rson].mr = tr[rson].mx = tr[rson].flag * tr[rson].len;
        tr[rt].flag = -1;
    }
}
void push_up(int rt) {
    tr[rt].ml = tr[lson].ml; if (tr[lson].ml == tr[lson].len) tr[rt].ml += tr[rson].ml;
    tr[rt].mr = tr[rson].mr; if (tr[rson].mr == tr[rson].len) tr[rt].mr += tr[lson].mr;
    tr[rt].mx = max(max(tr[lson].mx, tr[rson].mx), tr[lson].mr+tr[rson].ml);
}
int query(int rt, int len) {
    if (tr[rt].l == tr[rt].r && tr[rt].mx == len) return tr[rt].l;
    push_down(rt);
    if (tr[lson].mx >= len) return query(lson, len);
    else if (tr[lson].mr+tr[rson].ml >= len) return tr[lson].r-tr[lson].mr+1;
    else if (tr[rson].mx >= len) return query(rson, len);
    else return 0;
}
void modify(int rt, int l, int r, int x) {
    if (tr[rt].l == l && tr[rt].r == r) {
        tr[rt].ml = tr[rt].mr = tr[rt].mx = x * tr[rt].len;
        tr[rt].p = x ? tr[rt].l : 0;
        tr[rt].flag = x;
        return;
    }
    push_down(rt);
    int mid = tr[rt].l+tr[rt].r>>1;
    if (r <= mid) modify(lson, l, r, x);
    else if (l > mid) modify(rson, l, r, x);
    else { modify(lson, l, mid, x); modify(rson, mid+1, r, x); }
    push_up(rt);
}
int n, m;
void work() {
    build(1, 1, n);
    while (m--) {
        int x, d, p, len;
        scanf("%d%d", &x, &d);
        if (x == 1) {
            int p = query(1, d);
            if (p) modify(1, p, d+p-1, 0);
            printf("%d\n", p);
        }
        else {
            scanf("%d", &len);
            modify(1, d, min(d+len-1, n), 1);
        }
    }
}
int main() {
//    freopen("in.txt", "r", stdin);
    while (scanf("%d%d", &n, &m) != EOF) work();
    return 0;
}
