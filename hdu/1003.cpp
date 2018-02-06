#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
int dp[maxn], p[maxn], kas;
typedef long long LL;
void work() {
    int n;
    scanf("%d", &n);
    dp[0] = 0, p[0] = 1;
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        if (dp[i-1] >= 0) dp[i] = dp[i-1] + x, p[i] = p[i-1];
        else dp[i] = x, p[i] = i;
    }
    int ans = 1;
    for (int i = 2; i <= n; ++i) {
        if (dp[i] > dp[ans]) ans = i;
    }
    printf("Case %d:\n%d %d %d\n", ++kas, dp[ans], p[ans], ans);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        work();
        if (T) puts("");
    }
    return 0;
}
