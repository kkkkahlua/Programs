#include <cstdio>
#include <algorithm>
#include <iostream>
#define maxn 10010
typedef long long LL;
using namespace std;
LL n, m, a[maxn], b[maxn];
int kas;
LL gcd(LL a, LL b) {
    if (!b) return a;
    return gcd(b, a % b);
}
LL phi(LL x) {
    LL ans = x;
    for (LL i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            ans -= ans / i;
            while (x % i == 0) x /= i;
        }
    }
    if (x > 1) ans -= ans / x;
    return ans;
}
void work() {
    scanf("%lld%lld", &n, &m);
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
        a[i] = gcd(a[i], m);
        if (a[i] == 1) flag = true;
    }
    if (flag) { printf("Case #%d: %lld\n", ++kas, m * (m - 1) >> 1); return; }
    sort(a, a + n);
    n = unique(a, a + n) - a;
    int tot = 0;
    for (LL i = 2; i * i <= m; ++i) {
        if (i * i == m) { b[tot++] = i; break; }
        if (m % i == 0) {
            b[tot++] = i;
            b[tot++] = m / i;
        }
    }
    LL ans = 0;
    for (int i = 0; i < tot; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[j] > b[i]) break;
            if (b[i] % a[j] == 0) {
//                printf("%lld\n", b[i]);
                ans += phi(m / b[i]);
                break;
            }
        }
    }
    ans = ans * m / 2;
    printf("Case #%d: %lld\n", ++kas, ans);
}
int main() {
    freopen("5514.in", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
