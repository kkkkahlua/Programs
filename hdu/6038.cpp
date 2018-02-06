#include <cstdio>
#include <cmath>
#include <cstring>
#define mod 1000000007
#define maxn 100010
typedef long long LL;
int kas, a[maxn], b[maxn], n, m;
LL tot[maxn];
bool in[maxn];
void findcycle(int* a, int n) {
    for (int i = 0; i < n; ++i) {
        if (!in[i]) {
            in[i] = true;
            int ii = a[i], cnt = 1;
            while (ii != i) {
                in[ii] = true;
                ii = a[ii];
                ++cnt;
            }
            ++tot[cnt];
        }
    }
}
void work() {
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i) scanf("%d", &b[i]);
    memset(tot, 0, sizeof(tot));
    memset(in, 0, sizeof(in));
    findcycle(b, m);
    memset(in, 0, sizeof(in));
    LL ans = 1;
    for (int i = 0; i < n; ++i) {
        if (!in[i]) {
            in[i] = true;
            int ii = a[i], cnt = 1;
            while (ii != i) {
//                printf("%d ", ii);
                in[ii] = true;
                ii = a[ii];
                ++cnt;
            }
//            printf("\n");
//            printf("%d %d\n", i, cnt);
            LL mul = 0;
            for (int j = 1; j <= cnt; ++j) {
                if (cnt % j == 0) {
                    mul += (tot[j] * j) % mod;
                    mul %= mod;
                }
            }
            ans *= mul;
            ans %= mod;
        }
    }

    printf("Case #%d: %lld\n", ++kas, ans % mod);
}
int main() {
    while (scanf("%d%d\n", &n, &m) != EOF) work();
    return 0;
}
