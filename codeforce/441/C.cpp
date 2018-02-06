#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int ans[100];
int digit(int x) {
    int ret = 0;
    while (x) {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}
int main() {
    int n;
    scanf("%d", &n);
    int tot = 0;
    for (int i = max(n-81,0); i <= n; ++i) {
        if (i+digit(i) == n) ans[tot++] = i;
    }
    printf("%d\n", tot);
    for (int i = 0; i < tot; ++i) printf("%d\n", ans[i]);
    return 0;
}
