#include <bits/stdc++.h>
typedef long long LL;
const LL mod = 1e9 + 7;
LL poww(LL a, LL b) {
    LL ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret % mod;
}
int kas;
LL n, k;
void work() {
    printf("Case #%d: %lld\n", ++kas, poww(n % mod, k));
}
int main() {
    while (scanf("%lld%lld", &n, &k) != EOF) work();
    return 0;
}
