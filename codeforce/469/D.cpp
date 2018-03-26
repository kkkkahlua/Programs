#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
typedef long long LL;
LL n; int q;
LL calc(LL x) {
    if (x&1) return (x+1)>>1;
    return calc(n+(x>>1));
}
int main() {
    scanf("%I64d%d", &n,&q);
    while (q--) {
        LL x, ans;
        scanf("%I64d", &x);
        printf("%I64d\n", calc(x));
    }
    return 0;
}
