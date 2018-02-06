#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
typedef long long LL;
struct Edge {
    int to, d;
    Edge(int a = 0, int b = 0) : to(a), d(b) {}
};
struct node {
    LL dist; int cnt;
    bool operator < (const node& nd) const { return dist < nd.dist; }
    node(int a = 0, int b = 0) : dist(a), cnt(b) {}
}ans[maxn];
priority_queue<node> q;
vector<Edge> edge[maxn];
int n, k;
LL dist[maxn];
void dfs(int u, int fa) {
    for (auto e : edge[u]) {
        int v = e.to, d = e.d;
        if (v == fa) continue;
        dist[v] = dist[u] + d;
//        printf("v : %d %d %lld\n", v, edge[v].size(), dist[v]);
        if (edge[v].size() > 1) q.push(node(dist[v], edge[v].size() - 1));
        dfs(v, u);
    }
}
void work() {
    LL anss = 0;
    for (int i = 1; i <= n; ++i) edge[i].clear();
    memset(dist, 0, sizeof(dist));
    for (int i = 0; i < n - 1; ++i) {
        int x, y, d;
        scanf("%d%d%d", &x, &y, &d);
        anss += d;
        edge[x].push_back(Edge(y, d));
        edge[y].push_back(Edge(x, d));
    }
    dist[1] = 0;
    while (!q.empty()) q.pop();
    dfs(1, -1);
    int tot = 0, t = 0;
//    while (!q.empty()) {
//        node x = q.top();
//        printf("%lld %d\n", x.dist, x.cnt);
//        q.pop();
//    }
    k -= edge[1].size();
    while (true) {
        if (q.empty()) break;
        node now = q.top();
//        printf("%d\n", tot);
        if (tot + now.cnt >= k) {
            ans[t++] = node(now.dist, k - tot);
            break;
        }
        tot += now.cnt;
        ans[t++] = now;
        q.pop();
    }
    for (int i = 0; i < t; ++i) {
        anss += ans[i].dist * ans[i].cnt;
    }
    printf("%lld\n", anss);
}
int main() {
//    freopen("多校第三场数据和标程/数据/1005.in", "r", stdin);
    freopen("in.txt", "r", stdin);
    while (scanf("%d%d", &n, &k) != EOF) work();
    return 0;
}
