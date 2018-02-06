#include <bits/stdc++.h>
#include <stack>
#define maxn 100010
using namespace std;
struct Edge {
    int to, ne;
    Edge(int a = 0, int b = 0) : to(a), ne(b) {}
}edge[maxn * 2];
int low[maxn], dfn[maxn], cnt, tot, ne[maxn], n, m, scc;
bool vis[maxn], in[maxn];
stack<int> s;
void add(int u, int v) {
    edge[tot] = Edge(v, ne[u]);
    ne[u] = tot++;
}
void dfs(int u) {
    vis[u] = true;
    low[u] = dfn[u] = cnt++;
    in[u] = true;
    s.push(u);
    for (int i = ne[u]; i != -1; i = edge[i].ne) {
        Edge e = edge[i]; int v = e.to;
        if (!vis[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if (in[v]) low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u]) {
        ++scc;
        if (scc == 2) return;
        while (true) {
            int x = s.top();
            s.pop(); in[x] = false;
            if (x == u) break;
        }
    }
}
void work() {
    memset(vis, 0, sizeof(vis));
    memset(ne, -1, sizeof(ne));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    cnt = tot = scc = 0;
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
    }
    bool flag = false;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) dfs(i);
        if (scc > 1) break;
    }
//    printf("%d\n", scc);
    if (scc == 1) printf("Yes\n");
    else printf("No\n");
}
int main() {
    freopen("in.txt", "r", stdin);
    while (scanf("%d%d", &n, &m) != EOF && n + m) work();
    return 0;
}
