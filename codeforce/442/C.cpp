#include <bits/stdc++.h>
#define maxn 200010
int ans[maxn];
using namespace std;
typedef long long LL;
int main() {
    int n;
    scanf("%d", &n);
    int tot = 0;

    printf("%d\n", n+n/2);
    for (int i = 1; i <= n/4; ++i) {
        ans[tot++] = i*2;
        ans[tot++] = i*2-1;
    }
    for (int i = 1; i <= n/4; ++i) {
        ans[tot++] = n-(i*2)+1;
        ans[tot++] = n-(i*2)+2;
    }

    if (n%4==1) {
        ans[tot++] = n/2+1;
        for (int i = 2; i < n; ++i) if (!(i&1)) ans[tot++] = i;
    }
    else if (n%4==3) {
        ans[tot++] = n/2+1, ans[tot++] = n/2, ans[tot++] = n/2+2;
        for (int i = 2; i < n; ++i) if (!(i&1)) ans[tot++] = i;
    }
    else if (n%4==2) {
        ans[tot++] = n/2; ans[tot++] = n/2+1, ans[tot++] = n/2;
        for (int i = 1; i <= n/4; ++i) ans[tot++] = 2*i, ans[tot++] = n+1-2*i;
    }
    else {
        for (int i = 1; i <= n/4; ++i) ans[tot++] = 2 * i, ans[tot++] = n+1-2*i;
    }
    printf("%d", ans[0]);
    for (int i = 1; i < tot; ++i) printf(" %d", ans[i]); printf("\n");

    return 0;
}
