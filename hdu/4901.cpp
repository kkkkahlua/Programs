#include <cstdio>
#include <cstring>
#define mod 1000000007
#define maxn 1025
typedef long long LL;
LL dp[maxn][maxn], dp2[maxn][maxn], a[maxn], dp3[maxn][maxn];
int n;
typedef long long LL;
void work() {
    memset(dp, 0, sizeof(dp));
    memset(dp2, 0, sizeof(dp2));
    memset(dp3, 0, sizeof(dp3));
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; ++i) dp[i][a[i]] = 1;
    for (int i = 1; i < n - 1; ++i) {
        LL x = a[i];
        for (int j = 0; j < maxn; ++j) {
            dp[i][j] += dp[i - 1][j]; dp[i][j] %= mod;
            dp[i][j ^ x] += dp[i - 1][j]; dp[i][j ^ x] %= mod;
        }
    }
    for (int i = n - 1; i > 0; --i) dp2[i][a[i]] = dp3[i][a[i]] = 1;
    for (int i = n - 2; i >= 1; --i) {
        LL x = a[i];
        for (int j = 0; j < maxn; ++j) {
            dp2[i][j] += dp2[i + 1][j]; dp2[i][j] %= mod;
            dp2[i][j & x] += dp2[i + 1][j]; dp2[i][j & x] %= mod;
            dp3[i][j & x] += dp2[i + 1][j]; dp3[i][j & x] %= mod;
        }
    }
    LL ans = 0;
    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            ans = ((dp[j][i] * dp3[j + 1][i]) % (LL)mod + ans) % (LL)mod;
        }
    }
    printf("%lld\n", ans);
}
int main() {
    int T;
    scanf("%d", &T);
    while (scanf("%d", &n) != EOF) work();
    return 0;
}
