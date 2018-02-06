#include <bits/stdc++.h>
int dp[10][2], a[10], n, m;
int dfs(int p, int pre, bool sta, bool limit) {
    if (p == -1) return 1;
    if (!limit && dp[p][sta] != -1) return dp[p][sta];
    int up = limit ? a[p] : 9, temp = 0;
    for (int i = 0; i <= up; ++i) {
        if (i == 4) continue;
        if (pre == 6 && i == 2) continue;
        temp += dfs(p - 1, i, i == 6, limit && i == a[p]);
    }
    if (!limit) dp[p][sta] = temp;
    return temp;
}
int solve(int x) {
    memset(dp, -1, sizeof(dp));
    int tot = 0;
    while (x) {
        a[tot++] = x % 10;
        x /= 10;
    }
    return dfs(tot - 1, 0, 0, true);
}
void work() {
    printf("%d\n", solve(m) - solve(n - 1));
}
int main() {
    while (scanf("%d%d", &n, &m) != EOF && n + m) work();
    return 0;
}
