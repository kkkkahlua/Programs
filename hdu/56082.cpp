#include <bits/stdc++.h>
#define maxn 1000000
#define maxm maxn + 10
#include <map>
using namespace std;
typedef long long LL;
const LL mod = 1e9+7;
map<int, LL> sum;
LL inv, g[maxm];
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
    for (int i = 1; i <= maxn; ++i) g[i] = (LL)(i - 1) * (i - 2) % mod;
    for (int i = 1; i <= maxn; ++i) {
        for (int j = i << 1; j <= maxn; j += i) {
            g[j] = (g[j] - g[i] + mod) % mod;
        }
    }
    for (int i = 1; i <= maxn; ++i) (g[i] += g[i - 1]) %= mod;
    inv = poww(3, mod - 2);
}
LL pre(LL x) {
    return x * (x - 1) % mod * (x - 2) % mod * inv % mod;
}
LL g_sum(int x) {
    if (x <= maxn) return g[x];
    if (sum.find(x) != sum.end()) return sum[x];
    int le, ri;
    LL ret = 0;
    for (int i = 2; i <= x; i = ri + 1) {
        le = i, ri = x / (x / i);
        ret = (ret + ((ri - le + 1) * g_sum(x / i) + mod) % mod + mod) % mod;
    }
    return sum[x] = (pre(x) - ret + mod) % mod;
}
void work() {
    LL n;
    scanf("%lld", &n);
    printf("%lld\n", g_sum(n));
}
int main() {
    init();
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
