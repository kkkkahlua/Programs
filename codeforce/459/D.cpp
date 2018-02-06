#include <bits/stdc++.h>
#define maxn 110
#define maxm 5010
using namespace std;
typedef long long LL;
int mp[maxn][maxn];
int ne[maxn], tot;
struct Edge { int to, ne, w; }edge[maxm << 1];
bool vis[maxn][maxn][26], dp[maxn][maxn][26];
void add(int u, int v, int c) {
    edge[tot] = {v, ne[u], c};
    ne[u] = tot++;
}
int dfs(int u, int v, int ch) {
    if (vis[u][v][ch]) return dp[u][v][ch];
    vis[u][v][ch] = true;
    if (u == v) return false;
    if (mp[u][v]) {
//        printf("%d %d %d %d\n", u, v, ch, mp[u][v]);
        if (ch <= mp[u][v]) return dp[u][v][ch] = true;
    }
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int x = edge[i].to; char ww = edge[i].w;
        if (ch <= ww && !dfs(v, x, ww)) return dp[u][v][ch] = true;
    }
    return false;
}
int main() {
    freopen("in.txt", "r", stdin);
    memset(ne, -1, sizeof ne);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v; char c;
        scanf("%d%d %c", &u, &v, &c);
        mp[u][v] = c-'a';
        add(u, v, c-'a');
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            putchar(dfs(i, j, 0) ? 'A' : 'B');
        }
        puts("");
    }
    return 0;
}
