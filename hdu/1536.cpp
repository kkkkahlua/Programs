#include <bits/stdc++.h>
#define maxn 10000
using namespace std;
typedef long long LL;
bool vis[maxn+10];
int sg[maxn+10], a[maxn+10];
int n, T;
void init() {
    sg[0] = 0;
    for (int i = 1; i <= maxn; ++i) {
        memset(vis, 0, sizeof(vis));
        for (int j = 0; j < n && i >= a[j]; ++j) {
            vis[sg[i-a[j]]] = true;
        }
        for (int j = 0; j <= n; ++j) if (!vis[j]) { sg[i] = j; break; }
    }
    for (int j = 0; j < 15; ++j) printf("%d ", sg[j]); printf("\n");
}
void work() {
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    init();
    sort(a, a+n);
    scanf("%d", &T);
    while (T--) {
        int ret = 0, x, y;
        scanf("%d", &x);
        while (x--) scanf("%d", &y), ret ^= y;
        putchar(ret ? 'L' : 'W');
    }
    putchar('\n');
}
int main() {
    while (scanf("%d", &n) != EOF && n) work();
    return 0;
}
