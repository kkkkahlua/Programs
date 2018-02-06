#include <cstdio>
#include <cstring>
#define maxn 1010
#define maxm 6010
#include <stack>
#define inf 0x3f3f3f3f
using namespace std;
stack<int> s;
int dfn[maxn], low[maxn], ne[maxn], ne2[maxn], belong[maxn], ind[maxn], tot, tot2, cnt, scc, in[maxn], kas, dep[maxn], vis[maxn];
bool ok;
struct Edge {
    int from, to, ne;
    Edge(int a = 0, int b = 0, int c = 0) : from(a), to(b), ne(c) {}
}edge[maxm], edge2[maxm];
void add(int u, int v) {
    edge[tot] = Edge(u, v, ne[u]);
    ne[u] = tot++;
}
void add2(int u, int v) {
    edge2[tot2] = Edge(u, v, ne2[u]);
    ne2[u] = tot2++;
}
void init() {
    tot = 0;
    memset(ne, -1, sizeof(ne));
}
void init2() {
    tot2 = 0; ok = false;
    memset(vis, 0, sizeof(vis));
    memset(ne2, -1, sizeof(ne2));
    memset(dep, 0, sizeof(dep));
}
void tarjanInit() {
    cnt = scc = 0;
    while (!s.empty()) s.pop();
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(ind, 0, sizeof(ind));
    memset(in, 0, sizeof(in));
}
void tarjan(int u) {
    dfn[u] = low[u] = ++cnt;
    in[u] = true;
    s.push(u);
    for (int i = ne[u]; i != -1; i = edge[i].ne) {
        int v = edge[i].to;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (in[v]) low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u]) {
        ++scc;
        while (true) {
            int v = s.top();
            in[v] = false;
            s.pop();
            belong[v] = scc;
            if (v == u) break;
        }
    }
}
void contract() {
    init2();
    for (int i = 0; i < tot; ++i) {
        int u = edge[i].from, v = edge[i].to;
        if (belong[u] == belong[v]) continue;
        add2(belong[u], belong[v]);
        ++ind[belong[v]];
    }
}
void dfs(int u) {
    vis[u] = true;
    dep[u] = 1;
    for (int i = ne2[u]; i != -1; i = edge2[i].ne) {
        int v = edge2[i].to;
        if (!vis[v]) dfs(v);
        dep[u] = max(dep[u], dep[v] + 1);
    }
}
void work() {
    int n, m;
    init(); tarjanInit();
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
    }
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) tarjan(i);
    }
    contract();
    for (int i = 1; i <= scc; ++i) {
        if (!ind[i]) { dfs(i); if (dep[i] == scc) ok = true; break; }
    }
    if (ok) printf("I love you my love and our love save us!\n");
    else printf("Light my fire!\n");
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
