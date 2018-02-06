#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    LL n, m;
    scanf("%I64d%I64d", &n, &m);
    if (m-n >= 10) puts("0");
    else {
        int ans = 1;
        for (LL i = n+1; i <= m; ++i) ans *= i%10;
        printf("%d", ans % 10);
    }
    return 0;
}
