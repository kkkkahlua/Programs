#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define MAXN 40010
#define MAX 100010
using namespace std;
typedef long long LL;
int tot, n, m, cnt, a[MAX], dep[MAX], nextE[MAX], first[MAX], ele[20][MAX];
LL dis[MAX];
bool vis[MAX];
struct Edge { int u, v, nextE; LL w; }edge[MAX];
void addEdge(int u, int v, LL w) {
    edge[tot].u = u;
    edge[tot].v = v;
    edge[tot].w = w;
    edge[tot].nextE = nextE[u];
    nextE[u] = tot++;
}
void dfs(int root, int depth) {
//    printf("root : %d\n", root);
    vis[root] = true;
    if (first[root] == -1) first[root] = cnt;
    a[cnt] = root;
    dep[cnt++] = depth;
    int x = nextE[root];
    while (x != -1) {
//        printf("%d\n", x);
        Edge e = edge[x];
//        cout << e.u << " " << e.v << " " << e.w << " " << e.nextE << endl;
        x = e.nextE;
        if (vis[e.v]) continue;
        dis[e.v] = dis[root] + e.w;
        dfs(e.v, depth + 1);
        a[cnt] = root;
        dep[cnt++] = depth;
    }
}
void init() {
    for (int i = 0; i < cnt; ++i) { ele[0][i] = i; }

    for (int i = 1; (1 << i) < cnt; ++i) {
        for (int j = 1; j + (1 << i) < cnt; ++j) {
            ele[i][j] = dep[ele[i-1][j]] < dep[ele[i-1][j + (1 << i - 1)]] ? ele[i-1][j] : ele[i-1][j + (1 << i - 1)];
        }
    }
}
int rmq(int l, int r) {
    //printf("%d %d\n", l, r);
    int k = (int)(log((double)(r - l + 1)) / log(2.0));
    return dep[ele[k][l]] < dep[ele[k][r - (1 << k) + 1]] ? ele[k][l] : ele[k][r - (1 << k) + 1];
}
int query(int u, int v) {
    u = first[u], v = first[v];
    return a[rmq(u < v ? u : v, u > v ? u : v)];
}
void work() {
    memset(vis, 0, sizeof(vis));
    memset(nextE, -1, sizeof(nextE));
    memset(first, -1, sizeof(first));
    memset(dis, 0, sizeof(dis));
    tot = cnt = 0;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        LL w;
        scanf("%d%d%lld", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
//    cout << tot << endl;
//    for (int i = 0; i < tot; ++i) {
//        cout << edge[i].u << " " << edge[i].v << " " << edge[i].w << " " << edge[i].nextE << endl;
//    }
//    for (int i = 1; i <= n; ++i) printf("%d ", nextE[i]);
//    printf("\n");

    dfs(1, 0);
    init();
//    printf("%d\n", cnt);
//    for (int i = 0; i < cnt; ++i) {
//        printf("%d ", a[i]);
//    }
//    printf("\n");
//    for (int i = 0; i < cnt; ++i) {
//        printf("%d ", dep[i]);
//    }
//    printf("\n");
//    for (int i = 1; i <= n; ++i) {
//        printf("%d ", first[i]);
//    }
//    printf("\n");
//    for (int i = 1; i <= n; ++i) {
//        printf("%d ", dis[i]);
//    }
//    printf("\n");
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        int lca = query(u, v);
//        printf("lca : %d\n", lca);
        printf("%lld\n", dis[u] + dis[v] - 2 * dis[lca]);
    }
//    printf("\n");
}
int main() {
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    while (scanf("%d%d", &n, &m) != EOF) work();
    return 0;
}
