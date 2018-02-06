#include <bits/stdc++.h>
#define maxn 200010
using namespace std;
typedef long long LL;
LL c[maxn], a[maxn];
int main() {
//    freopen("in.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    LL base = 0;
    for (int i = 1; i < n; ++i) {
        LL s = a[i-1], t = a[i];
        if (t < s) t += m;
        base += t - s;
        c[s+2] += 1, c[t+1] -= t-s, c[t+2] += t-s-1;
    }
    for (int i = 1; i <= (m<<1); ++i) c[i] += c[i-1];
    for (int i = 1; i <= (m<<1); ++i) c[i] += c[i-1];
    LL maxx = 0;
    for (int i = 1; i <= m; ++i) maxx = max(maxx, c[i] + c[i+m]);
    printf("%lld\n", base - maxx);
    return 0;
}
