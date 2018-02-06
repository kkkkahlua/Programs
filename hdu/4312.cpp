#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define maxn 100010
using namespace std;
typedef long long LL;
struct node {
    LL x, y;
}a[maxn];
bool cmp1(int i, int j) { return a[i].x < a[j].x; }
bool cmp2(int i, int j) { return a[i].y < a[j].y; }
LL x[maxn], y[maxn], pr[maxn], su[maxn];
int id[maxn];
void work() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        LL xx, yy;
        scanf("%lld%lld", &xx, &yy);
        a[i].x = xx+yy, a[i].y = yy-xx;
    }
    for (int i = 1; i <= n; ++i) id[i] = i;

    sort(id+1, id+1+n, cmp1);
    memset(pr, 0, sizeof pr);
    memset(su, 0, sizeof su);
    for (int i = 1; i <= n; ++i) pr[i] = pr[i-1] + a[id[i]].x;
    su[n] = a[id[n]].x; for (int i = n-1; i > 0; --i) su[i] = su[i+1] + a[id[i]].x;
    for (int i = 1; i <= n; ++i) x[id[i]] = (2*i-1-n)*a[id[i]].x - pr[i-1] + su[i+1];

    sort(id+1, id+1+n, cmp2);
    memset(pr, 0, sizeof pr);
    memset(su, 0, sizeof su);
    for (int i = 1; i <= n; ++i) pr[i] = pr[i-1] + a[id[i]].y;
    su[n] = a[id[n]].y; for (int i = n-1; i > 0; --i) su[i] = su[i+1] + a[id[i]].y;
    for (int i = 1; i <= n; ++i) y[id[i]] = (2*i-1-n)*a[id[i]].y - pr[i-1] + su[i+1];

    LL ans = inf;
    for (int i = 1; i <= n; ++i) ans = min(ans, x[i]+y[i]);
    printf("%lld\n", ans/2);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
