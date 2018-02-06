#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
#define maxn 1010
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;
struct Edge { int to, ne, c; }edge[maxn];
int dep[maxn], ne[maxn], n,tot, s,t, a[maxn];
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
bool getInt(int& x) {
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch=='\n') return false;
        ch = getchar();
    }
    x = ch-'0';
    return true;
}
bool tryy(int x) {
    tot=0; memset(ne,-1,sizeof(ne));
    s=0, t=n+n*(n-1)/2+1;
    for (int i = 1; i <= n; ++i) add(s, i, a[i]);
    for (int i = 1; i <= n*(n-1)/2; ++i) add(n+i, t, 1);
    int u=1, v=2;
    for (int i = 1; i <= n*(n-1)/2; ++i) {
        if (u >= x && a[v] > a[u]) add(u, n+i, 1);
        else add(u, n+i, 1), add(v, n+i, 1);
        ++v; if (v==n+1) v = ++u+1;
    }
    int ans=0, ret=0;
    while (bfs(s)) {
        while (ret = dfs(s, inf)) ans += ret;
    }
    return ans == n*(n-1)/2;
}
void work() {
    n = 0; while (getInt(a[++n])); --n;
    for (int i = n; i >= 1; --i) if (tryy(n-i+1)) {
        printf("%d\n", i); return;
    }
}
int main() {
    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d\n", &T);
    while (T--) work();
    return 0;
}
