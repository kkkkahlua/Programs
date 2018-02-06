#include <cstdio>
#include <cstring>
#define maxn 100010
#include <stack>
#define inf 0x3f3f3f3f
using namespace std;
stack<int> s;
int dfn[maxn], low[maxn], ne[maxn], sz[maxn], belong[maxn], outd[maxn], tot, cnt, scc, in[maxn];
struct Edge {
    int from, to, ne;
    Edge(int a = 0, int b = 0, int c = 0) : from(a), to(b), ne(c) {}
}edge[maxn];
void add(int u, int v) {
    edge[tot] = Edge(u, v, ne[u]);
    ne[u] = tot++;
}
void init() {
    tot = cnt = scc = 0;
    while (!s.empty()) s.pop();
    memset(ne, -1, sizeof(ne));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(outd, 0, sizeof(outd));
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
        ++scc; sz[scc] = 0;
        while (true) {
            int v = s.top();
            in[v] = false;
            s.pop();
            ++sz[scc];
            belong[v] = scc;
            if (v == u) break;
        }
    }
}
void contract() {
    for (int i = 0; i < tot; ++i) {
        int u = edge[i].from, v = edge[i].to;
        if (belong[u] == belong[v]) continue;
        ++outd[belong[u]];
    }
}
int n, m;
void work() {
    init();
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
    }
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) tarjan(i);
    }
    contract();
    int num = 0, p;
    for (int i = 1; i <= scc; ++i) {
        if (!outd[i]) {
            ++num, p = i;
            if (num > 1) break;
        }
    }
    if (num > 1) printf("0\n");
    else printf("%d\n", sz[p]);
}
int main() {
    while (scanf("%d%d", &n, &m) != EOF) work();
    return 0;
}
