#include <bits/stdc++.h>
#define maxn 300010
#define maxl 1000010
using namespace std;
typedef long long LL;
int prime[maxn], d[maxl], cnt[maxl], fa[maxn], n, k, a[maxn];
bool check[maxl];
LL c[maxn];
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
int lowbit(int x) { return x & (-x); }
void add(int p, int x) {
    while (p <= n) c[p] += x, p += lowbit(p);
}
LL query(int x) {
    LL ret = 0;
    while (x) ret += c[x], x -= lowbit(x);
    return ret;
}
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("ans.txt", "w", stdout);
    init();
    scanf("%d%d", &n,&k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        add(i, a[i]);
        fa[i] = i;
    }
    fa[n+1] = n+1;
    for (int i = 1; i <= n; ++i) if (a[i] <= 2) fa[i] = find(i+1);
    while (k--) {
        int t, l, r;
        scanf("%d%d%d", &t,&l,&r);
        if (t==2) printf("%I64d\n", query(r)-query(l-1));
        else for (int i = find(l); i <= r; i = find(i+1)) {
            add(i, d[a[i]] - a[i]);
            if ((a[i] = d[a[i]]) <= 2) fa[i] = find(i+1);
        }
    }
    return 0;
}
