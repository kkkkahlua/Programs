#include <bits/stdc++.h>
#define maxn 4000
#define maxm maxn+10
using namespace std;
typedef long long LL;
LL temp[maxm][maxm], C[maxm][maxm];
const LL mod = 1e9+7;
LL add(LL a, LL b) { return (a+b) % mod; }
LL mul(LL a, LL b) { return (a*b) % mod; }
void init() {
    for (int i = 0; i <= maxn; ++i) C[i][0] = 1;
    for (int i = 1; i <= maxn; ++i) {
        for (int j = 1; j <= i; ++j) C[i][j] = add(C[i-1][j], C[i-1][j-1]);
    }
    for (int i = 0; i <= maxn; ++i) {
        temp[i][0] = C[i][0];
        for (int j = 1; j <= maxn; ++j) {
            temp[i][j] = add(temp[i][j-1], C[i][j]);
        }
    }
    for (int i = 0; i <= maxn; ++i) {
        for (int j = 1; j <= maxn; ++j) temp[i][j] = add(temp[i][j], temp[i][j-1]);
    }
}
int main() {
//    freopen("in.txt", "r", stdin);
    init();
    int a, b;
    LL ans = 0;
    scanf("%d%d", &a, &b);
    for (int p = 0; p <= a; ++p) {
        for (int q = 0; q <= b-1; ++q) {
            if (p+q > a) continue;
            if (q == 0) ans = add(ans, 1);
            else ans = add(ans, mul(C[b-1][q], temp[q-1][p]));
        }
    }
    printf("%lld\n", ans);
    return 0;
}
