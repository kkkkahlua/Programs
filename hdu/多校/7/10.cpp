#include <bits/stdc++.h>
#define maxn 200010
using namespace std;
int n,m, a[maxn], b[maxn], ans[maxn];
void work() {
    scanf("%d %d", &n, &m);
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    int mod = 1;
    while (mod < n) mod <<= 1;
    m %= mod;
    for (int i = 1; i <= n; ++i) {
        int deno = m + i - 2, nomi = i - 1;
        if ((deno & nomi) == nomi) {
            for (int j = 1; j <= n - i + 1; ++j) ans[i + j - 1] ^= a[j];
        }
    }
    printf("%d", ans[1]);
    for (int i = 2; i <= n; ++i) {
        printf(" %d", ans[i]);
    }
    printf("\n");
}
int main() {
    freopen("多校第七场数据和标程/数据/1010.in", "r", stdin);
    freopen("10.out", "w", stdout);
//    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
