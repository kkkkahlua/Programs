#include <bits/stdc++.h>
#define maxn 200010
typedef long long LL;
char s[maxn];
LL cnt[maxn];
int main() {
    scanf("%s", s);
    LL len = strlen(s);
    LL ans = len * (len - 1) / 2;
    for (int i = 0; i < len; ++i) ++cnt[s[i]-'a'];
    for (int i = 0; i < 26; ++i) {
        ans -= (cnt[i] * (cnt[i] - 1)) / 2;
    }
    printf("%lld\n", ans+1);
    return 0;
}
