#include <bits/stdc++.h>
#define maxn 60
using namespace std;
typedef long long LL;
const LL mod = 1e9+7;
char s1[maxn], s2[maxn];
int main() {
    int n;
    LL ans = 1;
    scanf("%d%s%s", &n, s1, s2);
    int tp, beg;
    if (s1[0] == s2[0]) ans = 3, beg = 1, tp = 1;
    else ans = 6, beg = 2, tp = 2;
    for (int i = beg; i < n; ) {
        if (tp == 1) {
            ans = ans * 2 % mod;
            if (s1[i] == s2[i]) ++i;
            else i += 2, tp = 2;
        }
        else {
            if (s1[i] == s2[i]) ++i, tp = 1;
            else ans = ans * 3 % mod, i += 2;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
