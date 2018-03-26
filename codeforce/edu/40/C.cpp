#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 200010
using namespace std;
typedef long long LL;
int a[maxn];
int main() {
    int n, y;
    scanf("%d", &n);
    F(i, 0, n) scanf("%d", &a[i]);
    F(i, 1, n) {
        y = abs(a[i]-a[i-1]);
        if (y==0) { puts("NO"); return 0; }
        if (y>1) break;
    }
    if (y==1) { puts("YES"); printf("%d %d\n", 1, 1000000000); }
    else {
        F(i, 1, n) {
            if (a[i]-a[i-1]==1) {
                if (a[i-1]%y==0) { puts("NO"); return 0; }
            }
            else if (a[i]-a[i-1]==-1) {
                if (a[i]%y==0) { puts("NO"); return 0; }
            }
            else if (abs(a[i]-a[i-1])!=y) { puts("NO"); return 0; }
        }
        puts("YES");
        printf("%d %d\n", 1000000000, y);
    }
    return 0;
}
