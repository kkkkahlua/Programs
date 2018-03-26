#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
int a[20];
typedef long long LL;
int main() {
//    freopen("in.txt", "r", stdin);
    LL n;
    scanf("%lld", &n);
    int cnt = 0, x;
    while (n) {
        a[cnt++] = n%10;
        n /= 10;
    }
    bool flag = false;
    F(i, 0, cnt-1) if (a[i]!=9) { flag=true; break; }
    if (!flag) printf("%d\n", a[cnt-1]+(cnt-1)*9);
    else printf("%d\n", a[cnt-1]-1+(cnt-1)*9);
    return 0;
}
