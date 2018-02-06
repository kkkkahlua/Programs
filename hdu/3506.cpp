#include <cstdio>
#include <cstring>
#define maxn 2010
typedef long long LL;
LL dp[maxn][maxn], sum[maxn];
int a[maxn], n;
LL min(LL a, LL b) { return a < b ? a : b; }
void work() {
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        a[n + i] = a[i];
    }
    sum[1] = a[1];
    for (int i = 1; i <= (n << 1); ++i) printf("%d ", a[i]); printf("\n");
    for (int i = 2; i <= (n << 1); ++i) sum[i] = sum[i - 1] + a[i];
    for (int k = 2; k <= n; ++k) {
        for (int i = 1; i <= 2 * n; ++i) {
            int j = i + k - 1;
            if (j > 2 * n) break;
            dp[i][j] = dp[i][i] + dp[i + 1][j];
            for (int p = i + 1; p < j; ++p) {
                dp[i][j] = min(dp[i][j], dp[i][p] + dp[p + 1][j]);
            }
            dp[i][j] += sum[j] - sum[i - 1];
        }
    }
    LL ans = dp[1][n];
//    for (int i = 1; i <= 2 * n; ++i) {
//        for (int j = 1; j <= 2 * n; ++j) {
//            printf("%lld ", dp[i][j]);
//        }
//        printf("\n");
//    }
    for (int i = 1; i < n; ++i) ans = min(ans, dp[i][i + n - 1]);
    printf("%lld\n", ans);
}
int main() {
    while (scanf("%d", &n) != EOF) work();
    return 0;
}
