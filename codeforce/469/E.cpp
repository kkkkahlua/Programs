#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 100010
using namespace std;
typedef long long LL;
int dfn[maxn], low[maxn], ne[maxn], belong[maxn], a[maxn], sz[maxn], scc, cnt, tot, outd[maxn];
stack<int> s;
bool in[maxn];
struct Edge { int from, to, ne; }edge[maxn<<1];
void add(int u, int v) {
    edge[tot] = {u, v, ne[u]};
    ne[u] = tot++;
}
void tarjan(int u) {
    dfn[u] = low[u] = ++cnt;
    in[u] = true;
    s.push(u);
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (in[v]) low[u] = min(low[u], dfn[v]);
    }
    if (low[u]==dfn[u]) {
        ++scc;
        while (true) {
            int v = s.top(); in[v] = false; s.pop();
            belong[v] = scc; ++sz[scc];
            if (u==v) break;
        }
    }
}
void contrast() {
    F(i, 0, tot) {
        int u = edge[i].from, v = edge[i].to;
        if (belong[u]==belong[v]) continue;
        ++outd[belong[u]];
    }
}
int main() {
    memset(ne, -1, sizeof ne);
    int n, m, h, u, v;
    scanf("%d%d%d", &n, &m, &h);
    F2(i, 1, n) scanf("%d", &a[i]);
    F(i, 0, m) {
        scanf("%d%d", &u,&v);
        if (a[u]>a[v]) swap(u, v);
        if (a[v]-a[u]==1) add(u, v);
        if (a[v]-a[u]==h-1) add(v, u);
    }
    F2(i, 1, n) if (!dfn[i]) tarjan(i);
    contrast();
    int ans=n+1, p=-1;
    F2(i, 1, scc) {
        if (!outd[i]) {
            if (sz[i]<ans) ans=sz[i], p=i;
        }
    }
//    F2(i, 1, n) printf("%d ", belong[i]); puts("");
    printf("%d\n", ans);
    F2(i, 1, n) if (belong[i]==p) printf("%d ", i); puts("");
    return 0;
}
