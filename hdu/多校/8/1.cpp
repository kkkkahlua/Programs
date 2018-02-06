#include <bits/stdc++.h>
#define maxn 2000
typedef long long LL;
const LL mod = 1e9 + 7;
LL C[maxn + 10][maxn + 10], A[maxn + 10][maxn + 10];
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
void init() {
    for (int i = 0; i <= maxn; ++i) C[i][i] = C[i][0] = 1;
    for (int i = 2; i <= maxn; ++i) {
        for (int j = 1; j < maxn; ++j) C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
    }
}
void init2() {
    for (int i = 1; i <= maxn; ++i) A[i][1] = 1;
    for (int i = 2; i <= maxn; ++i) A[i][i] = A[i-1][i-1] * i % mod;
    for (int i = 3; i <= maxn; ++i) {
        for (int j = 2; j < i; ++j) {
            A[i][j] = (A[i - 1][j] * j % mod + A[i - 1][j - 1] * j % mod) % mod;
        }
    }
}
void work() {
    LL n, m;
    scanf("%lld%lld", &n, &m);
    LL ans = 0;
    for (int tot = 2; tot <= m; ++tot) {
        int le = max(1, tot - n), ri = min(tot - 1, n);
        for (int i = le; i <= ri; ++i) {
            int j = tot - i;
            ans += C[m][tot] * C[tot][i] % mod * A[n][i] % mod * A[n][tot - i] % mod;

//            ans += C[m][tot] * C[tot][i] % mod * AA(n, i) % mod * AA(n, tot - i) % mod;
            ans %= mod;
        }
    }
    printf("%lld\n", ans);
}
int main() {
    freopen("in.txt", "r", stdin);
    init(); init2();
//    for (int i = 1; i <= 20; ++i) {
//        for (int j = 1; j <= i; ++j) printf("%lld ", A[i][j]); printf("\n");
//    }
//    for (int i = 990; i <= 1000; ++i) printf("%lld ", A[2000][i]); printf("\n");
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
