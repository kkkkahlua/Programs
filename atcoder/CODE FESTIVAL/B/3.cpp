#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
typedef long long LL;
struct Edge {
    int to, ne;
    Edge(int _to=0, int _ne=0): to(_to), ne(_ne) {}
}edge[maxn*2];
int tot, ne[maxn];
void add(int u, int v) {
    edge[tot] = Edge(v, ne[u]);
    ne[u] = tot++;
}
int n, m, c[maxn];
void dfs(int u, int col) {
    c[u] = col;
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (c[v] == -1) dfs(v, !col);
        if (c[v] != !col) { printf("%lld\n", 1LL*n*(n-1)/2-m); exit(0); }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    memset(c, -1, sizeof(c));
    memset(ne, -1, sizeof(ne));
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }
    dfs(1, 0);
    int b=0, w=0;
    for (int i = 1; i <= n; ++i) if (c[i]) ++b; else ++w;
    printf("%lld\n", 1LL*b*w-m);
    return 0;
}
