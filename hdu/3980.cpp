#include <bits/stdc++.h>
#define maxn 1010
using namespace std;
typedef long long LL;
int f[maxn], n, m;
bool vis[maxn][maxn], calc[maxn];
int fun(int x) {
    if (calc[x]) return f[x];
    calc[x] = true;
    if (x < m) return f[x] = 0;
    for (int i = 0; i <= x-m; ++i) vis[x][fun(i) ^ fun(x-m-i)] = true;
    int ret;
    for (int i = 0; i <= x; ++i) if (!vis[x][i]) { ret = i; break; }
    return f[x] = ret;
}
int kas;
void work() {
    scanf("%d%d", &n, &m);
    memset(f, 0, sizeof(f));
    memset(calc, 0, sizeof(calc));
    memset(vis, 0, sizeof(vis));
    printf("Case #%d: ", ++kas);
    if (n < m) { puts("abcdxyzk"); return; }
    if (!fun(n-m)) puts("aekdycoin");
    else puts("abcdxyzk");
//    for (int i = 0; i <= n; ++i) printf("%d ", f[i]); puts("");
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
