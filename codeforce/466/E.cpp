#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 100010
using namespace std;
typedef long long LL;
LL a[maxn], sum[maxn], dp[maxn];
int st[maxn];
int main() {
//    freopen("in.txt", "r", stdin);
    int n, c;
    scanf("%d%d", &n, &c);
    F2(i, 1, n) {
        scanf("%I64d", &a[i]);
        sum[i] = sum[i-1] + a[i];
    }
    if (c==1) { printf("%d\n", 0); return 0; }
    dp[1] = a[1];
    int l=0, r=0; st[r++] = 1;
    F2(i, 2, n) {
        LL minn = dp[i-1]+a[i];
        while (r>l && a[st[r-1]]>=a[i]) --r;
        st[r++] = i;
        if (i-c>=0) {
            while (r>l && st[l]<=i-c) ++l;
            minn = min(minn, dp[i-c]+sum[i]-sum[i-c]-a[st[l]]);
        }
        dp[i] = minn;
    }
    printf("%I64d\n", dp[n]);
    return 0;
}
