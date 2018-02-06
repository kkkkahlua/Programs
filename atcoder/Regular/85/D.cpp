#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;
int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d%d%d", &n, &z, &w);
    int mx = 0, mn = inf;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        mx = max(mx, a[i]), mn = min(mn, a[i]);
    }
    int ans = max(abs(mx - w), abs(mn - w));

    int beg = 1;
    sucl[n] = such[n] = {a[n], n};
    for (int i = n-1; i > 0; --i) {
        if (sucl[i+1].val < a[i]) sucl[i] = sucl[i+1];
        else sucl[i] = {a[i], i};
    }
    while (true) {
        prel[beg] = preh[beg] = {a[beg], beg};
        for (int i = beg+1; i <= n; ++i) {
            if (prel[i-1].val < a[i]) prel[i] = prel[i-1];
            else prel[i] = {a[i], i};
            if (preh[i-1].val > a[i]) preh[i] = preh[i-1];
            else preh[i] = {}
        }
    }
    for (int i = 2; i <= n; ++i) prel[i] = min(prel[i-1], a[i]), preh[i] = max(preh[i-1], a[i]);
    for (int i )
    return 0;
}
