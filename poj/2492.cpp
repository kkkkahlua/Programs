#include <stdio.h>
#include <iostream>
#define maxn 2010
using namespace std;
typedef long long LL;
int fa[maxn], rk[maxn], sz[maxn];
int find(int x) {
    if (fa[x] == x) return x;
    int tmp = fa[x];
    fa[x] = find(fa[x]);
    rk[x] = rk[tmp] ^ rk[x];
    return fa[x];
}
int kas;
void work() {
    printf("Scenario #%d:\n", ++kas);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) sz[i] = 1, fa[i] = i, rk[i] = 0;
    bool flag = false;
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (flag) continue;
        int xx = find(x), yy = find(y);
        if (xx == yy) {
            if (rk[x] == rk[y]) flag = true;
        }
        else {
            if (sz[xx] > sz[yy]) swap(xx, yy), swap(x, y);
            fa[xx] = yy; rk[xx] = !(rk[x] ^ rk[y]); sz[yy] += sz[xx];
        }
    }
    if (flag) printf("Suspicious bugs found!\n\n");
    else printf("No suspicious bugs found!\n\n");
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
