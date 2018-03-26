#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 1000010
using namespace std;
int a[maxn], b[maxn];
typedef long long LL;
int main() {
    int n,m;
    LL s1=0, s2=0;
    scanf("%d%d",&n,&m);
    F(i, 0, n) scanf("%d", &a[i]);
    F(i, 0, m) scanf("%d", &b[i]);
    int i=0, j=0, tot=-1;
    while (true) {
        if (s1==s2) {
            ++tot;
            if (i==n||j==m) break;
            s1=0; s2=0;
            s1 += a[i++], s2+= b[j++];
        }
        else if (s1<s2) s1 += a[i++];
        else s2 += b[j++];
    }
    printf("%d\n", tot);
    return 0;
}
