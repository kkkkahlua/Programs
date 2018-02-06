#include <cstdio>
#include <cctype>
#include <queue>
#include <cmath>
#include <algorithm>
#define maxn 100010
using namespace std;
typedef long long LL;
queue<LL> q1, q2;
LL n, t, a[maxn];
bool can(LL k) {
//    printf("%d\n", k);
    while (!q1.empty()) q1.pop();
    while (!q2.empty()) q2.pop();
    LL cost = 0;
    LL x = (n - 1) % (k - 1);
    if (x) {
        for (int i = 0; i < k - 1 - x; ++i) q1.push(0);
    }
    for (LL i = 0; i < n; ++i) q1.push(a[i]);
    LL times = ceil((double)(n - 1) / (k - 1));
    for (LL i = 0; i < times; ++i) {
        LL c0 = 0;
        for (LL j = 0; j < k; ++j) {
            if (!q1.empty() && !q2.empty()) {
                LL u = q1.front(), v = q2.front();
                if (u <= v) { c0 += (LL)u; q1.pop(); }
                else { c0 += (LL)v; q2.pop(); }
            }
            else if (q1.empty()) {
                c0 += (LL)q2.front(); q2.pop();
            }
            else { c0 += (LL)q1.front(); q1.pop(); }
            if (c0 > t) return false;
        }
        q2.push(c0);
        cost += c0;
//        printf("%lld %lld\n", k, cost);
        if (cost > t) return false;
    }
//    printf("%d %d\n", k, cost);
    return true;
}
void work() {
    scanf("%lld%lld", &n, &t);
    for (LL i = 0; i < n; ++i) scanf("%lld", &a[i]);
    sort(a, a + n);
    LL lo = 2, hi = n;
    while (hi > lo) {
        LL mid = (hi + lo) >> 1;
        if (can(mid)) hi = mid;
        else lo = mid + 1;
    }
    printf("%lld\n", lo);
}
int main() {
    freopen("5884.in", "r", stdin);
    LL T;
    scanf("%lld", &T);
    while (T--) work();
    return 0;
}
