#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;
int a[100010], mnl[100010], mnr[100010];
int main() {
//    freopen("in.txt", "r", stdin);
    int n, m, x, mn = inf, mx = -inf;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    if (m==1) printf("%d\n", mn);
    else if (m==2) {
        int ans=-inf;
        if (a[0]!=mx && a[n-1]!=mx) {
            mnl[0] = a[0]; for (int i = 1; i < n; ++i) mnl[i] = min(mnl[i-1], a[i]);
            mnr[n-1] = a[n-1]; for (int i = n-2; i >= 0; --i) mnr[i] = min(mnr[i+1], a[i]);
            for (int i = 1; i < n; ++i) {
                ans = max(ans, max(mnl[i-1], mnr[i]));
            }
        }
        else ans = mx;
        printf("%d\n", ans);
    }
    else printf("%d\n", mx);
    return 0;
}
