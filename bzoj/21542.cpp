#include <bits/stdc++.h>
#define maxn 10000000
#define maxm maxn + 10
typedef long long LL;
using namespace std;
const LL mod = 20101009;
int kas, prime[maxm], pre1[maxm];
LL sum[maxm], h[maxm];
bool check[maxm];
int n, m;
void init() {
    int tot = 0;
    h[1] = 1;
    for (LL i = 2; i <= n; ++i) {
        if (!check[i]) {
            prime[tot++] = i;
            h[i] = (i - i * i + mod) % mod;
        }
        for (int j = 0; j < tot; ++j) {
            if (i * prime[j] > n) break;
            check[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                h[i * prime[j]] = h[i] * prime[j] % mod;
                break;
            }
            h[i * prime[j]] = h[i] * h[prime[j]] % mod;
        }
    }
    for (LL i = 1; i <= n; ++i) {
        pre1[i] = (pre1[i - 1] + i) % mod;
        sum[i] = (sum[i - 1] + h[i] + mod) % mod;
    }
}
void work() {
    int le, ri, lim = min(n, m);
    LL ans = 0;
    for (int i = 1; i <= lim; i = ri + 1) {
//        printf("%d\n", i);
        le = i, ri = min(n / (n / i), m / (m / i));
        ans = (ans + (sum[ri] - sum[le - 1]) % mod * pre1[n / i] % mod * pre1[m / i] % mod) % mod;
    }
    while (ans < 0) ans += mod;
    printf("%lld\n", ans);
}
int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    if (n < m) swap(n, m);
    init();
    work();
//    for (int i = 0; i <= 10; ++i) printf("%d ", pre2[i]);
//    while (scanf("%d%d", &n, &m) != EOF) work();
    return 0;
}
