#include <bits/stdc++.h>
#define maxn 10000000
#define maxm maxn + 10
using namespace std;
typedef long long LL;
bool check[maxm];
int prime[maxm], cnt[maxm], val[maxm], g[maxm], sum[maxm];
void init() {
    int tot = 0; g[1] = 0;
    for (int i = 2; i <= maxn; ++i) {
        if (!check[i]) {
            prime[tot++] = i;
            cnt[i] = 1, val[i] = i, g[i] = 1;
        }
        for (int j = 0; j < tot; ++j) {
            if (i * prime[j] > maxn) break;
            check[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                cnt[i * prime[j]] = cnt[i] + 1, val[i * prime[j]] = val[i] * prime[j];
                int temp = (i * prime[j]) / val[i * prime[j]];
                if (temp == 1) g[i * prime[j]] = 1;
                else g[i * prime[j]] = (cnt[temp] == cnt[i * prime[j]] ? -g[temp] : 0);
                break;
            }
            cnt[i * prime[j]] = 1, val[i * prime[j]] = prime[j];
            int temp = (i * prime[j]) / val[i * prime[j]];
            if (temp == 1) g[i * prime[j]] = 1;
            else g[i * prime[j]] = (cnt[temp] == cnt[i * prime[j]] ? -g[temp] : 0);
        }
    }
    for (int i = 1; i <= maxn; ++i) sum[i] = sum[i - 1] + g[i];
}
void work() {
    LL a, b;
    scanf("%lld%lld", &a, &b);
    int le, ri, lim = min(a, b);
    LL ans = 0;
    for (int i = 1; i <= lim; i = ri + 1) {
        le = i, ri = min(a / (a / i), b / (b / i));
        ans += (a / i) * (b / i) * (sum[ri] - sum[le - 1]);
    }
    printf("%lld\n", ans);
}
int main() {
    init();
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
