#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 310
using namespace std;
typedef long long LL;
char ss[maxn];
int dp[maxn][maxn][maxn];
int main() {
    int k;
    scanf("%s%d", ss, &k);
    int n = strlen(ss), ans=0;
    dF2(l, n-1, 0) {
        F(r, l, n) {
            F2(x, 0, k) {
                if (ss[l]==ss[r]) dp[l][r][x] = dp[l+1][r-1][x]+(l==r?1:2);
                else {
                    dp[l][r][x] = max(dp[l+1][r][x], dp[l][r-1][x]);
                    if (x) dp[l][r][x] = max(dp[l][r][x], dp[l+1][r-1][x-1]+2);
                }
            }
        }
    }
    printf("%d\n", dp[0][n-1][k]);
    return 0;
}
