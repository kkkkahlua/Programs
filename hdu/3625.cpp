#include <bits/stdc++.h>
#define maxn 21
typedef long long LL;
LL S[maxn][maxn];
void init() {
    S[1][1] = 1;
    for (int i = 2; i <= maxn; ++i) {
        S[i][1] = S[i - 1][1] * (i - 1);
        for (int j = 2; j < i; ++j) S[i][j] = S[i - 1][j - 1] + S[i - 1][j] * (i - 1);
        S[i][i] = 1;
    }
}
void work() {
    int n, k;
    scanf("%d%d", &n, &k);
    LL ans = S[n][1];
    for (int i = 2; i <= k; ++i) {
        ans += S[n][i] - S[n - 1][i - 1];
    }
    printf("%.4f\n", 1.0 * ans / S[n + 1][1]);
}
int main() {
    init();
    int T;
    scanf("%d",&T);
    while (T--) work();
    return 0;
}
