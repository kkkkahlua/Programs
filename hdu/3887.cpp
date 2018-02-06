#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
struct Edge {
    int to, ne;
    Edge(int a = 0, int b = 0) : to(a), ne(b) {}
}edge[maxn * 2];
int ans[maxn], le[maxn], ri[maxn], c[maxn], cnt, tot, ne[maxn];
void addEdge(int u, int v) {
    edge[tot] = Edge(v, ne[u]);
    ne[u] = tot++;
}
void dfs(int u, int fa) {
    le[u] = ri[u] = ++cnt;
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (v == fa) continue;
        dfs(v, u);
        ri[u] = max(ri[u], ri[v]);
    }
}
int n, p;
inline int lowbit(int x) { return x & (-x); }
inline void add(int x, int del) { while (x <= n) c[x] += del, x += lowbit(x); }
inline int query(int x) { int ret = 0; while (x) ret += c[x], x -= lowbit(x); return ret; }
void work() {
    tot = cnt = 0;
    memset(ne, -1, sizeof(ne));
    memset(c, 0, sizeof(c));
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(u, v); addEdge(v, u);
    }
    dfs(p, -1);
    for (int i = 1; i <= n; ++i) add(i, 1);
//    for (int i = 1; i <= n; ++i) printf("%d %d\n", le[i], ri[i]);
    for (int i = n; i >= 1; --i) {
        ans[i] = query(ri[i]) - query(le[i]);
        add(le[i], -1);
    }
    printf("%d", ans[1]);
    for (int i = 2; i <= n; ++i) printf(" %d", ans[i]); printf("\n");
}
int main() {
    while (scanf("%d%d", &n, &p) != EOF && n + p) work();
    return 0;
}
