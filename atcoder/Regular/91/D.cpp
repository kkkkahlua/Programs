#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
typedef long long LL;
int main() {
    int n,k;LL ans=0;
    scanf("%d%d",&n,&k);
    if (!k) ans=1LL*n*n;
    else {
        F2(mod, k+1, n) {
            int x=n/mod;
            ans += 1LL*x*(mod-1-k+1);
            int temp=n%mod;
            if (temp>=k) ans += temp-k+1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
