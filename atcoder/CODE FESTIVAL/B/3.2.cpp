#include <bits/stdc++.h>
#define maxn 200010
using namespace std;
typedef long long LL;
int fa[maxn], sz[maxn];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
bool same(int u, int v) { return find(u) == find(v); }
void unionn(int x, int y) {
    x = find(x), y = find(y);
    if (sz[x] > sz[y]) swap(x, y);
    fa[x] = y; sz[y] += sz[x];
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= (n<<1); ++i) fa[i] = i;
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        unionn(u, n+v);
        unionn(n+u, v);
    }
    for (int i = 1; i <= n; ++i) if (same(i, n+i)) { printf("%lld\n", 1LL*n*(n-1)/2-m); return 0; }
    int b = 1, w = 0;
    for (int i = 2; i <= n; ++i) if (same(1, i)) ++b; else ++w;
    printf("%lld\n", 1LL * b * w - m);
    return 0;
}
