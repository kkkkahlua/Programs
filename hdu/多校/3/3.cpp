#include <bits/stdc++.h>
#define maxn 500010
typedef long long LL;
int pos[maxn], s1[110], s2[110], pre[maxn], suc[maxn];
void work() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        pos[x] = i;
    }
    for (int i = 1; i <= n; ++i) {
        pre[i] = i - 1; suc[i] = i + 1;
    }
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        int p = pos[i], t1 = 0, t2 = 0;
        while (p > 0 && t1 < k + 1) {
            s1[t1++] = p;
            p = pre[p];
        }
        if (t1 <= k) s1[t1++] = 0;
        p = pos[i];
        while (p < n + 1 && t2 < k + 1) {
            s2[t2++] = p;
            p = suc[p];
        }
        if (t2 <= k) s2[t2++] = n + 1;

        for (int l = 0; l < t1 - 1; ++l) {
            int r = k - 1 - l;
            if (r >= t2 - 1) continue;
            ans += (LL)(s1[l] - s1[l + 1]) * (s2[r + 1] - s2[r]) * i;
        }

        p = pos[i];
        int prev = pre[p], succ = suc[p];
        pre[succ] = prev; suc[prev] = succ;
//        printf("%lld\n", ans);
    }
    printf("%lld\n", ans);
}
int main() {
    freopen("多校第三场数据和标程/数据/1003.in", "r", stdin);
    freopen("03.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
