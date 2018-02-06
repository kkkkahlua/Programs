#include <bits/stdc++.h>
#define maxn 10010
using namespace std;
typedef long long LL;
LL ans[110], b[maxn];
void work() {
    LL n, m;
    scanf("%lld%lld", &n, &m);
    LL lim1 = n - 1, add = (n - 1) * (n - 2) >> 1;
    LL lim2 = lim1 + add, tot1 = (n - 1) * (n - 1) * 2;
    if (m >= lim2) { printf("%lld\n", n * (n - 1)); return; }
    if (m >= lim1) { printf("%lld\n", tot1 - 2 * (m - lim1)); return; }
    LL nn = m + 1;
    LL tot0 = (nn - 1) * (nn - 1) * 2 + ((n - nn) * nn * 2 + (n - nn) * (n - nn - 1)) *n;
    printf("%lld\n", tot0);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
