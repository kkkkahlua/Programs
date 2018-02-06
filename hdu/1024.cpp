#include <bits/stdc++.h>
#define maxn 1000010
#define inf 0x3f3f3f3f
int a[maxn], dp[2][maxn], n, m;
using namespace std;
typedef long long LL;
void work() {
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), a[i] += a[i-1];
    m <<= 1;
    for (int i = 0; i < maxn; ++i) dp[0][i] = -inf;
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i&1][0] = max(dp[(i-1)&1][0], -a[i]);
        for (int j = 1; j < m; ++j) {
            if (j&1) dp[i&1][j] = max(dp[(i-1)&1][j-1]+a[i], dp[(i-1)&1][j]);
            else dp[i&1][j] = max(dp[i&1][j-1]-a[i], dp[(i-1)&1][j]);
        }
    }
    printf("%d\n", dp[n&1][m-1]);
}
int main() {
    while (scanf("%d%d", &m, &n) != EOF) work();
    return 0;
}
