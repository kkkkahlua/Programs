#include <bits/stdc++.h>
#define maxn 300010
#define maxl 1000010
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
typedef long long LL;
int prime[maxn], d[maxl], cnt[maxl], n, k, a[maxn];
bool check[maxl];
void init() {
    int tot = 0; d[1] = 1;
    for (int i = 2; i <= 1000000; ++i) {
        if (!check[i]) {
            prime[tot++] = i;
            d[i] = 2, cnt[i] = 1;
        }
        for (int j = 0; j < tot; ++j) {
            if (i * prime[j] > 1000000) break;
            check[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                cnt[i * prime[j]] = cnt[i] + 1;
                d[i * prime[j]] = d[i] / (cnt[i] + 1) * (cnt[i * prime[j]] + 1);
                break;
            }
            cnt[i * prime[j]] = 1;
            d[i * prime[j]] = d[i] << 1;
        }
    }
}
struct node { int l, r; bool flag; LL sum; } tr[maxn<<2];
inline void push_up(int rt) {
    tr[rt].sum = tr[lson].sum + tr[rson].sum;
    tr[rt].flag = tr[lson].flag & tr[rson].flag;
}
inline int midi(int a, int b) { return a + b >> 1; }
void build(int rt, int l, int r) {
    tr[rt].l = l, tr[rt].r = r, tr[rt].flag = 0;
    if (l == r) {
        scanf("%I64d", &tr[rt].sum);
        if (tr[rt].sum <= 2) tr[rt].flag = 1;
        return;
    }
    int mid = midi(l,r);
    build(lson, l, mid); build(rson, mid + 1, r);
    push_up(rt);
}
void modify(int rt, int l, int r) {
    if (tr[rt].flag) return;
    if (tr[rt].l == tr[rt].r) {
        tr[rt].sum = d[tr[rt].sum];
        if (tr[rt].sum <= 2) tr[rt].flag = 1;
        return;
    }
    int mid = midi(tr[rt].l, tr[rt].r);
    if (r <= mid) modify(lson, l, r);
    else if (l > mid) modify(rson, l, r);
    else { modify(lson, l, mid); modify(rson, mid + 1, r); }
    push_up(rt);
}
LL query(int rt, int l, int r) {
    if (tr[rt].l == l && tr[rt].r == r) return tr[rt].sum;
    int mid = midi(tr[rt].l, tr[rt].r);
    if (r <= mid) return query(lson, l, r);
    else if (l > mid) return query(rson, l, r);
    else return query(lson, l, mid) + query(rson, mid + 1, r);
}
int main() {
    scanf("%d%d", &n,&k);
    build(1, 1, n);
    init();
    while (k--) {
        int t, l, r;
        scanf("%d%d%d", &t,&l,&r);
        if (t==2) printf("%I64d\n", query(1, l, r));
        else modify(1, l, r);
    }
    return 0;
}
