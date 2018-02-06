#include <bits/stdc++.h>
#define maxn 50000
#define maxm maxn + 10
typedef long long LL;
using namespace std;
bool check[maxm];
int prime[maxm], mu[maxm], cnt[maxn];
LL pre[maxm], sum[maxm], d[maxn];
//void init() {
//    int tot = 0; mu[1] = 1;
//    for (int i = 2; i <= maxn; ++i) {
//        if (!check[i]) {
//            prime[tot++] = i;
//            mu[i] = -1;
//        }
//        for (int j = 0; j < tot; ++j) {
//            if (i * prime[j] > maxn) break;
//            check[i * prime[j]] = true;
//            if (i % prime[j] == 0) {
//                mu[i * prime[j]] = 0;
//                break;
//            }
//            mu[i * prime[j]] = -mu[i];
//        }
//    }
//    for (int i = 1; i <= maxn; ++i) {
//        int lim = maxn / i;
//        for (int j = 0; j <= lim; ++j) {
//            int w = i * j;
//            sum[w] += j;
//            if (w + i <= maxn) sum[w + i] -= j;
//        }
//    }
//    for (int i = 0; i <= 20; ++i) printf("%d ", sum[i]); printf("\n");
//
//    for (int i = 1; i <= maxn; ++i) {
//        pre[i] = pre[i - 1] + mu[i];
//        sum[i] += sum[i - 1];
//    }
//}
void init() {
    int tot = 0; mu[1] = d[1] = 1;
    for (int i = 2; i <= maxn; ++i) {
        if (!check[i]) {
            prime[tot++] = i;
            mu[i] = -1, d[i] = 2, cnt[i] = 1;
        }
        for (int j = 0; j < tot; ++j) {
            if (i * prime[j] > maxn) break;
            check[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                cnt[i * prime[j]] = cnt[i] + 1;
                d[i * prime[j]] = d[i] / (cnt[i] + 1) * (cnt[i * prime[j]] + 1);
                break;
            }
            mu[i * prime[j]] = -mu[i];
            cnt[i * prime[j]] = 1;
            d[i * prime[j]] = d[i] << 1;
        }
    }

    for (int i = 1; i <= maxn; ++i) {
        pre[i] = pre[i - 1] + mu[i];
        sum[i] = sum[i - 1] + d[i];
    }
}
void work() {
    int n, m;
    scanf("%d%d", &n, &m);
    int lim = min(n, m), le, ri;
    LL ans = 0;
    for (int i = 1; i <= lim; i = ri + 1) {
        le = i, ri = min(n / (n / i), m / (m / i));
        ans += (pre[ri] - pre[le - 1]) * sum[n / i] * sum[m / i];
    }
    printf("%lld\n", ans);
}
int main() {
    init();
//    for (int i = 0; i <= 20; ++i) printf("%d ", sum[i]); printf("\n");
    int T;
    scanf("%d",&T);
    while (T--) work();
    return 0;
}
