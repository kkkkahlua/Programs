#include <stdio.h>
#define maxn 100010
using namespace std;
typedef long long LL;
int a[maxn], l[maxn], r[maxn];
LL pre[maxn];
int main() {
//    freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), pre[i] = pre[i-1] + a[i];
    l[1] = 0;
    for (int i = 2; i <= n; ++i) {
        int p = i-1;
        while (p && a[p] >= a[i]) p = l[p];
        l[i] = p;
    }
    r[n] = n+1;
    for (int i = n-1; i > 0; --i) {
        int p = i+1;
        while (p != n+1 && a[p] >= a[i]) p = r[p];
        r[i] = p;
    }
    LL ans = -1;
    int ll, rr;
    for (int i = 1; i <= n; ++i) {
        LL temp = (pre[r[i]-1] - pre[l[i]]) * a[i];
        if (temp > ans) ans = temp, ll = l[i]+1, rr = r[i]-1;
    }
    printf("%lld\n%d %d\n", ans, ll, rr);
    return 0;
}
