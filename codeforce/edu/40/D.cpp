#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 1010
struct Edge { int to, ne; }edge[maxn<<1];
int tot, ne[maxn], dist1[maxn], dist2[maxn];
bool vis[maxn], mp[maxn][maxn];
void add(int u, int v) {
    edge[tot] = {v, ne[u]};
    ne[u] = tot++;
}
struct node {
    int v, c;
    bool operator < (const node& nd) const { return c > nd.c; }
};
using namespace std;
typedef long long LL;
void dij(int src, int* dist) {
    memset(vis, 0, sizeof vis);
    memset(dist, 0x3f, maxn*sizeof(int));
    vis[src] = true; dist[src] = 0;
    priority_queue<node> q;
    while (true) {
//        printf("%d\n", src);
        for (int i = ne[src]; ~i; i = edge[i].ne) {
            int v = edge[i].to;
            if (vis[v]) continue;
            if (dist[src]+1<dist[v]) {
                dist[v] = dist[src]+1;
                q.push({v, dist[v]});
            }
        }
        while (!q.empty() && vis[q.top().v]) q.pop();
        if (q.empty()) break;
        vis[src=q.top().v] = true;
    }
}
int main() {
//    freopen("in.txt", "r", stdin);
    memset(ne, -1, sizeof ne);
    int n, m, s, t, u, v;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    F(i, 0, m) {
        scanf("%d%d", &u, &v);
        add(u, v), add(v, u);
        mp[u][v] = mp[v][u] = true;
    }
    dij(s, dist1);
    dij(t, dist2);
//    F2(i, 1, n) printf("%d ", dist1[i]); puts("");
//    F2(i, 1, n) printf("%d ", dist2[i]); puts("");
    int cur = dist1[t], ans = 0;
    F2(i, 1, n) {
        F2(j, i+1, n) {
            if (mp[i][j]) continue;
            if (dist1[i]+1+dist2[j]>=cur && dist2[i]+1+dist1[j]>=cur) ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}
