#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#define inf1 0x3f3f3f3f3f3f3f3f
#define inf2 0x3f3f3f3f
#define maxn 1010
#define maxm 200010
using namespace std;
typedef long long LL;
LL a[maxn][maxn], mx, d;
struct Edge { int to, ne, c; }edge[maxm];
int dep[maxn], ne[maxn], tmp[maxn], n,m, tot, s,t,num, x[maxn], y[maxn];
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
void floyd() {
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) a[i][j] = inf1;
    for (int i = 1; i <= n; ++i) a[i][i] = 0;
    while (m--) {
        int u, v;
        scanf("%d%d%lld", &u, &v, &d);
        a[u][v] = a[v][u] = min(a[u][v], d);
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (k==i||k==j) continue;
                a[i][j] = a[j][i] = a[i][k]+a[k][j] < a[i][j] ? a[i][k]+a[k][j] : a[i][j];
            }
        }
    }
    mx = 0;
    for (int i = 1; i <= n; ++i) for (int j = i+1; j <= n; ++j) if (a[i][j] != inf1) mx = max(mx, a[i][j]);
}
bool check(LL lim) {
    tot = 0; memset(ne, -1, sizeof ne);
    for (int i = 1; i <= n; ++i) {
        add(s, i, x[i]); add(n+i, t, y[i]);
        add(i, n+i, inf2);
    }
    int cnt = tot;
    for (int i = s; i <= t; ++i) tmp[i] = ne[i];
    for (int i = 1; i <= n; ++i) {
        for (int j = i+1; j <= n; ++j) {
            if (a[i][j] <= lim) add(i, n+j, inf2), add(j, n+i, inf2);
        }
    }
    int ans=0, ret=0;
    while (bfs(s)) {
        while (ret = dfs(s, inf2)) ans += ret;
    }
    return ans == num;
}
int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    s = 0, t = n<<1|1, num = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &x[i], &y[i]);
        num += x[i];
    }
    floyd();
    LL l = 0, r = mx;
    while (r > l) {
        LL mid = l+r>>1;
        if (check(mid)) r = mid;
        else l = mid+1;
    }
    if (check(l)) printf("%lld\n", l);
    else puts("-1");
    return 0;
}
