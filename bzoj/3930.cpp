#include <bits/stdc++.h>
#include <map>
#define maxn 10000010
#define maxm maxn + 10
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long LL;
const LL mod = 1e9+7;
map<LL, LL> sum;
int prime[maxm], mu[maxm];
bool check[maxm];
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
}
LL mu_sum(LL x) {
    if (x <= maxn) return mu[x];
    if (sum.find(x) != sum.end()) return sum[x];
    LL le, ri, ret = 0;
    for (LL i = 2; i <= x; i = ri + 1) {
        le = i, ri = x / (x / i);
        ret = (ret + (ri - le + 1) * mu_sum(x / i) + mod) % mod;
    }
    return sum[x] = (1 - ret + mod) % mod;
}
LL poww(LL a, LL b) {
    LL ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}
LL n, k, l, h;
LL F(LL d) { return poww(h / d - (l-1) / d, n); }
void work() {
    LL hi = h / k;
    LL ans = 0, le, ri;
    for (LL i = 1; i <= hi; i = ri + 1) {
        LL temp = i * k;
        le = i, ri = min(h / (h / temp), (l-1) / temp ? (l-1) / ((l-1) / temp) : inf) / k;
        ans = (ans + mod + (mu_sum(ri) - mu_sum(le - 1) + mod) % mod * F(temp) % mod) % mod;
    }
    ans = (ans + mod) % mod;
    printf("%lld\n", ans);
}
int main() {
    freopen("in.txt", "r", stdin);
    freopen("3930.out", "w", stdout);
    init();
    while (scanf("%lld%lld%lld%lld", &n, &k, &l, &h) != EOF) work();
    return 0;
}
