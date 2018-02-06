#include <bits/stdc++.h>
#define maxn 1000
using namespace std;
typedef long long LL;
int f[maxn+10], sg[maxn+10];
bool vis[maxn+10];
void init() {
    f[0] = f[1] = 1;
    int i = 2;
    for (; i <= maxn && f[i-1] < maxn ; ++i) f[i] = f[i-1] + f[i-2];
    int tot = i-1;
    sg[0] = 0;
    for (int i = 1; i <= maxn; ++i) {
        memset(vis, 0, sizeof(vis));
        for (int j = 0; j < tot && i >= f[j]; ++j) vis[sg[i-f[j]]] = true;
        for (int j = 0; j <= maxn; ++j) { if (!vis[j]) {sg[i] = j; break; } }
    }
}
int n, m, p;
void work() {
    if (sg[n]^sg[m]^sg[p]) puts("Fibo");
    else puts("Nacci");
}
int main() {
    init();
    while (scanf("%d%d%d", &n, &m, &p) != EOF && n&&m&&p) work();
    return 0;
}
