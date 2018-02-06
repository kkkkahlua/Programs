#include <bits/stdc++.h>
#define maxn 100010
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long LL;
vector<int> v;
int a[maxn], pre[maxn], succ[maxn], b[maxn];
bool flag[maxn];
int main() {
    LL x;
    scanf("%lld", x);
    int k;
    scanf("%d", k);
    r[i] = 0;
    for (int i = 1; i <= k; ++i) scanf("%lld", r[i]);
    for (int i = 0; i < k; ++i) {
        diff[i] = r[i+1] - r[i];
        if (diff[i] > x) diff[i] = x;
        if (i & 1 == 0) diff[i] = -diff[i];
    }
    for (int i = 1; i < k; ++i) diff[i] += diff[i-1];
    scanf("%d", &q);
    while (q--) {
        scanf("%lld%lld", &t, &a);
        LL lo = -a, hi = x-a;
        for (int i = 0; i < k; ++i) {
            if (t >= a[i])
        }
    }
    return 0;
}
