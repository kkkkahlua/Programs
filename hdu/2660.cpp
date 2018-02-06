#include <cstdio>
#include <cstring>
#define maxn 22
int v[maxn], c[maxn], dp[maxn][1010], n, k;
inline max(int a, int b) { return a > b ? a : b; }
void work() {
    for (int i = 1; i <= n; ++i) scanf("%d%d", &v[i], &c[i]);
    int w;
    scanf("%d", &w);
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
        for (int j = k; j >= 1; --j) {
            for (int p = w; p >= c[i]; --p) {
                dp[j][p] = max(dp[j][p], dp[j - 1][p - c[i]] + v[i]);
            }
        }
    }
    printf("%d\n", dp[k][w]);
}
int main() {
    int T;
    scanf("%d", &T);
    while (scanf("%d%d", &n, &k) != EOF) work();
    return 0;
}
