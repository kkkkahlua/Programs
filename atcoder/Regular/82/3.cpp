#include <bits/stdc++.h>
#define maxn 100010
typedef long long LL;
const LL mod = 998244353;
LL x[maxn], y[maxn], P[maxn];
int main() {
    LL n;
    scanf("%lld", &n);
    for (int i = 0; i < n; ++i) scanf("%lld%lld", &x[i], &y[i]);
    P[0] = 1;
    for (int i = 1; i <= n; ++i) (P[i] = P[i-1] << 1) %= mod;
    LL ans = P[n] - 1 - n - n*(n-1)/2;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            int cnt = 0;
            for (int k = j+1; k < n; ++k) {
                if ((x[j]-x[i]) * (y[k]-y[j]) == (x[k]-x[j]) * (y[j]-y[i])) ++cnt;
            }
            ((ans -= P[cnt]-1) += mod) %= mod;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
