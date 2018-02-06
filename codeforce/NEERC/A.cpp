#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
//    freopen("in.txt", "r", stdin);
    LL n, m, a, d;
    scanf("%I64d%I64d%I64d%I64d", &n, &m, &a, &d);
    LL k = d/a+1, ans = 0, last = 0;
    for (int i = 0; i < m; ++i) {
        LL t;
        scanf("%I64d", &t);
        if (t <= last) continue;
        if (t < a) { last = t + d, ++ans; continue; }
        LL kmin = last/a+1, kmax = t/a;
        if (kmin <= kmax && kmin <= n) {
            kmax = min(kmax, n);
            LL delk = kmax-kmin+1;
            LL cnt = ceil(1.0*delk / k)-1;
            ans += cnt;

            kmin += cnt*k;
            if (kmin*a+d >= t) last = kmin*a+d, ++ans;
            else last = t+d, ans += 2;
        }
        else last = t + d, ++ans;
    }
    LL b = last / a + 1;
    if (b <= n) ans += ceil(1.0*(n-b+1) / k);
    printf("%I64d\n", ans);
    return 0;
}
