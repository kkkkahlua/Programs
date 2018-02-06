#include <bits/stdc++.h>
#define maxn 110
using namespace std;
int a[3][maxn], dp[3][maxn];
typedef long long LL;
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= 2; ++i) {
        for (int j = 1; j <= n; ++j) scanf("%d", &a[i][j]);
    }
    for (int i = 1; i <= n; ++i) dp[1][i] = dp[1][i-1] + a[1][i];
    for (int i = 1; i <= 2; ++i) dp[i][1] = dp[i-1][1] + a[i][1];
    for (int j = 2; j <= n; ++j) {
        dp[2][j] = max(dp[1][j], dp[2][j-1]) + a[2][j];
    }
    printf("%d\n", dp[2][n]);
    return 0;
}
