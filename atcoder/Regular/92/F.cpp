#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxm 200010
#define maxn 1010
using namespace std;
typedef long long LL;
struct Edge {
    int from, to, ne;
}edge[maxm];
int head[maxn], ne[maxm], pre[maxm], T, tot;
bool flag[maxn][maxn];
int f1[maxn][maxn], f2[maxn][maxn], vis[maxn<<1];
void add(int u, int v) {
    if (~ne[u]) pre[ne[u]] = tot;
    else head[u] = tot;
    edge[tot] = {u, v, ne[u]};
    ne[u] = tot++;
}
void dfs1(int src, int u) {
    flag[src][u] = true; vis[u] = T;
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (vis[v] != T) dfs1(src, v);
    }
}
void dfs2(int src, int exc, int u, int f[maxn][maxn]) {
    if (~f[exc][u]) return;
    f[exc][u] = src; vis[u] = T;
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (vis[v]!=T && v!=exc) dfs2(src, exc, v, f);
    }
}
int main() {
//    freopen("in.txt", "r", stdin);
    int n, m;
    memset(ne, -1, sizeof ne);
    memset(head, -1, sizeof head);
    memset(f1, -1, sizeof f1);
    memset(f2, -1, sizeof f2);
    scanf("%d%d", &n, &m);
    F(i, 0, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
    }
//    F2(i, 1, n) printf("%d\n", head[i]);
//    F(i, 0, m) printf("%d\n", pre[i]);
//    F2(i, 1, n) {
//        ++T; dfs1(i, i);
//    }
    F2(i, 1, n) {
        ++T;
        for (int j = ne[i]; ~j; j = edge[j].ne) {
            int v = edge[j].to;
            dfs2(j, i, edge[j].to, f1);
        }
        if (head[i]==-1) continue;
        ++T;
        for (int j = head[i]; ; j = pre[j]) {
//            printf("dfs2 : %d %d\n", i, j);
            int v = edge[j].to;
            dfs2(j, i, edge[j].to, f2);
            if (j==ne[i]) break;
        }
    }

//    F2(i, 1, n) {
//        F2(j, 1, n) printf("%d ", flag[i][j]); puts("");
//    }
    F2(i, 1, n) {
        F2(j, 1, n) printf("%d ", f1[i][j]); puts("");
    }
    F2(i, 1, n) {
        F2(j, 1, n) printf("%d ", f2[i][j]); puts("");
    }
    F(i, 0, m) {
        int u=edge[i].from, v=edge[i].to;
        if (f1[v][u]!=-1 ^ (f1[u][v]!=i||f2[u][v]!=i)) puts("diff");
        else puts("same");
    }
    return 0;
}
