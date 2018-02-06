#include <bits/stdc++.h>
#define maxn 100010
int c[maxn], ans[maxn], n, p, ne[maxn], tot;
struct Edge {
    int to, ne;
    Edge(int a = 0, int b = 0) : to(a), ne(b) {}
}edge[maxn * 2];
void addEdge(int u, int v) {
    edge[tot] = Edge(v, ne[u]);
    ne[u] = tot++;
}
int lowbit(int x) { return x & -x; }
void add(int x, int d) { while (x <= n) c[x] += d, x += lowbit(x); }
int query(int x) { int ret = 0; while (x) ret += c[x], x -= lowbit(x); return ret; }
void dfs(int u, int fa) {
    add(u, 1);
    int temp = query(u);
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (v == fa) continue;
        dfs(v, u);
    }
    ans[u] = query(u) - temp;
}
void work() {
    tot = 0;
    memset(c, 0, sizeof c);
    memset(ne, -1, sizeof ne);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(u, v); addEdge(v, u);
    }
    dfs(p, -1);
    printf("%d", ans[1]);
    for (int i = 2; i <= n; ++i) printf(" %d", ans[i]); printf("\n");
}
int main() {
    while (scanf("%d%d", &n, &p) != EOF && n + p) work();
    return 0;
}
