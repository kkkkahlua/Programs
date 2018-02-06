#include <bits/stdc++.h>
#define maxn 100010
typedef long long LL;
inline int min(int a, int b) { return a < b ? a : b; }
inline int max(int a, int b) { return a > b ? a : b; }
int kas, prime[maxn], cnt[maxn], mu[maxn];
bool check[maxn];
const LL mod = 1e9 + 7;
void Mobius() {
    memset(check, 0, sizeof(check));
    mu[1] = 1;
    int tot = 0;
    for (int i = 2; i <= maxn; ++i) {
        if (!check[i]) {
            prime[tot++] = i;
            mu[i] = -1;
        }
        for (int j = 0; j < tot; ++j) {
            if (i * prime[j] > maxn) break;
            check[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                break;
            }
            else {
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
}
LL poww(LL a, LL b) {
    LL ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}
void work() {
    int n;
    scanf("%d", &n);
    int minn = maxn + 10, maxx = 0;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        ++cnt[x];
        minn = min(minn, x); maxx = max(maxx, x);
    }
    for (int i = 1; i <= maxn; ++i) cnt[i] += cnt[i - 1];
//    for (int i = 1; i <= 100; ++i) printf("%d ", cnt[i]);
    LL ans = 0;
    for (int i = 2; i <= minn; ++i) {
        if (mu[i] == 0) continue;
        LL mul = 1;
        for (int j = 1; i * j <= maxx; ++j) {
            int up = min(i * (j + 1), maxx + 1);
            int num = cnt[up - 1] - cnt[i * j - 1];
            mul *= poww(j, num); mul %= mod;
        }
        ans = (ans - mu[i] * mul + mod) % mod;
//        printf("%lld\n", mul);
    }
    printf("Case #%d: %lld\n", ++kas, ans);
}
int main() {
    freopen("多校联合第二场数据和标程/数据/1009.in", "r", stdin);
    freopen("09.out", "w", stdout);
//    freopen("in.txt", "r", stdin);
    Mobius();
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
