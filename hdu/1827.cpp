#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#include <stack>
#include <vector>
#define maxn 1010
using namespace std;
typedef long long LL;
stack<int> s;
vector<int> bcc[maxn];
struct Edge {
    int from, to, ne;
    Edge(int a=0, int b =0, int c = 0) : from(a), to(b), ne(c) {}
}edge[maxn * 2];
int dfn[maxn], low[maxn], ne[maxn], belong[maxn], deg[maxn], tot, cnt, scc, val[maxn];
bool in[maxn];
void add(int u, int v) {
    edge[tot] = Edge(u, v, ne[u]);
    ne[u] = tot++;
}
void init() {
    cnt = tot = scc = 0;
    while (!s.empty()) s.pop();
    memset(ne, -1, sizeof(ne));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(belong, 0, sizeof(belong));
    memset(deg, 0, sizeof(deg));
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
        bcc[scc].clear();
        while (true) {
            int v = s.top();
            in[v] = false;
            s.pop();
            belong[v] = scc;
            bcc[scc].push_back(v);
            if (v == u) break;
        }
    }
}
void contract() {
    for (int i = 0; i < tot; ++i) {
        int u = edge[i].from, v = edge[i].to;
        if (belong[u] == belong[v]) continue;
        ++deg[belong[v]];
    }
}
int n, m;
void work() {
    init();
    for (int i = 1; i <= n; ++i) scanf("%d", &val[i]);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
    }
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) tarjan(i);
    }
    contract();
    LL ans = 0; int anc = 0;
    for (int i = 1; i <= scc; ++i) {
        if (deg[i] == 0) {
            ++anc;
            int minn = inf;
            for (auto x : bcc[i]) minn = min(minn, val[x]);
            ans += minn;
        }
    }
    printf("%d %lld\n", anc, ans);
}
int main() {
    while (scanf("%d%d", &n, &m) != EOF) work();
    return 0;
}
