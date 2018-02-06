#include <cstdio>
typedef long long LL;
LL phi(int x) {
    LL ret = x;
    for (int i = 2; i * i <= x; ++i) {
        if (!(x % i)) {
            while (!(x % i)) x /= i;
            ret = ret / i * (i - 1);
        }
    }
    if (x > 1) ret = ret / x * (x - 1);
    return ret;
}
void work() {
    int n, m;
    scanf("%d%d", &n, &m);
    LL ans = 0;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i) continue;
        int p = n / i;
        if (i >= m) ans += phi(p);
        if (p >= m && p != i) ans += phi(i);
    }
    printf("%lld\n", ans);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
