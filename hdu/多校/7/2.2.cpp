#include <bits/stdc++.h>
#define maxn 110
typedef long long LL;
LL sz[maxn], x[maxn], n, k;
LL query(LL n, LL dep) {
//    printf("%lld %lld\n", n, dep);
    if (dep == 2) return n ^ ((n - 1 & 1) ? 1 : 0);
    LL mod = pow(k, dep - 2);
    LL ful1 = (n - sz[dep - 1]) / mod;
    LL ful2 = k - ful1, ret = n ^ ((ful1 & 1) ? x[dep - 1] : 0);
    if ((n - sz[dep - 1]) % mod) {
        --ful2;
        ret ^= ((ful2 & 1) ? x[dep - 2] : 0) ^ query(n - 1 - ful1 * sz[dep - 1] - ful2 * sz[dep - 2], dep - 1);
    }
    else ret ^= ((ful2 & 1) ? x[dep - 2] : 0);
    return ret;
}
void work() {
    scanf("%lld%lld", &n, &k);
    if (k == 1) {
        LL xx = n % 4;
        LL ans;
        switch (xx) {
            case 0: ans = n; break;
            case 1: ans = 1; break;
            case 2: ans = n + 1; break;
            case 3: ans = 0;
        }
        printf("%lld\n", ans);
        return;
    }
    LL cnt = 1, cur = n, h = 1;
    sz[1] = 1, x[1] = 1;
    while (true) {
        cur -= cnt;
        cnt *= k;
        sz[h + 1] = sz[h] * k + 1;
        x[h + 1] = ((k & 1) ? x[h] : 0) ^ sz[h + 1];
        ++h;
        if (cur < cnt) break;
    }
    printf("%lld\n", query(n, h));
}
int main() {
    freopen("多校第七场数据和标程/数据/1002.in", "r", stdin);
    freopen("02.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
