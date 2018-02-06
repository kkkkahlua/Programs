#include <bits/stdc++.h>
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define maxn 50010
using namespace std;
stack<int> s;
bool brok[maxn];
struct node { int l, r, len, ml, mr, mm; }tr[maxn * 4];
void push_up(int rt) {
    tr[rt].ml = tr[lson].ml; if (tr[lson].ml == tr[lson].len) tr[rt].ml += tr[rson].ml;
    tr[rt].mr = tr[rson].mr; if (tr[rson].mr == tr[rson].len) tr[rt].mr += tr[lson].mr;
    tr[rt].mm = max(tr[lson].mm, max(tr[rson].mm, tr[lson].mr + tr[rson].ml));
}
void build(int rt, int l, int r) {
    tr[rt].l = l, tr[rt].r = r, tr[rt].len = r - l + 1;
    tr[rt].ml = tr[rt].mr = tr[rt].mm = tr[rt].len;
    if (l == r) return;
    int mid = l + r >>1;
    build(lson, l, mid); build(rson, mid + 1, r);
}
void modify(int rt, int x, int w) {
    if (tr[rt].l == tr[rt].r) { tr[rt].ml = tr[rt].mr = tr[rt].mm = w; return; }
    int mid = tr[rt].l + tr[rt].r >> 1;
    if (x <= mid) modify(lson, x, w);
    else modify(rson, x, w);
    push_up(rt);
}
int query(int rt, int x) {
    if (tr[rt].l == tr[rt].r || tr[rt].mm == tr[rt].len || tr[rt].mm == 0) return tr[rt].mm;
    int mid = tr[rt].l + tr[rt].r >> 1;
    if (x <= mid) {
        if (x > tr[lson].r - tr[lson].mr) return query(lson, x) + query(rson, mid + 1);
        else return query(lson, x);
    }
    else {
        if (x < tr[rson].l + tr[rson].ml) return query(rson, x) + query(lson, mid);
        else return query(rson, x);
    }
}
int n, m;
void work() {
    while (!s.empty()) s.pop();
    memset(brok, 0, sizeof brok);
    build(1, 1, n);
    while (m--) {
//        for (int i = 1; i <= 13; ++i) {
//            printf("%d %d %d %d %d\n", tr[i].l, tr[i].r, tr[i].ml, tr[i].mr, tr[i].mm);
//        }
        char c; int x;
        scanf("\n%c", &c);
        if (c == 'D') {
            scanf("%d", &x);
            if (!brok[x]) {
                brok[x] = true;
                modify(1, x, 0);
            }
            s.push(x);
        }
        else if (c == 'R') {
            if (s.empty()) continue;
            int x = s.top();
            if (brok[x]) {
                brok[x] = false;
                modify(1, x, 1);
            }
            s.pop();
        }
        else {
            scanf("%d", &x);
            printf("%d\n", query(1, x));
        }
    }
}
int main() {
    while (scanf("%d%d", &n, &m) != EOF) work();
    return 0;
}
