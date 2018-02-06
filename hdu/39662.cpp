#include <bits/stdc++.h>
#define maxn 50010
#pragma comment(linker, "/STACK:1024000000,1024000000");
using namespace std;
typedef long long LL;
int le[maxn], ri[maxn], ne[maxn], tot, cnt, n, m, p, dep[maxn], f[maxn];
LL a[maxn], c[maxn];
struct Edge {
    int from, to, ne;
    Edge(int c = 0, int a = 0, int b = 0) : from(c), to(a), ne(b) {}
}edge[maxn * 2];
void addEdge(int u, int v) {
    edge[tot] = Edge(u, v, ne[u]);
    ne[u] = tot++;
}
void dfs(int u, int fa, int depth) {
    le[u] = ++cnt; dep[u] = depth; f[u] = fa;
    for (int i = ne[u]; ~i; i = edge[i].to) {
        int v = edge[i].to;
        if (v == fa) continue;
        dfs(v, u, depth+1);
    }
    ri[u] = cnt;
}
inline int lowbit(int x) { return x & (-x); }
inline void add(int x, LL w) { while (x <= n) c[x] += w, x += lowbit(x); }
inline LL query(int x) { LL ret = 0; while (x) ret += c[x], x -= lowbit(x); return ret; }
void work() {
    memset(c, 0, sizeof(c)); memset(ne, -1, sizeof(ne));
    tot = cnt = 0;
    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(u, v); addEdge(v, u);
    }
    dfs(1, -1, 0);
//    for (int i = 1; i <= n; ++i) printf("%d ", le[i]); printf("\n");
    while (p--) {
        char c; int u, v; LL x;
        scanf("\n%c", &c);
        if (c == 'I') {
            scanf("%d%d%lld", &u, &v, &x);
            add(le[u], x); add(ri[u], x); add(lca(u, v), -x); add(f[lca(u, v)], -x);
        }
        else if (c == 'D') {
            scanf("%d%d%lld", &u, &v, &x);
            add(le[u], -x); add(ri[u], -x); add(lca(u, v), x); add(f[lca(u, v)], x);
        }
        else {
            scanf("%d", &u);
            printf("%lld\n", a[u] + query(ri[u]) - query(le[u]-1));
        }
    }
}
int main() {
    while (scanf("%d%d%d", &n, &m, &p) != EOF) work();
    return 0;
}
