#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 300010
using namespace std;
typedef long long LL;
int ans[maxn];
int main() {
    int n,a,b;
    scanf("%d%d%d", &n,&a,&b);
    int temp=a+b-1, nn=n;
    if (temp>n || n>1LL*a*b) puts("-1");
    else {
        if (a==1) F2(i, 1, n) ans[i]=n-i+1;
        else if (b==1) F2(i, 1, n) ans[i]=i;
        else {
            int x=n-temp,
                grp=x/(a-1),
                rem=x%(a-1);
            dF2(i, a, 1) ans[i]=n--;
            F2(i, 1, grp) {
                int t=(i+1)*a, s=i*a+1;
                dF2(j, t, s) ans[j]=n--;
            }
            int s=(grp+1)*a+1, t=s+rem;
            dF2(i, t, s) ans[i]=n--;
            F2(i, t+1, nn) ans[i]=n--;
            n=nn;
        }
        F2(i, 1, nn) printf("%d ", ans[i]); puts("");
    }
    return 0;
}
