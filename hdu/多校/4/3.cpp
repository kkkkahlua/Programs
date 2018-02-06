#include <bits/stdc++.h>
#define maxn 1000000
#define mod 998244353
typedef long long LL;
bool vis[maxn + 10];
int prime[maxn + 10], tot;
LL a[maxn + 10], cnt, mul[maxn + 10];
void pre() {
    for (int i = 2; i <= maxn; ++i) {
        if (!vis[i]) {
            prime[tot++] = i;
        }
        for (int j = 0; j < tot; ++j) {
            if (i * prime[j] > maxn) break;
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}
void work() {
    LL l, r, k;
    scanf("%lld%lld%lld", &l, &r, &k);
    for (LL i = l; i <= r; ++i) a[i - l] = i, mul[i - l] = 1;
    LL r0 = r; r -= l;
    for (int i = 0; i < tot; ++i) {
//        printf("%d\n", i);
        if (prime[i] > r0) break;
//        int j;
        int j = ceil((double)l / prime[i]) * prime[i] - l;

//        for (j = 0; j <= r; ++j) {
//            if (a[j] % prime[i] == 0) break;
//        }
        for (int jj = j; jj <= r; jj += prime[i]) {
            LL cnt = 0;
            while (a[jj] % prime[i] == 0) ++cnt, a[jj] /= prime[i];
            mul[jj] = mul[jj] * (k * cnt % mod + 1) % mod;
//            printf("%d %lld\n", jj, mul[jj]);
        }
    }
    for (int i = 0; i <= r; ++i) if (a[i] > 1) mul[i] *= (k + 1), mul[i] %= mod;
    LL sum = 0;
    for (int i = 0; i <= r; ++i) sum += mul[i], sum %= mod;
    printf("%lld\n", sum);
}
int main() {
    freopen("多校第四场标程和数据/数据/1003.in", "r", stdin);
//    freopen("03.out", "w", stdout);
//    freopen("in.txt", "r", stdin);
    pre();
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
