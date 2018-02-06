#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
typedef long long LL;
struct Edge {
    int to, ne;
    Edge(int a = 0, int b = 0) : to(a), ne(b) {}
}edge[maxn * 2];
LL c1[maxn], c2[maxn], c3[maxn], ori[maxn], val[maxn];
int dep[maxn], le[maxn], ri[maxn], tot, cnt, ne[maxn];
void addEdge(int u, int v) {
    edge[tot] = Edge(v, ne[u]);
    ne[u] = tot++;
}
int n, m;
inline int lowbit(int x) { return x & (-x); }
inline void add(int x, LL del, LL* c) { while (x <= n) c[x] += del, x += lowbit(x); }
inline LL query(int x, LL* c) { LL ret = 0; while (x) ret += c[x], x -= lowbit(x); return ret; }
void dfs(int u, int fa, int depth, LL p) {
    le[u] = ++cnt; dep[u] = depth; ori[u] = p;
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (v == fa) continue;
        dfs(v, u, depth + 1, p + val[v]);
    }
    ri[u] = cnt;
}
void work() {
    memset(c1, 0, sizeof c1); memset(c2, 0, sizeof c2); memset(c3, 0, sizeof c3);
    memset(ne, -1, sizeof(ne)); tot = 0;
    for (int i = 1; i <= n; ++i) scanf("%lld", &val[i]);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(u, v); addEdge(v, u);
    }
    dfs(1, -1, 0, val[1]);
    while (m--) {
        int x, u; LL w;
        scanf("%d", &x);
        if (x == 1) {
            scanf("%d%lld", &u, &w);
            add(le[u], w, c1), add(ri[u]+1, -w, c1);
        }
        else if (x == 2) {
            scanf("%d%lld", &u, &w);
            add(le[u], w*(-dep[u]+1), c2), add(ri[u]+1, -w*(-dep[u]+1), c2);
            add(le[u], w, c3), add(ri[u]+1, -w, c3);
        }
        else {
            scanf("%d", &u);
            printf("%lld\n", ori[u]+query(le[u], c1)+query(le[u], c2)+dep[u]*query(le[u], c3));
        }
    }
}
int main() {
    while (scanf("%d%d", &n, &m) != EOF) work();
    return 0;
}
