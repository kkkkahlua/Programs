#include <bits/stdc++.h>
#define maxn 2010
#define mod 998244353
typedef long long LL;
int a[maxn], b[maxn];
LL sum[maxn][maxn][2];
void work() {
    memset(sum, 0, sizeof(sum));
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= m; ++i) scanf("%d", &b[i]);
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        LL cntl = 1, cntg = 0;
        for (int j = 1; j <= m; ++j) {
            sum[i][j][0] = sum[i - 1][j][0]; sum[i][j][1] = sum[i - 1][j][1];
            if (a[i] == b[j]) {
                ans += (cntg + cntl) % mod; ans %= mod;
                sum[i][j][0] += cntl, sum[i][j][1] += cntg; sum[i][j][0] %= mod; sum[i][j][1] %= mod;
//                printf("%d %d %lld %lld\n", i, j, sum[i][j][0], sum[i][j][1]);
            }
            else if (a[i] > b[j]) cntg += sum[i - 1][j][0], cntg %= mod;
            else cntl += sum[i - 1][j][1], cntl %= mod;
        }
    }
    printf("%lld\n", ans);
}
int main() {
    freopen("多校第四场标程和数据/数据/1012.in", "r", stdin);
//    freopen("03.out", "w", stdout);
//    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
