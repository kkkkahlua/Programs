#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
typedef long long LL;
int main() {
//    freopen("in.txt", "r", stdin);
    LL n,k,a,b;
    scanf("%I64d%I64d%I64d%I64d",&n,&k,&a,&b);
    LL ans = 0;
    bool flag = false;
    while (n!=1) {
        if (n%k) {
            ans += n%k*a;
            n = n/k*k;
        }
        if (n/k*(k-1)*a <= b) {
            ans += (n-1)*a;
            break;
        }
        ans += b;
        n /= k;
    }
    printf("%I64d\n", ans);
    return 0;
}
