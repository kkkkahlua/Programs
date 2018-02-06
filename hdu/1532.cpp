#include <bits/stdc++.h>
#define maxm 210
#define maxn 210
#define inf 0x7fffffff
using namespace std;
typedef long long LL;
int n, m, cur[maxn], tot, ne[maxn], dep[maxn];
struct Edge {
    int to, ne, c;
}edge[maxm<<1];
void add(int u, int v, int c) {
    edge[tot] = {v, ne[u], c};
    ne[u] = tot++;
}
int bfs(int src) {
    queue<int> q;
    while (!q.empty()) q.pop();
    memset(dep, 0, sizeof(dep));
    q.push(src);
    dep[src] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = ne[u]; ~i; i = edge[i].ne) {
            int v = edge[i].to;
            if (edge[i].c > 0 && !dep[v]) {
                dep[v] = dep[u]+1;
                q.push(v);
            }
        }
    }
    return dep[m];
}
int dfs(int u, int flow) {
    if (u == m) return flow;
    for (int& i = cur[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (edge[i].c > 0 && dep[v] == dep[u]+1) {
            int c = dfs(v, min(flow, edge[i].c));
            if (c) {
                edge[i].c -= c;
                edge[i^1].c += c;
                return c;
            }
        }
    }
    return 0;
}
void work() {
    tot = 0; memset(ne, -1, sizeof(ne));
    for (int i = 0; i < n; ++i) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        add(u, v, c);
        add(v, u, 0);
    }
    int ans = 0, ret;
    while (bfs(1)) {
        for (int i = 1; i <= m; ++i) cur[i] = ne[i];
        while (ret = dfs(1, inf)) ans += ret;
    }
    printf("%d\n", ans);
}
int main() {
//    freopen("in.txt", "r", stdin);
    while (scanf("%d%d", &n, &m) != EOF) work();
    return 0;
}
