#include <bits/stdc++.h>
#define maxn 10010
typedef long long LL;
LL b[maxn], ans[55], f[maxn];
void work() {
    int n, m;
    scanf("%d%d", &n, &m);
    memset(f, 0, sizeof(f));
    for (int i = 0; i <= m; ++i) scanf("%lld", &b[i]);
    f[0] = 1;
    int p = 0, tot = 0;
    while (true) {
        if (b[p] == f[p]) ++p;
        else {
            ans[tot++] = p;
            if (tot == n) break;
            for (int i = m; i >= p; --i) f[i] += f[i - p];
        }
    }
    printf("%lld", ans[0]);
    for (int i = 1; i < tot; ++i) printf(" %lld", ans[i]);
    printf("\n");
}
int main() {
//    freopen("多校第五场数据和标程/数据/1008.in", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
