#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 1000000
#define maxk 20
int dp[maxn+10][maxk+1], lp[maxn+10], prime[maxn], tot;
bool vis[maxn+10];
using namespace std;
typedef long long LL;
const LL mod=1e9+7;
void init() {
    F2(i, 2, maxn) {
        if (!vis[i]) {
            prime[tot++] = i;
            lp[i] = i;
        }
        F(j, 0, tot) {
            if (i*prime[j]>maxn) break;
            vis[i*prime[j]] = true;
            lp[i*prime[j]] = prime[j];
            if (i%prime[j]==0) break;
        }
    }
    F2(i, 1, maxk) dp[0][i] = 2;
    F2(i, 1, maxn) {
        dp[i][0] = 1;
        F2(j, 1, maxk) dp[i][j] = (dp[i][j-1] + dp[i-1][j])%mod;
    }
}
LL calc(int n, int r) {
    LL ans=1;
    while (n>1) {
        int pr = lp[n], cnt=0;
        while (n % pr==0) ++cnt, n/=pr;
        (ans *= dp[r][cnt]) %= mod;
    }
    return ans;
}
int main() {
//    freopen("in.txt", "r", stdin);
    init();
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, r;
        scanf("%d%d", &r,&n);
        printf("%I64d\n", calc(n, r));
    }
    return 0;
}
