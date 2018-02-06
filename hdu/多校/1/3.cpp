#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#define maxn 200010
using namespace std;
typedef long long LL;
int tot, tot2, kas, n, ne[maxn], dfn[maxn], sz[maxn], col[maxn];
LL ans;
struct Edge {
    int to, ne;
    Edge(int b = 0, int c = 0) :  to(b), ne(c) {}
}edge[maxn * 2];
Edge e;
stack<int> st[maxn];
void add(int u, int v) {
    edge[tot].to = v;
    edge[tot].ne = ne[u];
    ne[u] = tot++;
}
void dfs(int u, int fa) {
    sz[u] = 1; dfn[u] = ++tot2;
//    printf("%d\n", u);
    for (int i = ne[u]; i != -1; i = edge[i].ne) {
        e = edge[i]; int v = e.to;
        if (v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
        LL temp = sz[v];
        while (!st[col[u]].empty() && dfn[st[col[u]].top()] > dfn[u]) {
            int vv = st[col[u]].top();
            temp -= sz[vv];
            st[col[u]].pop();
        }
        ans -= temp * (temp - 1) >> 1;
    }
    st[col[u]].push(u);
}
void work() {
    memset(ne, -1, sizeof(ne));
    tot = tot2 = 0;
    for (int i = 1; i <= n; ++i) scanf("%d", &col[i]);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y);
        add(y, x);
    }
    ans = ((LL)n * (n - 1) >> 1) * (LL)n;
    dfs(1, -1);
    for (int i = 1; i <= n; ++i) {
        LL temp = n;
        while (!st[i].empty()) {
            int v = st[i].top();
            temp -= sz[v];
            st[i].pop();
        }
        ans -= temp * (temp - 1) >> 1;
    }
    printf("Case #%d: %lld\n", ++kas, ans);
}
int main() {
    freopen("1003.in", "r", stdin);
//    freopen("03.out", "w", stdout);
    while (scanf("%d", &n) != EOF) work();
    return 0;
}
