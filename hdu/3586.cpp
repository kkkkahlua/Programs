#include <cstdio>
#include <cstring>
#include <iostream>
#define maxn 100010
using namespace std;
struct Edge {
    int from, to, cost, ne;
    Edge(int a = 0, int b = 0, int c = 0, int d = 0): from(a), to(b), cost(c), ne(d) {}
}edge[maxn * 2];
bool cut[maxn];
int ne[maxn], f[maxn], ok[maxn], tot, n, m, ans;
void add(int u, int v, int c) {
    Edge e(u, v, c, ne[u]);
    edge[tot] = e;
    ne[u] = tot++;
}
void dfs(int u, int fa, int lim) {
    f[u] = 0; ok[u] = false;
    bool flag = false;
    for (int i = ne[u]; i != -1; i = edge[i].ne) {
        Edge e = edge[i]; int v = e.to;
        if (v == fa) continue;
        flag = true;
        dfs(v, u, lim);
        if (!ok[v]) {
            if (e.cost <= lim) {
                f[u] += e.cost;
                cut[i] = true;
            }
            else return;
        }
        else {
            if (e.cost <= lim) {
                if (e.cost <= f[v]) {
                    f[u] += e.cost;
                    cut[i] = true;
                }
                else f[u] += f[v];
            }
        }
    }
    if (!flag) return;
    ok[u] = true;
}
void dfs2(int u, int fa, int& sum) {
    for (int i = ne[u]; i != -1; i = edge[i].ne) {
        if (cut[i]) {
            ans = max(ans, edge[i].cost);
            sum += edge[i].cost;
            continue;
        }
        Edge e = edge[i];
        if (e.to != fa) dfs2(e.to, u, sum);
    }
}
bool can(int lim) {
    memset(cut, 0, sizeof(cut));
    memset(ok, 0, sizeof(ok));
    dfs(1, -1, lim);
//    printf("%d %d\n", lim, ok[1]);
    if (ok[1]) return true;
    else return false;
}
void work() {
    memset(ne, -1, sizeof(ne));
    memset(f, 0, sizeof(f));
    tot = ans = 0;
    for (int i = 1; i < n; ++i) {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        add(x, y, c);
        add(y, x, c);
    }

    int l = 0, r = m;
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        if (can(mid)) r = mid;
        else l = mid;
    }
    if (can(l)) {
        int sum = 0;
        dfs2(1, -1, sum);
        if (sum <= m) { printf("%d\n", ans); return; }
    }
    if (can(r)) {
        int sum = 0;
        dfs2(1, -1, sum);
        if (sum <= m) { printf("%d\n", ans); return; }
    }
    printf("-1\n");
}
int main() {
    freopen("3586.in", "r", stdin);
    while (scanf("%d%d", &n, &m) != EOF && n + m) work();
    return 0;
}
