#include <bits/stdc++.h>
#define maxn 100010
#define maxm 200010
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long LL;
const LL mod = 1e9 + 7;
int ne[maxn], tot;
bool vis[maxn];
LL dist1[maxn], dist2[maxn], ways1[maxn], ways2[maxn];
struct Edge { int from, to, ne; LL w; }edge[maxm<<1];
void add(int u, int v, LL w) {
    edge[tot] = {u, v, ne[u], w};
    ne[u] = tot++;
}
struct node {
    int v; LL c;
    bool operator < (const node nd) const { return c > nd.c; }
};
int n;
void dfs(int src, LL* dist, LL* ways) {
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= n; ++i) dist[i] = inf;
    vis[src] = true; dist[src] = 0; ways[src] = 1;
    priority_queue<node> q;
    while (!q.empty()) q.pop();
    while (true) {
        for (int j = ne[src]; ~j; j = edge[j].ne) {
            int v = edge[j].to;
            if (vis[v]) continue;
            LL now = edge[j].w + dist[src];
            if (now == dist[v]) (ways[v] += ways[src]) %= mod;
            else if (now < dist[v]) {
                dist[v] = now; ways[v] = ways[src];
                q.push({v, now});
            }
        }
        while (!q.empty() && vis[q.top().v]) q.pop();
        if (q.empty()) break;
        vis[src = q.top().v] = true;
    }
}
int main() {
    memset(ne, -1, sizeof ne);
    int m, s, t;
    scanf("%d%d%d%d", &n,&m,&s,&t);
    for (int i = 0; i < m; ++i) {
        int u, v; LL w;
        scanf("%d%d%lld", &u,&v,&w);
        add(u, v, w), add(v, u, w);
    }
    dfs(s, dist1, ways1);
//    for (int i = 1; i <= n; ++i) printf("%lld ", dist1[i]); puts("");
//    for (int i = 1; i <= n; ++i) printf("%lld ", ways1[i]); puts("");
    dfs(t, dist2, ways2);
    assert(dist1[t] == dist2[s]);
    assert(ways1[t] == ways2[s]);
    LL ww = ways1[t];
    LL ans = ww * (ww-1) % mod;
//    printf("%lld\n", ans);
    LL dis = dist1[t];
    if (!(dis & 1)) {
        LL half = dis >> 1;
        for (int i = 1; i <= n; ++i) if (dist1[i] == half && dist2[i] == half) {
            LL temp = ways1[i] * ways2[i] % mod;
            ans = (ans - (temp * (temp-1)) % mod + mod) % mod;
        }
    }
//    printf("%lld\n", ans);
    for (int i = 0; i < m; ++i) {
        int id = i<<1,
            u = edge[id].from, v = edge[id].to;
        if (dist1[u] > dist1[v]) swap(u, v);
        if (dist1[u] + edge[id].w + dist2[v] == dis && (dist1[u]<<1) < dis && (dist2[v]<<1) < dis) {
            LL temp = ways1[u] * ways2[v] % mod;
            ans = (ans - (temp * (temp-1)) % mod + mod) % mod;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
