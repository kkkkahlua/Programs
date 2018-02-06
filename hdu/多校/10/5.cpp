#include <bits/stdc++.h>
#include <queue>
#define maxn 100010
typedef long long LL;
using namespace std;
struct qnode {
    int v; LL c;
    qnode(int a = 0, LL b = 0) : v(a), c(b) {}
    bool operator < (const qnode nd) const {
        return c > nd.c;
    }
};
struct Edge {
    int from, to, ne; LL w;
    Edge(int f = 0, int a = 0, int b = 0, LL ww = 0) : from(f), to(a), ne(b), w(ww) {}
}edge[maxn * 2];
int ne[maxn], tot;
void add(int u, int v, LL w) {
    edge[tot] = Edge(u, v, ne[u], w);
    ne[u] = tot++;
}
LL dist[maxn], dist1[maxn], dist2[maxn];
bool vis[maxn];
priority_queue<qnode> pq;
vector<LL> ve;
int n, m, cnt1[maxn], cnt2[maxn], cnt[maxn];
void bfs(int src) {
    memset(dist, 0x3f, sizeof(dist));
    while (!pq.empty()) pq.pop();
    pq.push(src);
    dist[src] = 0;
    cnt[src] = 0;
    vis[src] = true;
    while (true) {
        for (int i = ne[src]; ~i; i = edge[i].ne) {
            int v = edge[i].to;
            if (dist[src] + edge[i].w < dist[v]) {
                dist[v] = dist[src] + edge[i].w;
                cnt[v] = cnt[src] + 1;
                pq.push(qnode(v, dist[v]));
            }
        }
        while (!pq.empty() && vis[pq.top().v]) pq.pop();
        if (pq.empty()) break;
        vis[src = pq.top().v] = true;
    }
//    for (int i = 1; i <= n; ++i) printf("%lld\n", dist[i]);

}
void work() {
    memset(ne, -1, sizeof(ne));
    tot = 0;
    scanf("%d%d", &n, &m);
    while (m--) {
        int u, v; LL w;
        scanf("%d%d%lld", &u, &v, &w);
        add(u, v, w); add(v, u, w);
    }
    memset(vis, 0, sizeof(vis));
    bfs(1);
    for (int i = 1; i <= n; ++i) dist1[i] = dist[i], cnt1[i] = cnt[i];
    memset(vis, 0, sizeof(vis));
    bfs(n);
    for (int i = 1; i <= n; ++i) dist2[i] = dist[i], cnt2[i] = cnt[i];
    ve.clear();
    for (int i = 0; i < tot; ++i) {
        int u = edge[i].from, v = edge[i].to; LL w = edge[i].w;
        ve.push_back(dist1[u]+dist2[v]+w);
    }
    sort(ve.begin(), ve.end());
//    for (auto x : ve) printf("%d ", x); printf("\n");
    printf("%lld\n", ve[cnt1[n]]);
//    for (int i = 1; i <= n; ++i) printf("%lld %d\n", dist1[i], cnt1[i]);
//    for (int i = 1; i <= n; ++i) printf("%lld %d\n", dist2[i], cnt2[i]);

}
int main() {
//    freopen("in.txt","r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
