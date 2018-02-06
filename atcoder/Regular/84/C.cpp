#include <bits/stdc++.h>
#define maxn 100010
int a[maxn], b[maxn], c[maxn];
using namespace std;
typedef long long LL;
int main() {
//    freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
    sort(a,a+n);
    sort(b,b+n);
    sort(c,c+n);
    LL ans=0;
    for (int i = 0; i < n; ++i) {
        int p1 = lower_bound(a, a+n, b[i]) - a - 1,
            p2 = upper_bound(c, c+n, b[i]) - c;
        ans += 1LL * (p1+1) * (n-p2);
    }
    printf("%lld\n", ans);

    return 0;
}
