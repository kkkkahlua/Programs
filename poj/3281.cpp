#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
#define maxn 100010
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;
struct Edge { int to, ne, c; }edge[maxn];
int dep[maxn], ne[maxn], n,f,d, tot, s,t;
void add(int u, int v, int c) {
    edge[tot] = {v, ne[u], c};
    ne[u] = tot++;
    edge[tot] = {u, ne[v], 0};
    ne[v] = tot++;
}
int bfs(int src) {
    memset(dep, 0, sizeof dep);
    dep[src] = 1;
    queue<int> q;
    while (!q.empty()) q.pop();
    q.push(src);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = ne[u]; ~i; i = edge[i].ne) {
            int v = edge[i].to;
            if (edge[i].c > 0 && !dep[v]) dep[v] = dep[u] + 1, q.push(v);
        }
    }
    return dep[t];
}
int dfs(int u, int flow) {
    if (u == t) return flow;
    int ret = 0;
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (edge[i].c > 0 && dep[v] == dep[u] + 1) {
            int c = dfs(v, min(flow-ret, edge[i].c));
            edge[i].c -= c;
            edge[i^1].c += c;
            ret += c;
            if (ret == flow) break;
        }
    }
    if (!flow) dep[u] = 0;
    return ret;
}
int main() {
//    freopen("in.txt", "r", stdin);

    while (scanf("%d%d%d", &n, &f, &d) != EOF) {
        s = 0, t = f+2*n+d+1;
        tot = 0; memset(ne, -1, sizeof ne);
        for (int i = 1; i <= f; ++i) add(s, i, 1);
        for (int i = 1; i <= d; ++i) add(f+2*n+i, t, 1);
        for (int i = 1; i <= n; ++i) {
            int a,b,x;
            add(f+i, f+n+i, 1);
            scanf("%d%d", &a, &b);
            while (a--) {
                scanf("%d", &x);
                add(x, f+i, 1);
            }
            while (b--) {
                scanf("%d", &x);
                add(f+n+i, f+2*n+x, 1);
            }
        }
        int ans=0, tmp;
        while (bfs(s)) {
            while (tmp = dfs(s, inf)) ans += tmp;
        }
        printf("%d\n", ans);
    }
    return 0;
}
