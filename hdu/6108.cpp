#include <bits/stdc++.h>
#define maxn 32000
#define maxm maxn + 10
typedef long long LL;
bool check[maxm];
int prime[maxm], tot;
void init() {
    tot = 0;
    for (int i = 2; i <= maxn; ++i) {
        if (!check[i]) {
            prime[tot++] = i;
        }
        for (int j = 0; j < tot; ++j) {
            if (i * prime[j] > maxn) break;
            check[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}
void work() {
    int n;
    scanf("%d", &n);
    --n;
    LL ans = 1;
    for (int i = 0; i < tot; ++i) {
        if (n == 1) break;
        if (n % prime[i] == 0) {
            int cnt = 1;
            while (n % prime[i] == 0) n /= prime[i], ++cnt;
            ans *= (LL)cnt;
        }
    }
    if (n > 1) ans <<= 1;
    printf("%lld\n", ans);
}
int main() {
    init();
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
