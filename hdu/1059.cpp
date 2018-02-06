#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int dp[600010];
int n[7], kas;
int main() {
    freopen("in.txt", "r", stdin);
    while (true) {
        int mask = 0, tot = 0;
        for (int i = 1; i <= 6; ++i) {
            scanf("%d", &n[i]);
            mask |= n[i];
            tot += n[i] * i;
//            tot += ((n[i] &= 1) ? i : 0);
        }
        if (!mask) break;
        printf("Collection #%d:\n", ++kas);

        bool ok;
        if (tot & 1) ok = false;
        else {
            memset(dp, 0, sizeof dp);
            int req = tot >> 1;
            dp[0] = 1; int cur = 0;
            for (int i = 1; i <= 6; ++i) {
                if (!n[i]) continue;
                for (int j = cur; j >= 0; --j) if (dp[j]) {
                    for (int k = 1; k <= n[i]; ++k) {
                        if (dp[])
                    }
                    dp[j+i] = true;
            }
            ok = dp[req];
        }
        if (ok) puts("Can be divided.\n");
        else puts("Can't be divided.\n");
    }
    return 0;
}
