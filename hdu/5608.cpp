#include <bits/stdc++.h>
#define maxn 10000000
#define maxm maxn + 10
#include <map>
using namespace std;
typedef long long LL;
const LL mod = 1e9+7;
map<int, LL> sum;
int mu[maxm], prime[maxm];
bool check[maxm];
LL inv;
LL poww(LL a, LL b) {
    LL ret = 1;
    while (b) {
        if (b & 1) (ret *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return ret;
}
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
    for (int i = 1; i <= maxn; ++i) mu[i] += mu[i - 1];
    inv = poww(3, mod - 2);
}
LL mu_sum(int x) {
    if (x <= maxn) return (LL)mu[x];
    if (sum.find(x) != sum.end()) return sum[x];
    int le, ri;
    LL ret = 0;
    for (int i = 2; i <= x; i = ri + 1) {
        le = i, ri = x / (x / i);
        ret = (ret + ((ri - le + 1) * mu_sum(x / i) + mod) % mod + mod) % mod;
    }
    return sum[x] = (1 + mod - ret) % mod;
}
LL pre(LL x) {
    return x * (x - 1) % mod * (x - 2) % mod * inv % mod;
}
void work() {
    LL n;
    scanf("%lld", &n);
    LL ans = 0, le, ri;
    for (LL i = 1; i <= n; i = ri + 1) {
        le = i, ri = n / (n / i);
        ans = (ans + (mu_sum(ri) - mu_sum(le - 1) + mod) % mod * pre(n / i) % mod + mod) % mod;
    }
    printf("%lld\n", ans);
}
int main() {
    init();
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
