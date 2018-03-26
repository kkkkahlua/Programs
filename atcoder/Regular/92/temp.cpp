#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 1010
#define maxm 200010
using namespace std;
typedef long long LL;
int f[maxn][maxn][2], vis[maxn<<1], T;
struct node {int to, id; };
vector<node> edge[maxn];
pair<int, int> E[maxm];
void dfs(int u, int src, int id, int type) {
    f[src][u][type] = id; vis[u] = T;
    for (auto& e : edge[u]) {
        int v = e.to;
        if (vis[v]!=T) dfs(v, src, id, type);
    }
}
void work(int src) {
    ++T; vis[src] = T;
    for (auto& e : edge[src]) {
        int v = e.to;
        if (vis[v]!=T) dfs(v, src, e.id, 0);
    }

    reverse(edge[src].begin(), edge[src].end());
    ++T; vis[src] = T;
    for (auto& e : edge[src]) {
        int v = e.to;
        if (vis[v]!=T) dfs(v, src, e.id, 1);
    }
}
int main() {
//    freopen("in.txt", "r", stdin);
    int n, m, u, v;
    scanf("%d%d", &n ,&m);
    F2(i, 1, m) {
        scanf("%d%d", &u, &v);
        edge[u].push_back({v, i});
        E[i] = {u, v};
    }
    F2(i, 1, n) work(i);
//    F2(i, 1, n) {
//        F2(j, 1, n) printf("%d ", f[i][j][0]); puts("");
//    }
//    F2(i, 1, n) {
//        F2(j, 1, n) printf("%d ", f[i][j][1]); puts("");
//    }
    F2(i, 1, m) {
        int u = E[i].first, v = E[i].second;
        if (f[v][u][0]!=0 ^ (f[u][v][0]!=i||f[u][v][1]!=i)) puts("diff");
        else puts("same");
    }
    return 0;
}
