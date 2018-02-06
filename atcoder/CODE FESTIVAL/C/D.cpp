#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 200010
using namespace std;
typedef long long LL;
char s[maxn];
int opt[maxn], h[maxn];
int main() {
    scanf("%s", s+1);
    int len = strlen(s+1);
    for (int i = 1; i <= len; ++i) h[i] = h[i-1] ^ (1<<(s[i]-'a'));
    map<int, int> dp;
    for (int i = 1; i <= len; ++i) {
        opt[i] = (!h[i] || dp[h[i]]) ? dp[h[i]] : inf;
        int mask = 1;
        for (int j = 0; j < 26; ++j) {
            if ((h[i]^mask) == 0 || dp[h[i]^mask]) opt[i] = min(opt[i], dp[h[i]^mask]);
            mask <<= 1;
        }
        ++opt[i];
        if (!dp[h[i]] && h[i]) dp[h[i]] = opt[i];
        else dp[h[i]] = min(dp[h[i]], opt[i]);
    }
    printf("%d\n", opt[len]);
    return 0;
}
