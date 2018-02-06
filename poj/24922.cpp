#include <stdio.h>
#include <iostream>
#define maxn 4010
using namespace std;
typedef long long LL;
int fa[maxn], rk[maxn], sz[maxn];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void unionn(int x, int y) {
    x = find(x), y = find(y);
    if (sz[x] > sz[y]) swap(x, y);
    fa[x] = y, sz[y] += sz[x];
}
int kas;
void work() {
    printf("Scenario #%d:\n", ++kas);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= 2*n; ++i) sz[i] = 1, fa[i] = i;
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        unionn(x, y+n), unionn(y, x+n);
    }
    bool flag = false;
    for (int i = 1; i <= n; ++i) if (find(i)==find(i+n)) { flag = true; break; }
    if (flag) printf("Suspicious bugs found!\n\n");
    else printf("No suspicious bugs found!\n\n");
}
int main() {
    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
