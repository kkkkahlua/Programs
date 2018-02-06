#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#define maxn 1010
#define maxm 10010
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;
struct Edge { int to, ne, c; }edge[maxm];
int dep[maxn], ne[maxn], n, m, tot, s,t, out[maxn], in[maxn];
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
void work() {
    scanf("%d%d", &n, &m);
    tot = 0; memset(ne, -1, sizeof ne);
    memset(out, 0, sizeof out); memset(in, 0, sizeof in);
    s = 0, t = n+1;
    for (int i = 0; i < m; ++i) {
        int u, v, t;
        scanf("%d%d%d", &u, &v, &t);
        if (!t) add(u, v, 2);
        ++out[u], ++in[v];
    }
    int cnt=0;
    for (int i = 1; i <= n; ++i) {
        if (abs(out[i]-in[i])&1) { puts("impossible"); return; }
        if (out[i] > in[i]) add(s, i, out[i]-in[i]), cnt += out[i]-in[i];
        else if (out[i] < in[i]) add(i, t, in[i]-out[i]);
    }
    int ret=0,ans=0;
    while (bfs(s)) {
        while (ret = dfs(s, inf)) ans += ret;
    }
    if (ans == cnt) puts("possible");
    else puts("impossible");
}
int main() {
    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
