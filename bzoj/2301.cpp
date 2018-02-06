#include <bits/stdc++.h>
#define maxn 50000
typedef long long LL;
using namespace std;
int kas, prime[maxn + 10], mu[maxn + 10], pre[maxn];
bool check[maxn + 10];
void mobius() {
    int tot = 0;
    mu[1] = 1;
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
    for (int i = 1; i <= maxn; ++i) pre[i] = pre[i - 1] + mu[i];
}
LL calc(int c, int d) {
    if (c > d) swap(c, d);
    LL ans = 0;
    int le, ri;
    for (int i = 1; i <= c; i = ri + 1) {
        le = i, ri = min(c / (c / i), d / (d / i));
        ans += 1LL * (pre[ri] - pre[le - 1]) * (c / i) * (d / i);
    }
    return ans;
}
void work() {
    int a, b, c, d, k;
    scanf("%d%d%d%d%d", &a, &c, &b, &d, &k);
    LL tot1 = calc(c / k, d / k), tot2 = calc(c / k, (b-1) / k),
        tot3 = calc((a-1) / k, d / k), tot4 = calc((a-1) / k, (b-1) / k);
    printf("%lld\n", tot1 - tot2 - tot3 + tot4);
}
int main() {
    mobius();
//    for (int i = 1; i <= 20; ++i) printf("%d ", pre[i]); printf("\n");
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
