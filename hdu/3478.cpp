#include <bits/stdc++.h>
#define maxm 500010
#define maxn 100010
using namespace std;
typedef long long LL;
struct Edge {
    int to, ne;
    Edge(int _to=0, int _ne=0) : to(_to), ne(_ne) {}
}edge[maxm * 2];
int tot, ne[maxn], col[maxn];
void add(int u, int v) {
    edge[tot] = Edge(v, ne[u]);
    ne[u] = tot++;
}
bool flag;
void dfs(int u, int c) {
    col[u] = c;
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (col[v]==-1) dfs(v, !c);
        else if (col[v] != !c) flag=true;
    }
}
int kas;
void work() {
    printf("Case %d: ", ++kas);
    int n, m, x;
    flag = tot = 0; memset(ne, -1, sizeof(ne)); memset(col, -1, sizeof(col));
    scanf("%d%d%d", &n, &m, &x);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v); add(v, u);
    }
    dfs(x, 0);
    for (int i = 0; i < n; ++i) if (col[i] == -1) { printf("NO\n"); return; }
    if (flag) printf("YES\n");
    else printf("NO\n");
}
int main() {
    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
