#include <bits/stdc++.h>
#define maxm 600010
#define maxn 600010
using namespace std;
typedef long long LL;
int n, m, s, tot, ne[maxn], id[maxn], ans[maxn], cnt;
bool vis[maxn];
struct node {
    int u, v, t;
}a[maxm];
bool cmp(int i, int j) {
    return a[i].u < a[j].u || (a[i].u==a[j].u && a[i].v<a[j].v) || (a[i].u==a[j].u && a[i].v==a[j].v && a[i].t<a[j].t);
}
struct Edge {
    int to, ne, type, dir, id;
    Edge(int _to=0, int _ne=0, int _type=0, int _id=0, int _dir=-1):
        to(_to), ne(_ne), type(_type), dir(_dir), id(_id) {}
}edge[maxm];
void add(int type, int u, int v, int id) {
    edge[tot] = Edge(v, ne[u], type, id);
    ne[u] = tot++;
    if (type==2) edge[tot] = Edge(u, ne[v], type, id), ne[v] = tot++;
}
void dfs1(int u) {
    ++cnt;
    vis[u] = true;
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (vis[v]) continue;
        edge[i].dir = 1;
        dfs1(v);
    }
}
void dfs2(int u) {
    ++cnt;
    vis[u] = true;
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (vis[v]) continue;
        if (edge[i].type == 1) dfs2(v);
        else edge[i].dir = 0;
    }
}
void out() {
    printf("%d\n", cnt);
    for (int i = 0; i < tot; ++i) {
        if (edge[i].dir!=-1) ans[edge[i].id] = edge[i].to == a[edge[i].id].v ? edge[i].dir : !edge[i].dir;
    }
    for (int i = 1; i < m; ++i) {
        if (a[id[i]].u == a[id[i-1]].u && a[id[i]].v==a[id[i-1]].v && a[id[i]].t==a[id[i-1]].t) ans[id[i]] = ans[id[i-1]];
    }
    for (int i = 0; i < m; ++i) {
        if (a[i].t == 2) putchar(ans[i]==1 ? '+' : '-');
    }
    puts("");
}
int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 0; i < m; ++i) scanf("%d%d%d", &a[i].t, &a[i].u, &a[i].v), id[i] = i;
    sort(id, id+m, cmp);
    memset(ne, -1, sizeof(ne));
    add(a[id[0]].t, a[id[0]].u, a[id[0]].v, id[0]);
    for (int i = 1; i < m; ++i) {
        if (a[id[i]].u!=a[id[i-1]].u || a[id[i]].v!=a[id[i-1]].v || a[id[i]].t!=a[id[i-1]].t) add(a[id[i]].t, a[id[i]].u, a[id[i]].v, id[i]);
    }

    cnt = 0;
    dfs1(s);
    out();
    cnt = 0;

    for (int i = 1; i <= n; ++i) edge[i].dir = -1;
    memset(vis, 0, sizeof(vis));
    dfs2(s);
    out();
    return 0;
}
