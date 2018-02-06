#include <bits/stdc++.h>
#define maxn 1000000
typedef long long LL;
const LL mod = 1e9 + 7;
bool check[maxn + 10];
int mu[maxn + 10], prime[maxn + 10], n, maxq;
LL g[maxn + 10], sum[maxn + 10], u[maxn + 10];
inline int max(int a, int b) { return a > b ?a : b; }
inline int min(int a, int b) { return a < b ?a : b; }
void Mobius() {
    memset(check, 0, sizeof(check));
    mu[1] = 1;
    int tot = 0;
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
            else {
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
}
void init() {
    for (int j = 1; j <= maxn; ++j) {
        g[j] += 1; g[j + 1] -= 1;
        int lim = ceil(1.0 * maxn / j);
        for (int k = 2; k <= lim; ++k) {
            int w = k * j;
            g[w - j + 1] += k, g[w-j+1] %= mod;
            if (w + 1 <= maxn) g[w + 1] = (g[w+1] + mod - k) % mod;
        }
    }
    for (int i = 1; i <= maxn; ++i) g[i] += g[i - 1], g[i] %= mod;
    for (int i = 1; i <= maxn; ++i) sum[i] = sum[i-1] + g[i], sum[i] %= mod;
    for (int i = 1; i <= maxn; ++i) u[i] = u[i-1] + mu[i];
}
void work() {
    LL ans = 0;
    int le, ri;
    for (int i = 1; i <= n; i = ri + 1) {
        le = i, ri = n / (n / i);
        ans = (ans + (u[ri] - u[le - 1] + mod) % mod * sum[n / i] % mod) % mod;
    }
    printf("%lld\n", ans);
}
int main() {
//    freopen("in.txt", "r", stdin);
    freopen("第八次多校标程和数据/数据/1002.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    Mobius(); init();
//    for (int i = 1; i <= 10; ++i) printf("%lld ", sum[i]); printf("\n");
    while (scanf("%d", &n) != EOF) work();
    return 0;
}
