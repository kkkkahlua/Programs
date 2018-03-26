#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 80
#define maxl 1100000
using namespace std;
typedef long long LL;
const int mod = 1e9+7;
int num[maxn][maxn], n, dp[maxn][maxl];
char s[maxn];
void init() {
    F(i, 0, n) {
        int x=0;
        F(j, i, n) {
            num[i][j] = ((x<<=1) += s[j]-'0');
        }
    }
}
int main() {
    scanf("%d%s", &n, s);
    init();
    int lim=(1<<20)-1;
    F2(i, 0, n) {
        dp[i][0] = 1;
        F(j, 0, lim) {
            if (!dp[i][j]) continue;
            F2(k, i+1, n) {
                if (num[i][k-1]>20) break;
                if (!num[i][k-1]) continue;
                (dp[k][j|(1<<num[i][k-1]-1)] += dp[i][j]) %= mod;
            }
        }
    }
    int ans=0;
    F2(i, 0, n) {
        F2(j, 1, 20) (ans += dp[i][(1<<j)-1]) %= mod;
    }
    printf("%d", ans);
    return 0;
}
