#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
typedef long long LL;
int a[maxn], cnt[maxn], ans[maxn];
int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        ++cnt[a[i] % k];
    }
    for (int i = 0; i < k; ++i) {
        if (cnt[i] >= m) {
            printf("Yes\n");
            int tot = 0;
            for (int j = 0; j < n && tot < m; ++j) {
                if (a[j] % k == i) ans[tot++] = a[j];
            }
            printf("%d", ans[0]);
            for (int i = 1; i < tot; ++i) printf(" %d", ans[i]); printf("\n");
            exit(0);
        }
    }
    printf("No\n");
    return 0;
}
