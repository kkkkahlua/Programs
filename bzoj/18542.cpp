#include <bits/stdc++.h>
#define maxn 10000
#define maxm 1000010
using namespace std;
typedef long long LL;
struct Edge {
    int to, ne;
    Edge(int _to=0, int _ne=0) : to(_to), ne(_ne) {}
}edge[maxm * 2];
int tot, ne[maxm], T, match[maxm], vis[maxm];
void add(int u, int v) {
    edge[tot] = Edge(v, ne[u]);
    ne[u] = tot++;
}
int find(int u) {
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (vis[v] != T) {
            vis[v] = T;
            if (!match[v] || find(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}
int main() {
    freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    tot = 0; memset(ne, -1, sizeof(ne));
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, i), add(y, i);
    }
    int i = 1;
    for (; i <= maxn; ++i) {
        ++T;
        if (!find(i)) break;
    }
    printf("%d\n", i-1);
    return 0;
}
