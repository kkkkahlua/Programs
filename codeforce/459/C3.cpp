#include <bits/stdc++.h>
#define maxn 5010
using namespace std;
typedef long long LL;
bool f[maxn][maxn], g[maxn][maxn];
char s[maxn];
int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%s", s);
    int len = strlen(s);
    for (int l = 0; l < len; ++l) {
        int cnt = 0;
        for (int r = l; r < len; ++r) {
            cnt += s[r]==')' ? -1 : 1;
            f[l][r] = cnt >= 0;
            if (!f[l][r]) break;
        }
    }
    for (int r = len-1; r >= 0; --r) {
        int cnt = 0;
        for (int l = r; l >= 0; --l) {
            cnt += s[l]=='(' ? -1 : 1;
            g[l][r] = cnt >= 0;
            if (!g[l][r]) break;
        }
    }
    int ans=0;
    for (int i = 2; i <= len; i += 2) {
        for (int s = 0; s <= len-i; ++s) {
            int t = s+i-1;
            if (f[s][t] && g[s][t]) ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}
