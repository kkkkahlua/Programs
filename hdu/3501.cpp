#include <cstdio>
typedef long long LL;
const LL mod = 1e9 + 7;
LL n;
LL phi(LL x) {
    LL ret = x;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            ret -= ret / i;
            while (x % i == 0) x /= i;
        }
    }
    if (x > 1) ret -= ret / x;
    return ret;
}
void work() {
    LL tot = n * (n - 1) >> 1;
    LL coprime = phi(n) * n / 2;
    printf("%lld\n", (tot - coprime) % mod);
}
int main() {
    while (scanf("%lld", &n) != EOF && n) work();
    return 0;
}
