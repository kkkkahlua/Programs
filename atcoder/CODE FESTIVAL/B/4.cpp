#include <bits/stdc++.h>
#define maxn 500010
using namespace std;
char s[maxn];
int a[maxn], dp[maxn];
int main() {
    int n;
    scanf("%d%s", &n, s+1);
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '0') a[i] = i;
        else a[i] = a[i-1];
    }
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i-1];
        if (s[i] == '1') {
            if (s[i-1] == '0' && s[i-2] == '1') {
                dp[i] = max(dp[i], dp[a[i-2]]+ (i-2) - a[i-2]);
                dp[i] = max(dp[i], dp[a[i-2]+1] + (i-2) - (a[i-2]+1));
            }
            else if (a[i]>1 && s[a[i]-1] == '1') dp[i] = max(dp[i], dp[a[i]-2] + i - a[i]);
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}
