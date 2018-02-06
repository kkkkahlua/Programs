#include <stdio.h>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define maxm 200010
#define maxn 1010
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;
int n, m, x;
struct Edge { int to, ne, c; }edge[maxm];
int dep[maxn], ne[maxn], f,d, tot, s,t, vis[maxn];
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
    freopen("in.txt", "r", stdin);
    scanf("%d%d", &m, &n);
    s = 0, t = n+m+1, tot = 0, memset(ne, -1, sizeof(ne));
    memset(vis, -1, sizeof(vis));
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &x);
        add(n+i, t, x);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x);
        while (x--) {
            int y;
            scanf("%d", &y);
            if (~vis[y]) add(i, vis[y], inf);
            vis[y] = i;
            add(i, n+y, inf);
        }
        scanf("%d", &x);
        add(s, i, x);
    }
    int ans=0, ret;
    while (bfs(s)) {
        while (ret = dfs(s, inf)) ans += ret;
    }
    printf("%d\n", ans);
    char* p = (char*)main;
    char mainn = (char)main;
    printf("%c %x %x %c\n", *p, *p, p, mainn);
    return 0;
}
