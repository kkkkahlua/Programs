#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define inf 0x3f3f3f3f
#define maxn 510
using namespace std;
typedef long long LL;
vector<int> v[maxn];
int dp[maxn][maxn], minn[maxn][maxn];
char s[maxn];
int main() {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    memset(dp, 0x3f, sizeof dp);
    memset(minn, 0x3f, sizeof minn);
    F(i, 0, n) {
        scanf("%s", s);
        F(j, 0, m) if (s[j]=='1') v[i].push_back(j);
        int tot=v[i].size(), lim=min(k, tot);
        if (lim==tot) dp[i][lim] = 0, --lim;
        F2(j, 0, lim) {
            F2(p, 0, j) {
                dp[i][j] = min(dp[i][j], v[i][p+tot-j-1]-v[i][p]+1);
            }
        }
    }
    F2(i, 0, min(k, (int)v[0].size())) minn[0][i] = dp[0][i];
    F(i, 0, n-1) {
        F2(j, 0, k) {
            F2(p, 0, k) {
                if (j+p>k) break;
                minn[i+1][j+p] = min(minn[i+1][j+p], minn[i][j]+dp[i+1][p]);
            }
        }
    }
    int ans=inf;
    F2(i, 0, k) ans = min(ans, minn[n-1][i]);
    printf("%d\n", ans);
    return 0;
}
