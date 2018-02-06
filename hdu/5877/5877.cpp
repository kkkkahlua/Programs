#include <bits/stdc++.h>
#define maxn 200010
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long LL;
LL c[maxn], val[maxn], k, a[maxn], ans;
int ne[maxn], tot, cnt, n, le[maxn], ri[maxn], rev[maxn], inv[maxn], q, ind[maxn];
map<int, set<int> > m;
map<LL, int> nval;
struct Edge {
    int to, ne;
    Edge(int a = 0, int b = 0) : to(a), ne(b) {}
}edge[maxn];
struct Ans { int pre, suc; }rec[maxn];
void addEdge(int u, int v) {
    edge[tot] = Edge(v, ne[u]);
    ne[u] = tot++;
}
int lowbit(int x) { return x & -x; }
void add(int x, LL d) { while (x <= n) c[x] += d, x += lowbit(x); }
LL query(int x) { LL ret = 0; while (x) ret += c[x], x -= lowbit(x); return ret; }
void dfs(int u, int fa) {
    add(lower_bound(a, a+q, val[u]) - a + 1, 1);
    LL temp = query(lower_bound(a, a+q, val[u] ? k / val[u] : inf) - a + 1);
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (v == fa) continue;
        dfs(v, u);
    }
//    printf("%d %lld %lld\n", u, temp, query(lower_bound(a,a+q,val[u]?k/val[u] : inf)-a+1));
    ans += query(lower_bound(a, a+q, val[u] ? k/val[u] : inf) - a + 1) - temp;
}
void work() {
    tot = ans = 0;
    memset(ne, -1, sizeof(ne));
    memset(ind, 0, sizeof(ind));

    scanf("%d%lld", &n, &k);
    q = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &val[i]);
        a[q++] = val[i], a[q++] = val[i] ? k / val[i] : inf;
    }
    sort(a, a+q);
    q = unique(a, a + q) - a;

    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(u, v);
        ++ind[v];
    }
    int root;
    for (int i = 1; i <= n; ++i) if (!ind[i]) { root = i; break; }
    dfs(root, -1);
    printf("%lld\n", ans);
}
int main() {
    freopen("5877.in", "r", stdin);
    freopen("5877.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
