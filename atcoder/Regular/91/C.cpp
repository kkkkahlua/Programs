#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
typedef long long LL;
int main() {
    LL m,n;
    scanf("%lld%lld",&m,&n);
    if (m>=2&&n>=2) printf("%lld\n", m*n-((m-1+n-1)<<1));
    else {
        if (m>n) swap(m, n);
        if (n==1) puts("1");
        else printf("%lld\n", n-2);
    }
    return 0;
}
