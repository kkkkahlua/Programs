#include <cstdio>
#include <cstring>
#define maxn 10010
int n, t, dp[maxn][110];
inline max(int a, int b) { return a > b ? a : b; }
void work() {
    memset(dp, -1, sizeof(dp));
    memset(dp[0], 0, sizeof(dp[0]));
    for (int i = 1; i <= n; ++i) {
        int m, s;
        scanf("%d%d", &m, &s);
        if (s == 0) {
            for (int j = 0; j < m; ++j) {
                int w, c;
                scanf("%d%d", &w, &c);
                for (int k = t; k >= w; --k) {
                    if (dp[i][k - w] != -1) {
                        dp[i][k] = max(dp[i][k], dp[i][k - w] + c);
                    }
                    if (dp[i - 1][k - w] != -1) {
                        dp[i][k] = max(dp[i][k], dp[i - 1][k - w] + c);
                    }
                }
            }
        }
        else {
            for (int j = 0; j <= t; ++j) dp[i][j] = dp[i - 1][j];

            if (s == 1) {
                for (int j = 0; j < m; ++j) {
                    int w, c;
                    scanf("%d%d", &w, &c);
                    for (int k = t; k >= w; --k) {
                        if (dp[i - 1][k - w] != -1) {
                            dp[i][k] = max(dp[i][k], dp[i - 1][k - w] + c);
                        }
                    }
                }
            }
            else {
                for (int j = 0; j < m; ++j) {
                    int w, c;
                    scanf("%d%d", &w, &c);
                    for (int k = t; k >= w; --k) {
                        if (dp[i][k - w] != -1) {
                            dp[i][k] = max(dp[i][k], dp[i][k - w] + c);
                        }
                    }
                }
            }
        }
    }

    printf("%d\n", dp[n][t]);
}
int main() {
    freopen("3535.in", "r", stdin);
    while (scanf("%d%d", &n, &t) != EOF) work();
    return 0;
}
