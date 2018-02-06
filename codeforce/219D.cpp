#include <cstdio>
#include <cstring>
#define maxn 200010
struct Edge {
    int from, to, d, ne;
    Edge(int ss = 0, int tt = 0, int dd = 0, int nn = 0) :
        from(ss), to(tt), d(dd), ne(nn) {}
}edge[maxn * 2];
int tot = 0, next[maxn], rev[maxn][2], ans[maxn];
void add(int s, int t, int d) {
    Edge e(s, t, d, next[s]);
    edge[tot] = e;
    next[s] = tot++;
}
void dfs(int u, int fa) {
    rev[u][0] = 0;
    for (int i = next[u]; i != -1; i = edge[i].ne) {
        Edge e = edge[i];
        if (e.to == fa) continue;
        dfs(e.to, u);
        rev[u][0] += rev[e.to][0] + e.d;
    }
}
void dfs2(int u, int fa) {
    for (int i = next[u]; i != -1; i = edge[i].ne) {
        Edge e = edge[i];
        int v = e.to;
        if (v == fa) continue;
        rev[v][1] = rev[u][1] + 1 - e.d + (rev[u][0] - rev[v][0] - e.d);
        dfs2(e.to, u);
    }
}
int main() {
//    freopen("in.txt", "r", stdin);
    memset(next, -1, sizeof(next));
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int s, t;
        scanf("%d%d", &s, &t);
        add(s, t, 0);
        add(t, s, 1);
    }
    dfs(1, -1);
    dfs2(1, -1);
    int id = 1, tot = 0, ori = rev[1][0] + rev[1][1];
    ans[tot++] = id;
    for (int i = 2; i <= n; ++i) {
        int now = rev[i][0] + rev[i][1];
        if (now > ori) continue;
        if (now < ori) {
            id = i; tot = 0; ori = now;
        }
        ans[tot++] = i;
    }
//    for (int i = 1; i <= n; ++i) printf("%d ", rev[i][0]); printf("\n");
//    for (int i = 1; i <= n; ++i) printf("%d ", rev[i][1]); printf("\n");

    printf("%d\n", rev[id][0] + rev[id][1]);

    printf("%d", ans[0]);
    for (int i = 1; i < tot; ++i) printf(" %d", ans[i]);
    printf("\n");
    return 0;
}
