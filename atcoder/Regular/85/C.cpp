#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
//    freopen("in.txt", "r", stdin);
    int n,m;
    scanf("%d%d", &n, &m);
    LL ans = m*1900 + (n-m) *100;
    int mul = 1;
    for (int i = 1; i <= m; ++i)  mul <<= 1;
    printf("%lld\n", ans * mul);
    return 0;
}
