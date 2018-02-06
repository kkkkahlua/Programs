#include <cstdio>
#include <cstring>
#include <climits>
#define maxn 110
int dp[maxn][maxn], exp[maxn], lp[maxn];
int n, m, k, s;
inline min(int a, int b) { return a < b ? a : b; }
void work() {
    for (int i = 0; i < k; ++i) {
        scanf("%d%d", &exp[i], &lp[i]);
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= s; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int kk = 0; kk < k; ++kk) {
                if (j - exp[kk] >= 0 && dp[i - 1][j - exp[kk]] >= 0) {
                    if (dp[i][j] < 0 || dp[i][j] > dp[i - 1][j - exp[kk]] + lp[kk]) {
                        dp[i][j] = dp[i - 1][j - exp[kk]] + lp[kk];
                    }
                }
            }
        }
    }
//    for (int i = 1; i <= s; ++i) {
//        for (int j = 1; j <= n; ++j) {
//            printf("%d ", dp[i][j]);
//        }
//        printf("\n");
//    }
    int ans = INT_MAX;
    for (int i = 1; i <= s; ++i) if (dp[i][n] != -1) ans = min(ans, dp[i][n]);
    if (ans == INT_MAX) printf("-1\n");
    else printf("%d\n", m - ans);
}
int main() {
    while (scanf("%d%d%d%d", &n, &m, &k, &s) != EOF) work();
    return 0;
}
