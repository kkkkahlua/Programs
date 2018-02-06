#include <cstdio>
#include <cstring>
#define maxn 110
int dp[maxn], a[maxn][maxn], n, m;
void work() {
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int w = m; w >= 0; --w) {
            for (int j = 1; j <= m; ++j) {
                if (w - j < 0) break;
                dp[w] = dp[w - j] + a[i][j] > dp[w] ? dp[w - j] + a[i][j] : dp[w];
            }
        }
    }
    printf("%d\n", dp[m]);

}
int main() {
    while (scanf("%d%d", &n, &m) && n != 0 && m != 0) work();
}
