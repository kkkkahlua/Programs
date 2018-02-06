#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 10010
#define lson (rt << 1)
#define rson (rt << 1 | 1)
typedef long long LL;
struct node {
    int l, r, lv, rem;
    LL exp, tag;
}tr[maxn * 4];
int ned[20], n, k, q, kas;
inline LL max(LL a, LL b) { return a > b ? a : b; }
inline int max(int a, int b) { return a > b ? a : b; }
inline int midi(int a, int b) { return (a + b) >> 1; }
inline int min(int a, int b) { return a < b ? a : b; }
void push_up(int rt) {
    tr[rt].exp = max(tr[lson].exp, tr[rson].exp);
    tr[rt].rem = min(tr[lson].rem, tr[rson].rem);
    tr[rt].lv = max(tr[lson].lv, tr[rson].lv);
}
void push_down(int rt) {
    if (tr[rt].tag) {
        tr[lson].exp += (LL)tr[lson].lv * tr[rt].tag;
        tr[rson].exp += (LL)tr[rson].lv * tr[rt].tag;
        tr[lson].rem -= tr[rt].tag; tr[rson].rem -= tr[rt].tag;
        tr[lson].tag += tr[rt].tag; tr[rson].tag += tr[rt].tag;
        tr[rt].tag = 0;
    }
}
void build(int rt, int l, int r) {
    tr[rt].l = l; tr[rt].r = r; tr[rt].exp = 0; tr[rt].tag = 0; tr[rt].lv = 0;
    if (l == r) {
        tr[rt].lv = 1;
        tr[rt].rem = ned[1] / 1;
        return;
    }
    int mid = midi(l, r);
    build(lson, l, mid);
    build(rson, mid + 1, r);
    push_up(rt);
}
void modify(int rt, int l, int r, int exp) {
    if (tr[rt].l == tr[rt].r) {
        tr[rt].exp += (LL)exp * tr[rt].lv;
        while (tr[rt].lv < k && tr[rt].exp >= ned[tr[rt].lv]) ++tr[rt].lv;
        if (tr[rt].lv == k) tr[rt].rem = inf;
        else tr[rt].rem = ceil((double)(ned[tr[rt].lv] - tr[rt].exp) / tr[rt].lv);
        return;
    }
    if (tr[rt].l == l && tr[rt].r == r) {
        if (tr[rt].rem > exp) {
            tr[rt].exp += tr[rt].lv * exp;
            tr[rt].tag += exp;
            tr[rt].rem -= exp;
            return;
        }
        push_down(rt);
        int mid = midi(l, r);
        modify(lson, l, mid, exp);
        modify(rson, mid + 1, r, exp);
        push_up(rt);
        return;
    }
    push_down(rt);
    int mid = midi(tr[rt].l, tr[rt].r);
    if (r <= mid) modify(lson, l, r, exp);
    else if (l > mid) modify(rson, l, r, exp);
    else { modify(lson, l, mid, exp); modify(rson, mid + 1, r, exp); }
    push_up(rt);
    return;
}
LL query(int rt, int l, int r) {
    if (tr[rt].l == l && tr[rt].r == r) return tr[rt].exp;
    push_down(rt);
    int mid = midi(tr[rt].l, tr[rt].r);
    if (r <= mid) return query(lson, l, r);
    else if (l > mid) return query(rson, l, r);
    else return max(query(lson, l, mid), query(rson, mid + 1, r));
}
void work() {
    printf("Case %d:\n", ++kas);
    scanf("%d%d%d", &n, &k, &q);
    for (int i = 1; i < k; ++i) scanf("%d", &ned[i]);
    build(1, 1, n);
    while (q--) {
        char ch;
        scanf("\n%c", &ch);
        int l, r, exp;
        if (ch == 'Q') {
            scanf("%d%d", &l, &r);
            printf("%lld\n", query(1, l, r));
        }
        else {
            scanf("%d%d%d", &l, &r, &exp);
            modify(1, l, r, exp);
        }
//        if (ch == 'W')
//        for (int i = 1; i <= 9; ++i) {
//            printf("%d : %d %d %lld %d %d\n", i, tr[i].l, tr[i].r, tr[i].exp, tr[i].rem, tr[i].lv);
//        }
//        printf("\n");
    }
    printf("\n");
}
int main() {
    freopen("3954.in", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
