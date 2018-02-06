#include <bits/stdc++.h>
#define maxn 100010
typedef long long LL;
LL a[maxn], c[maxn];
int n, q, fa[maxn];
inline int lowbit(int x) { return x & (-x); }
inline LL query(int x) { LL ret = 0; while (x) ret += c[x], x -= lowbit(x); return ret; }
inline void modify(int x, LL y) { while (x <= n) c[x] += y, x += lowbit(x); }
inline int find(int x) { return fa[x] == x ? x : (fa[x] = find(fa[x])); }
void work() {
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        modify(i, a[i]);
        fa[i] = i;
    }
    fa[n+1] = n + 1;
    for (int i = 1; i <= n; ++i) if (fa[i] <= 1) fa[i] = find(i);
    scanf("%d", &q);
    while (q--) {
        int x, l, r;
        scanf("%d%d%d",&x,&l,&r);
        if (x == 1) printf("%lld\n", query(r) - query(l - 1));
        else for (int i = find(l); i <= r; i = find(i + 1)) {
            modify(i, (LL)sqrt(a[i])-a[i]);
            if ((a[i] = (LL)sqrt(a[i])) <= 1) fa[i] = find(i + 1);
        }
    }
}
int main() {
    while (scanf("%d", &n) != EOF) work();
    return 0;
}
