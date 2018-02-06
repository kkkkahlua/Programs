#include <cstdio>
typedef long long LL;
const LL mod = 1e9 + 7;
LL n, m;
LL poww(LL a, LL b) {
    LL ret = 1;
    while (b) {
        if (b & 1) { ret *= a; ret %= mod; }
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return ret % mod;
}
void work() {
    scanf("%I64d%I64d", &n, &m);
    LL x = poww(2, n) - 1;
    if (x < 0) x += mod;
    LL add = poww(x, m - 1) * 2 % mod;
    if (n & 1) add += 1;
    add *= poww(3, mod - 2);
    add %= mod;
    printf("%I64d\n", add);
}
int main() {
    freopen("多校联合第二场数据和标程/数据/1006.in", "r", stdin);
    freopen("06.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--) work();
    return 0;
}
