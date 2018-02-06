#include <bits/stdc++.h>
#define maxn 10000000
#define maxm maxn + 10
typedef long long LL;
using namespace std;
const LL mod = 20101009;
int kas, prime[maxm], mu[maxm];
LL pre1[maxm], pre2[maxm];
bool check[maxm];
int n, m;
void mobius() {
    int tot = 0;
    mu[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (!check[i]) {
            prime[tot++] = i;
            mu[i] = -1;
        }
        for (int j = 0; j < tot; ++j) {
            if (i * prime[j] > n) break;
            check[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                break;
            }
            mu[i * prime[j]] = -mu[i];
        }
    }
    for (LL i = 1; i <= n; ++i) {
        pre1[i] = (pre1[i - 1] + i) % mod;
        pre2[i] = (pre2[i - 1] + i * i % mod * mu[i] % mod + mod) % mod;
    }
}
LL calc(int a, int b) {
    int le, ri, lim = min(a, b);
    LL ret = 0;
    for (int i = 1; i <= lim; i = ri + 1) {
        le = i, ri = min(a / (a / i), b / (b / i));
        ret = (ret + (pre2[ri] - pre2[le - 1] + mod) % mod * pre1[a / i] % mod * pre1[b / i] % mod) % mod;
    }
    return ret;
}
void work() {
    int le, ri, lim = min(n, m);
    LL ans = 0;
    for (int i = 1; i <= lim; i = ri + 1) {
        le = i, ri = min(n / (n / i), m / (m / i));
        ans = (ans + (pre1[ri] - pre1[le - 1]) % mod * calc(n / i, m / i) % mod) % mod;
    }
    while (ans < 0) ans += mod;
    printf("%lld\n", ans);
}
int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    if (n < m) swap(n, m);
    mobius();
    work();
//    for (int i = 0; i <= 10; ++i) printf("%d ", pre2[i]);
//    while (scanf("%d%d", &n, &m) != EOF) work();
    return 0;
}
