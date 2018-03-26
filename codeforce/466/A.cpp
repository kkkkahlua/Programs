#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
typedef long long LL;
int a[110];
int main() {
//    freopen("in.txt", "r", stdin);
    int n, d;
    scanf("%d%d", &n, &d);
    F(i, 0, n) {
        int x;
        scanf("%d", &x);
        ++a[x];
    }
    F2(i, 1, 100) a[i] += a[i-1];
    int ans = min(a[100]-a[d], a[99-d]);
    F(i, 1, 100-d) {
        int l = i, r = i+d;
        ans = min(ans, a[l-1]+a[100]-a[r]);
    }
    printf("%d\n", ans);
    return 0;
}
