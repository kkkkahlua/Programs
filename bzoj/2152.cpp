#include <bits/stdc++.h>
#define maxn 20010
using namespace std;
typedef long long LL;
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
int tot, ne[maxn];
LL ans, dis[maxn][3];
struct Edge {
    int to, ne, w;
    Edge(int _to=0, int _ne=0, int _w=0) : to(_to), ne(_ne), w(_w) {}
}edge[maxn * 2];
void add(int u, int v, int w) {
    edge[tot] = Edge(v, ne[u], w);
    ne[u] = tot++;
}
void dfs(int u, int fa) {
//    printf("%d:\n", u);
    dis[u][0] = 1;
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (v == fa) continue;
        dfs(v, u);
        int w = edge[i].w;
        for (int i = 0; i < 3; ++i) {
            ans += dis[u][i] * dis[v][(6-w-i)%3];
            dis[u][i] += dis[v][(i+3-w)%3];
        }
    }
}
int main() {
    freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    tot = 0; memset(ne, -1, sizeof(ne));
    for (int i = 1; i < n; ++i) {
        int u, v; int w;
        scanf("%d%d%d", &u, &v, &w);
        w %= 3;
        add(u, v, w); add(v, u, w);
    }
    dfs(1, -1);
    ans <<= 1;
    ans += n;
    LL d = gcd(ans, 1LL*n*n);
    printf("%lld/%lld\n", ans/d, 1LL*n*n/d);
    return 0;
}
