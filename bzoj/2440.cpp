#include <bits/stdc++.h>
#define maxn 50000
#define maxm maxn + 10
int n, prime[maxm], mu[maxm];
bool check[maxm];
typedef long long LL;
void init() {
    int tot = 0; mu[1] = 1;
    for (int i = 2; i <= maxn; ++i) {
        if (!check[i]) {
            prime[tot++] = i;
            mu[i] = -1;
        }
        for (int j = 0; j < tot; ++j) {
            if (i * prime[j] > maxn) break;
            check[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                break;
            }
            mu[i * prime[j]] = -mu[i];
        }
    }
}
bool ok(LL x) {
    int lim = sqrt(x);
    LL ans = 0;
    for (int i = 1; i <= lim; ++i) {
        ans += mu[i] * x / (i * i);
    }
    return ans >= n;
}
void work() {
    scanf("%d", &n);
    LL l = 1, r = (n << 1), mid;
    while (l < r) {
        mid = l + r >> 1;
        if (ok(mid)) r = mid;
        else l = mid + 1;
    }
    if (ok(l)) printf("%lld\n", l);
    else printf("%lld\n", r);
}
int main() {
    init();
    int T;
    scanf("%d", &T);
    while (T--) work();
//    while (scanf("%d", &n) != EOF) ok(n);
    return 0;
}
