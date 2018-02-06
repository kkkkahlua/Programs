#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
char s[5010];
int dp[5010][5010];
bool ok(int l, int r) {
    if (s[l]=='(') {
        if (s[r]==')' || s[r]=='?') return true;
    }
    else if (s[l]=='?') {
        if (s[r]==')' || s[r]=='?') return true;
    }
    return false;
}
int main() {
    freopen("in.txt", "r", stdin);
    freopen("c2.out", "w", stdout);
    scanf("%s", s);
    int len = strlen(s), cnt=0;
    for (int i = 0; i <= len-2; ++i) {
        if (ok(i,i+1)) dp[i][i+1] = true, ++cnt;
    }
    for (int i = 4; i <= len; i += 2) {
        for (int s = 0; ; ++s) {
            int t = s+i-1;
            if (t >= len) break;
            if (dp[s+1][t-1] && ok(s,t)) {
                dp[s][t] = true, ++cnt;
//                printf("%d %d\n", s,t);
            }
            else {
                for (int k = s+1; k <= t-2; ++k) {
                    if (dp[s][k] && dp[k+1][t]) {
                        dp[s][t] = true, ++cnt;
//                        printf("%d %d\n", s,t);

                        break;
                    }
                }
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
