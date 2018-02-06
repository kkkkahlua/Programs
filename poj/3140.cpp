#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#define maxn 100010
typedef long long LL;
using namespace std;
inline LL abs(LL x) { return x < 0 ? -x : x; }
struct Edge {
    int from, to, ne;
    Edge(int a = 0, int b = 0, int c = 0) :
        from(a), to(b), ne(c) {}
}edge[maxn * 2];
int tot, kase, next[maxn], n, m;
LL sz[maxn], f[maxn], num[maxn], sum;
void add(int u, int v) {
    Edge e(u, v, next[u]);
    edge[tot] = e;
    next[u] = tot++;
}
void dfs(int u, int fa) {
    sz[u] = num[u];
    for (int i = next[u]; i != -1; i = edge[i].ne) {
        Edge e = edge[i]; int v = e.to;
        if (v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
    f[u] = abs(sum - 2 * sz[u]);
}
void work() {
    memset(next, -1, sizeof(next));
    memset(sz, 0, sizeof(sz));
    tot = 0; sum = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &num[i]);
        sum += num[i];
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y);
        add(y, x);
    }
    dfs(1, -1);
    LL ans = f[1];
//    for (int i = 1; i <= n; ++i) printf("%lld ", f[i]); printf("\n");
    for (int i = 2; i <= n; ++i) ans = f[i] < ans ? f[i] : ans;
    printf("Case %d: %lld\n", ++kase, ans);
}
int main() {
    while (scanf("%d%d", &n, &m) != EOF && (m + n)) work();
    return 0;
}
