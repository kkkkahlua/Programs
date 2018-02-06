#include <bits/stdc++.h>
#define maxn 1010
#define maxm 1000010
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;
double dist[maxm], maxx[maxn][maxn], len, dd[maxn][maxn];
int x[maxn], y[maxn], p[maxn], n, pre[maxn];
bool vis[maxn], in[maxn][maxn];
struct node {
    int v, u;
    double c;
    bool operator < (const node nd) const { return c > nd.c; }
};
priority_queue<node> q;
void prim(int src) {
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < n; ++i) dist[i] = 10000000;
    vis[src] = true;
    while (!q.empty()) q.pop();
    double temp=0;
    for (int i = 1; i < n; ++i) {
        for (int v = 0; v < n; ++v) {
            if (v == src) continue;
            if (vis[v]) {
                maxx[v][src] = maxx[src][v] = max(maxx[pre[src]][v], temp);
                continue;
            }
            if (vis[v]) continue;
            if (dd[src][v] < dist[v]) {
                dist[v] = dd[src][v];
                q.push(node{v, src, dd[src][v]});
            }
        }
        while (!q.empty() && vis[q.top().v]) q.pop();
        if (q.empty()) break;
        len += (temp = q.top().c);
        in[q.top().v][q.top().u] = in[q.top().u][q.top().v] = true;
        pre[q.top().v] = q.top().u;
        vis[src = q.top().v] = true;
    }
    for (int v = 0; v < n; ++v) {
        if (v == src) continue;
        maxx[v][src] = maxx[src][v] = max(maxx[v][pre[src]], temp);
    }
}
double dis(int u, int v) { return sqrt((x[u]-x[v])*(x[u]-x[v])+(y[u]-y[v])*(y[u]-y[v])); }
void init() {
    len = 0;
    memset(in, 0, sizeof in); memset(maxx, 0, sizeof maxx); memset(pre, 0, sizeof pre);
}
void work() {
    scanf("%d", &n);
    init();
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &x[i],&y[i],&p[i]);
        for (int j = 0; j < i; ++j) {
            double d = dis(i, j);
            dd[i][j] = dd[j][i] = d;
        }
    }
    prim(0);
    double ans=0, rat;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            double a = p[i]+p[j];
            if (in[i][j]) rat = a / (len - dd[i][j]);
            else rat = a / (len - maxx[i][j]);
            ans = max(ans, rat);
        }
    }
    printf("%.2f\n", ans);
}
int main() {
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
