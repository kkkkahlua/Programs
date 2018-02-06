#include <cstdio>
#include <cmath>
typedef long long LL;
LL n;
LL pow2(LL mul, LL nn) {
    LL ans = 1;
    while (nn) {
        if (nn & 1) ans = (ans * mul) % n;
        mul = (mul * mul) % n;
        nn >>= 1;
    }
    return ans;
}
void work() {
    printf("%lld\n", (pow2(2, n - 1) + 1) % n);
}
int main() {
    while (scanf("%lld", &n) && n != 0) work();
    return 0;
}
