#include <cstdio>
#include <cstring>
#define maxn 22
int v[maxn], c[maxn], dp[maxn][1010], n, k, ans, w;
inline max(int a, int b) { return a > b ? a : b; }
void dfs(int cnt, int tot, int cost, int val) {
    if (tot <= k && cost <= w) {
        ans = max(ans, val);
        if (tot == k) return;
    }
    for (int i = cnt + 1; i <= n; ++i) dfs(i, tot + 1, cost + c[i], val + v[i]);
}
void work() {
    for (int i = 1; i <= n; ++i) scanf("%d%d", &v[i], &c[i]);
    scanf("%d", &w);
    ans = 0;
    for (int i = 1; i <= n; ++i) dfs(i, 1, c[i], v[i]);
    printf("%d\n", ans);
}
int main() {
    int T;
    scanf("%d", &T);
    while (scanf("%d%d", &n, &k) != EOF) work();
    return 0;
}
