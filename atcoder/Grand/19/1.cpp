#include <bits/stdc++.h>
typedef long long LL;
void work() {
}
int main() {
    LL q, h, s, d;
    scanf("%lld%lld%lld%lld", &q, &h, &s, &d);
    if (q * 4 < s) s = q * 4;
    if (h * 2 < s) s = h * 2;
    if (q * 8 < d) d = q * 8;
    if (h * 4 < d) d = h * 4;
    LL ans, n;
    scanf("%lld", &n);
    if (d > 2 * s) {
        ans = n * s;
    }
    else {
        ans = n / 2 * d + n % 2 * s;
    }
    printf("%lld\n", ans);
    return 0;
}
