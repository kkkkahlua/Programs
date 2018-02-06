#include <bits/stdc++.h>
#define maxn 200010
int ans[maxn];
using namespace std;
typedef long long LL;
int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", n+n/2);

    int tot = 0;
    for (int i = 1; i <= n; ++i) if (!(i&1)) ans[tot++]= i;
    for (int i = 1; i <= n; ++i) if (i&1) ans[tot++] = i;
    for (int i = 1; i <= n; ++i) if (!(i&1)) ans[tot++]= i;

    printf("%d", ans[0]);
    for (int i = 1; i < tot; ++i) printf(" %d", ans[i]); printf("\n");
    return 0;
}
