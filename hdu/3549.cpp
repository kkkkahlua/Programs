#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxm 1010
#define maxn 20
using namespace std;
typedef long long LL;
struct Edge {
    int to, ne, c;
}edge[maxm<<1];
int tot, ne[maxn], dep[maxn];
void add(int u, int v, int c) {
    edge[tot] = {v, ne[u], c};
    ne[u] = tot++;
}
int n, m, u, v, c;
int bfs(int src) {
    queue<int> q;
    while (!q.empty()) q.pop();
    memset(dep, 0, sizeof(dep));
    dep[src] = 1;
    q.push(src);
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
    return dep[n];
}
int dfs(int u, int flow) {
    if (u == n) return flow;
    int ret = 0;
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (edge[i].c > 0 && dep[v]-dep[u]==1) {
            int c = dfs(v, min(flow-ret, edge[i].c));
            edge[i].c -= c;
            edge[i^1].c += c;
            ret += c;
            if (ret == flow) break;
        }
    }
    if (!flow) dep[u] = 0;
    return ret;
}
int kas;
void work() {
    scanf("%d%d", &n, &m);
    tot = 0; memset(ne, -1, sizeof(ne));
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &c);
        add(u, v, c);
        add(v, u, 0);
    }
    int ans = 0, ret;
    while (bfs(1)) {
        while (ret = dfs(1, inf)) ans += ret;
    }
    printf("Case %d: %d\n", ++kas, ans);
}
int main() {
//    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
