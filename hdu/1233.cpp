#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
typedef long long LL;
LL ans;
int ne[maxn], n, tot, dist[maxn];
bool vis[maxn];
struct Edge { int to, ne ,w; }edge[maxn<<1];
void add(int u, int v, int w) {
    edge[tot] = {v, ne[u], w};
    ne[u] = tot++;
}
struct node {
    int v, c;
    bool operator < (const node nd) const { return c > nd.c; }
};
priority_queue<node> q;
void prim(int src) {
    memset(vis, 0, sizeof vis);
    memset(dist, 0x3f, sizeof dist);
    vis[src] = true;
    while (!q.empty()) q.pop();
    for (int i = 1; i < n; ++i) {
        for (int j = ne[src]; ~j; j = edge[j].ne) {
            int v = edge[j].to;
            if (vis[v]) continue;
            if (edge[j].w < dist[v]) {
                dist[v] = edge[j].w;
                q.push(node{v, edge[j].w});
            }
        }
        while (!q.empty() && vis[q.top().v]) q.pop();
        if (q.empty()) break;
        vis[src = q.top().v] = true;
        ans += q.top().c;
    }
}
void work() {
    tot = 0; memset(ne, -1, sizeof ne);
    for (int i = 0; i < n*(n-1)/2; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w), add(v, u, w);
    }
    ans = 0; prim(1);
    printf("%lld\n", ans);
}
int main() {
//    freopen("in.txt", "r", stdin);
    while (scanf("%d", &n) != EOF && n) work();
    return 0;
}
