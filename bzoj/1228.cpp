#include <bits/stdc++.h>
#define maxn 20
#define maxk 33
using namespace std;
typedef long long LL;
int sg[maxn+10][maxn+10];
bool vis[maxn+10];
void work() {
    int n;
    scanf("%d", &n);
    n >>= 1;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        LL x, y;
        scanf("%lld%lld", &x, &y);
        --x; --y;
        LL modd = 2, ans = 0;
        for (int k = 0; k <= maxk; ++k) {
            if (x % modd < (modd>>1) && y % modd < (modd>>1)) break;
            modd <<= 1; ++ans;
        }
        res ^= ans;
    }
    puts(res ? "YES" : "NO");
}
void init() {
    sg[1][1] = 0;
    for (int i = 1; i <= maxn; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (i==1&&j==1) continue;
            memset(vis, 0, sizeof vis);
            for (int k = 1; k < i; ++k) vis[sg[k][i-k]] = true;
            for (int k = 1; k < j; ++k) vis[sg[k][j-k]] = true;
            for (int k = 0; k <= maxn; ++k) if (!vis[k]) { sg[i][j] = sg[j][i] = k; break; }
        }
    }
//    for (int i = 1; i <= maxn; ++i) {
//        for (int j = 1; j <= maxn; ++j) printf("%d ", sg[i][j]); putchar('\n');
//    }
}
int main() {
//    freopen("out.txt", "w", stdout);
    init();
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
