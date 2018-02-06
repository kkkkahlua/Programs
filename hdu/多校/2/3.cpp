#include <cstdio>
#include <algorithm>
#include <iostream>
#define maxn 250010
typedef long long LL;
const LL mod = 1e9 + 7;
using namespace std;
int a[maxn], b[maxn], maxa[maxn], diff[maxn], n;
inline int max(int a, int b) { return a > b ? a : b; }
void work() {
    for (int i = 1; i <= n; ++i) { scanf("%d", &a[i]); diff[i] = a[i] - i; }
    for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
    maxa[n] = diff[n];
    for (int i = n - 1; i > 0; --i) maxa[i] = max(maxa[i + 1], diff[i]);
    sort(b + 1, b + 1 + n);
    int x = maxa[b[1]];
    LL ans = x;
    for (int i = 1; i <= n; ++i) maxa[i] = max(maxa[i], x - (n + 1));
    for (int i = 2; i <= n; ++i) {
        x = maxa[b[i]];
        ans += (LL)x;
        ans %= mod;
    }
    printf("%lld\n", ans);
}
int main() {
    freopen("多校联合第二场数据和标程/数据/1003.in", "r", stdin);
    freopen("03.out", "w", stdout);
    while (scanf("%d", &n) != EOF) work();
    return 0;
}
