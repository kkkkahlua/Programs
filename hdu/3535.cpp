#include <cstdio>
#include <cstring>
struct node {
    int v, w;
}a[3][110][110];
int dp[110][110], dp2[110], tot[3], n, t, num[3][110];
inline max(int a, int b) { return a > b ? a : b; }
void work() {
    memset(tot, 0, sizeof(tot));
    for (int i = 0; i < n; ++i) {
        int x, type;
        scanf("%d%d", &x, &type);
        ++tot[type];
        num[type][tot[type]] = x;
        for (int j = 0; j < x; ++j) {
            scanf("%d%d", &a[type][tot[type]][j].w, &a[type][tot[type]][j].v);
        }
    }
//    printf("%d %d %d\n", tot[0], tot[1], tot[2]);

    memset(dp, -1, sizeof(dp));
    memset(dp[0], 0, sizeof(dp[0]));
    for (int i = 1; i <= tot[0]; ++i) {
        for (int j = 0; j < num[0][i]; ++j) {
            for (int k = t; k >= a[0][i][j].w; --k) {
                if (dp[i][k - a[0][i][j].w] != -1) dp[i][k] = max(dp[i][k], dp[i][k - a[0][i][j].w] + a[0][i][j].v);
                if (dp[i - 1][k - a[0][i][j].w] != -1) dp[i][k] = max(dp[i][k], dp[i - 1][k - a[0][i][j].w] + a[0][i][j].v);
            }
        }
    }
    if (dp[tot[0]][t] == -1) { printf("-1\n"); return; }
//    for (int i = 0; i <= t; ++i) dp2[i] = dp[tot[0]][i];
//    for (int i = 0; i <= t; ++i) printf("%d ", dp2[i]); printf("\n");
    for (int i = 1; i <= tot[1]; ++i) {
        for (int j = t; j >= 0; --j) {
            for (int k = 0; k < num[1][i]; ++k) {
                if (j - a[1][i][k].w < 0) continue;
                dp2[j] = max(dp2[j], dp2[j - a[1][i][k].w] + a[1][i][k].v);
            }
        }
    }
//    for (int i = 0; i <= t; ++i) printf("%d ", dp2[i]); printf("\n");

    for (int i = 1; i <= tot[2]; ++i) {
        for (int j = 0; j < num[2][i]; ++j) {
            for (int k = t; k >= a[2][i][j].w; --k) {
                dp2[k] = max(dp2[k], dp2[k - a[2][i][j].w] + a[2][i][j].v);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= t; ++i) {
        if (dp[tot[0]][i] == -1) continue;
        ans = max(ans, dp[tot[0]][i] + dp2[t - i]);
    }
    printf("%d\n", ans);
}
int main() {
    freopen("3535.in", "r", stdin);
    while (scanf("%d%d", &n, &t) != EOF) work();
    return 0;
}
