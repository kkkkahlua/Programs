#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#define maxn 320010
#define maxm 6050010
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long LL;
int tot, ne[maxn], dep[maxn], cur[maxn], n, m;
struct Edge { int to, ne; LL c; }edge[maxm];
void add(int u, int v, LL c) {
    edge[tot] = {v, ne[u], c};
    ne[u] = tot++;
}
int bfs(int src) {
    memset(dep, 0, sizeof dep);
    dep[src] = 1;
    queue<int> q;
    while (!q.empty()) q.pop();
    q.push(src);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = ne[u]; ~i; i = edge[i].ne) {
            int v = edge[i].to;
            if (edge[i].c > 0 && !dep[v]) dep[v] = dep[u] + 1, q.push(v);
        }
    }
    return dep[n+1];
}
LL dfs(int u, LL flow) {
    if (u == n+1) return flow;
    LL ret = 0;
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (edge[i].c > 0 && dep[v] == dep[u] + 1) {
            LL c = dfs(v, min(flow-ret, edge[i].c));
            edge[i].c -= c;
            edge[i^1].c += c;
            ret += c;
            if (ret == flow) break;
        }
    }
    if (!flow) dep[u] = 0;
    return ret;
}
int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    tot = 0, memset(ne, -1, sizeof(ne));
    for (int i = 1; i <= n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(0, i, a), add(i, 0, 0), add(i, n+1, b), add(n+1, i, b);
    }
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w); add(v, u, w);
    }
    LL ans=0, tmp=0;
    while (bfs(0)) {
        while (tmp = dfs(0, inf)) ans += tmp;
    }
    printf("%lld\n", ans);
    return 0;
}
