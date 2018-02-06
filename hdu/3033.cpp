#include <cstdio>
#include <cstring>
#define maxn 110
int tot[15], cost[15][maxn], val[15][maxn], dp[15][10010], n, m, k;
inline max(int a, int b) { return a > b ? a : b; }
void work() {
    memset(dp, -1, sizeof(dp));
    memset(dp[0], 0, sizeof(dp[0]));
    memset(tot, 0, sizeof(tot));
    for (int i = 0; i < n; ++i) {
        int id, c, v;
        scanf("%d%d%d", &id, &c, &v);
        cost[id][tot[id]] = c;
        val[id][tot[id]++] = v;
    }
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < tot[i]; ++j) {
            for (int p = m; p >= cost[i][j]; --p) {
                if (dp[i][p - cost[i][j]] != -1) dp[i][p] = max(dp[i][p], dp[i][p - cost[i][j]] + val[i][j]);
                if (dp[i - 1][p - cost[i][j]] != -1) dp[i][p] = max(dp[i][p], dp[i - 1][p - cost[i][j]] + val[i][j]);
            }
        }
    }
    if (dp[k][m] == -1) printf("Impossible\n");
    else printf("%d\n", dp[k][m]);
}
int main() {
    while (scanf("%d%d%d", &n, &m, &k) != EOF) work();
    return 0;
}
