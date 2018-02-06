#include <bits/stdc++.h>
#define maxn 5010
using namespace std;
typedef long long LL;
int a[maxn], b[maxn], dp[maxn][maxn];
bool flag[maxn];
int main() {
    int n, k, v, sum = 0;
    scanf("%d%d%d", &n, &k, &v);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        sum += (b[i] = a[i]), a[i] %= k;
    }

    if (sum < v) { puts("NO"); return 0; }
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < k; ++j) {
            if (dp[i-1][j]) {
                dp[i][j] = 1;
                if (!dp[i][(j+a[i])%k]) dp[i][(j+a[i])%k] = 2;
            }
        }
    }
    int tar = v % k;
    if (!dp[n][tar]) { puts("NO"); return 0; }
    puts("YES");
    int ans = 0, fnl1 = -1, fnl2 = -1;
    for (int i = n; i >= 1; --i) {
        if (dp[i][tar]==2) {
            flag[i] = true, (tar += k-a[i]) %= k, ans += b[i];
            if (fnl1==-1) fnl1 = i;
        }
        else if (fnl2 == -1) fnl2 = i;
    }
    if (fnl1==-1) {
        for (int i = 1; i < n; ++i) if (b[i]) {
            printf("%d %d %d\n", (b[i] + k-1)/k, i, n);
        }
        if (v/k) printf("%d %d %d\n", v/k, n, 1);
        return 0;
    }
    assert((v-ans) % k == 0);
    int rem = v - ans;
    int S1 = b[fnl1], S2 = b[fnl2];
    for (int i = 1; i <= n; ++i) {
        if (i == fnl1 || i == fnl2 || !b[i]) continue;
        if (!flag[i]) printf("%d %d %d\n", (b[i]+k-1)/k, i, fnl2), S2 += b[i];
        else printf("%d %d %d\n", (b[i]+k-1)/k, i, fnl1), S1 += b[i];
    }
    assert((v-S1) % k == 0);
    int cnt = (v-S1) / k;
    if (cnt>0) printf("%d %d %d\n", cnt, fnl2, fnl1);
    else if (cnt<0) printf("%d %d %d\n", -cnt, fnl1, 1);
    return 0;
}
