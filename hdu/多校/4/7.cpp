#include <bits/stdc++.h>
#define mod 998244353
#define maxn 600010
typedef long long LL;
using namespace std;
queue<int> q;
struct Edge {
    int to, ne; LL dist;
    Edge(int a = 0, LL b = 0, int c = 0) : to(a), dist(b), ne(c) {}
}edge[maxn * 4];
bool vis[maxn];
int ne[maxn], d[maxn], tot;
LL val[maxn];
void add(int u, int v, LL d) {
    edge[tot] = Edge(v, d, ne[u]);
    ne[u] = tot++;
}
void dfs(int u, int rt) {
    vis[u] = true;
    if (u == rt) return;
    for (int i = ne[u]; i != -1; i = edge[i].ne) {
        Edge e = edge[i]; int v = e.to;
        if (vis[v]) continue;
        val[++tot] = e.dist;
        dfs(v, rt);
    }
}
void work() {
    memset(vis, 0, sizeof(vis));
    memset(d, 0, sizeof(d));
    int n;
    scanf("%d", &n);
    memset(ne, -1, sizeof(ne)); tot = 0;
    for (int i = 1; i <= n; ++i) {
        int v1, v2; LL w1, w2;
        scanf("%d%lld%d%lld", &v1, &w1, &v2, &w2);
        add(i, n + v1, w1); add(n + v1, i, w1);
        add(i, n + v2, w2); add(n + v2, i, w2);
        ++d[n + v1]; ++d[n + v2];
    }
    while (!q.empty()) q.pop();
    for (int i = n + 1; i <= (n << 1); ++i) if (d[i] == 1) q.push(i);
    LL ans = 1;
    while (!q.empty()) {
        int u = q.front(); vis[u] = true;
//        printf("%d\n", u);
        for (int i = ne[u]; i != -1; i = edge[i].ne) {
            if (vis[edge[i].to]) continue;
            Edge e = edge[i]; int v = e.to;
            vis[v] = true;
            ans *= e.dist; ans %= mod;
            for (int i = ne[v]; i != -1; i = edge[i].ne) {
                Edge e = edge[i]; int vv = e.to;
                if (vv == u) continue;
                --d[vv]; if (d[vv] == 1) q.push(vv);
            }
        }
        q.pop();
    }
//    printf("%lld\n", ans);
    for (int i = 1; i <= (n << 1); ++i) {
        if (vis[i]) continue;
        tot = 0;
        Edge e;
        val[++tot] = (e = edge[ne[i]]).dist;
        dfs(e.to, i);
        LL sum1 = 1, sum2 = 1;
        for (int j = 1; j <= tot; ++j) {
//            printf("%lld ", val[j]);
            if (j & 1) sum1 *= val[j], sum1 %= mod;
            else sum2 *= val[j], sum2 %= mod;
        }
//        printf("\n");
        ans *= (sum1 + sum2) % mod; ans %= mod;
    }
    printf("%lld\n", ans);
}
int main() {
    freopen("多校第四场标程和数据/数据/1007.in", "r", stdin);
//    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
