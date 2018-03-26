#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
typedef long long LL;
int main() {
    int l,r,a;
    scanf("%d%d%d", &l,&r,&a);
    if (l-r>=a) printf("%d\n", r+a<<1);
    else if (r-l>=a) printf("%d\n", l+a<<1);
    else {
        int z=l-r;
        if ((z+a)&1) --a;
        int y=(z+a)>>1, x=a-y;
        printf("%d\n", (l+x)*2);
    }
    return 0;
}
