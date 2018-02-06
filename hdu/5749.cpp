#include <cstdio>
#define maxn 1010
typedef long long LL;
typedef unsigned int uint;
LL n, m, T, a[maxn][maxn], le[maxn][maxn], ri[maxn][maxn], up[maxn][maxn], down[maxn][maxn], lo[maxn], hi[maxn];
const LL mod = (LL)(1 << 30) * 4;
void work() {
    for (LL i = 0; i < n; ++i) {
        for (LL j = 0; j < m; ++j) {
            scanf("%lld", &a[i][j]);
        }
    }
    for (LL i = 0; i < n; ++i) {
        LL r = 0;
        for (LL j = 0; j < m; ++j) {
            while (r > 0 && a[i][j] < a[i][lo[r - 1]]) --r;
            if (r == 0) le[i][j] = 0;
            else le[i][j] = lo[r - 1] + 1;
            lo[r++] = j;
        }
        r = 0;
        for (LL j = m - 1; j >= 0; --j) {
            while (r > 0 && a[i][j] < a[i][lo[r - 1]]) --r;
            if (r == 0) ri[i][j] = m - 1;
            else ri[i][j] = lo[r - 1] - 1;
            lo[r++] = j;
        }
    }
    for (LL j = 0; j < m; ++j) {
        LL r = 0;
        for (LL i = 0; i < n; ++i) {
            while (r > 0 && a[i][j] > a[hi[r - 1]][j]) --r;
            if (r == 0) up[i][j] = 0;
            else up[i][j] = hi[r - 1] + 1;
            hi[r++] = i;
        }
        r = 0;
        for (LL i = n - 1; i >= 0; --i) {
            while (r > 0 && a[i][j] > a[hi[r - 1]][j]) --r;
            if (r == 0) down[i][j] = n - 1;
            else down[i][j] = hi[r - 1] - 1;
            hi[r++] = i;
        }
    }
//    for (LL i = 0; i < n; ++i) {
//        for (LL j = 0; j < m; ++j) {
//            printf("%d ", up[i][j]);
//        }
//        printf("\n");
//    }

    LL ans = 0;
    for (LL i = 0; i < n; ++i) {
        for (LL j = 0; j < m; ++j) {
            LL x = i - up[i][j] + 1, y = down[i][j] - up[i][j] + 1;
            LL ans1 = (y - x + 1) * (y + 1) * x / 2;
//            LL ans1 = ((x + y) * (y - x + 1) % mod / 2 * x % mod - (y - x + 1) * x % mod * (x - 1) % mod / 2) % mod;
            x = j - le[i][j] + 1, y = ri[i][j] - le[i][j] + 1;
            LL ans2 = (y - x + 1) * (y + 1) * x / 2;
//            LL ans2 = ((x + y) * (y - x + 1) % mod / 2 * x % mod - (y - x + 1) * x % mod * (x - 1) % mod / 2) % mod;
            ans += (LL)ans1 * ans2 % mod * a[i][j] % mod;
            ans %= mod;
        }
    }
    printf("%lld\n", ans);
}
int main() {
    scanf("%lld", &T);
    while (scanf("%lld%lld", &n, &m) != EOF) work();
    return 0;
}
