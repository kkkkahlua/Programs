#include <bits/stdc++.h>
#define maxn 200010
using namespace std;
const int mod = 10007;
typedef long long LL;
char s[maxn];
int f[maxn], n, dp[maxn];
void getfail() {
    f[0] = f[1] = 0;
    for (int i = 1; i < n; ++i) {
        int j = f[i];
        while (j && s[i] != s[j]) j = f[j];
        f[i+1] = s[i] == s[j] ? j+1 : 0;
    }
}
void work() {
    scanf("%d%s", &n, s);
    getfail();
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        (dp[i] = dp[f[i]] + 1) %= mod;
        (ans += dp[i]) %= mod;
    }
    printf("%d\n", ans);
}
int main() {
//    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
