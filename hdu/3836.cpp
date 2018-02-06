#include <bits/stdc++.h>
#include <stack>
#define maxn 20010
#define maxm 50010
using namespace std;
stack<int> s;
int dfn[maxn], low[maxn], ne[maxn], in[maxn], belong[maxn], ind[maxn], outd[maxn], cnt, tot, scc;
struct Edge {
    int from, to, ne;
    Edge(int a = 0, int b = 0, int c = 0) : from(a), to(b), ne(c) {}
}edge[maxm];
void add(int u, int v) {
    edge[tot] = Edge(u, v, ne[u]);
    ne[u] = tot++;
}
void init() {
    cnt = tot = scc = 0;
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(ne, -1, sizeof(ne));
    memset(in, 0, sizeof(in));
    memset(ind, 0, sizeof(ind));
    memset(outd, 0, sizeof(outd));
    while (!s.empty()) s.pop();
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
            if (u == v) break;
        }
    }
}
void contract() {
    for (int i = 0; i < tot; ++i) {
        int u = edge[i].from, v = edge[i].to;
        if (belong[u] == belong[v]) continue;
        ++outd[belong[u]], ++ind[belong[v]];
    }
}
int n, m;
void work() {
    init();
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
    }
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) tarjan(i);
    }
    if (scc == 1) {
        printf("0\n");
        return;
    }
    contract();
    int intot = 0, outtot = 0;
    for (int i = 1; i <= scc; ++i) {
        if (!ind[i]) ++intot;
        if (!outd[i]) ++outtot;
    }
    printf("%d\n", max(intot, outtot));
}
int main() {
    int T; scanf("%d", &T);
    while (scanf("%d%d", &n, &m) != EOF) work();
    return 0;
}
