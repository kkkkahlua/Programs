#include <bits/stdc++.h>
#define maxn 1010
#define maxp 1010
#define inf 0x3f3f3f3f
#define id1(i,j) (idx(i,j)<<1)
#define id2(i,j) (id1(i,j)|1)
using namespace std;
typedef long long LL;
int dep[maxp], cur[maxp], n, m, tot, k, ne[maxp];
char cnt[maxn][maxn], s[maxn];
inline int idx(int i, int j) { return (i-1)*m+j; }
inline bool check(int i, int j) { return i > 0 && i <= n && j > 0 && j <= m && cnt[i][j]!='0'; }
struct Edge { int to, ne, c; }edge[maxp<<4];
void add(int u, int v, int c) {
    edge[tot] = {v, ne[u], c};
    ne[u] = tot++;
    edge[tot] = {u, ne[v], 0};
    ne[v] = tot++;
}
void init() {
    tot = 0; memset(ne, -1, sizeof(ne));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (cnt[i][j] == '0') continue;
            if (i-k <= 0 || i+k > n || j-k <= 0 || j+k > m) { add(id1(i,j), 1, cnt[i][j]-'0'); continue; }
            add(id1(i,j), id2(i,j), cnt[i][j]-'0');
            for (int r = i-k; r <= i+k; ++r) {
                for (int c = j-k; c <= j+k; ++c) {
                    if (abs(i-r)+abs(j-c) > k) continue;
                    if (check(r, c)) add(id2(i, j), id1(r, c), inf);
                }
            }
        }
    }
}
int bfs(int src) {
    queue<int> q;
    while (!q.empty()) q.pop();
    memset(dep, 0, sizeof(dep));
    dep[src] = 1;
    q.push(src);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = ne[u]; ~i; i = edge[i].ne) {
            int v = edge[i].to;
            if (edge[i].c > 0 && !dep[v]) {
                dep[v] = dep[u]+1;
                q.push(v);
            }
        }
    }
    return dep[1];
}
int dfs(int u, int flow) {
    if (u == 1) return flow;
    for (int& i = cur[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (edge[i].c > 0 && dep[v]-dep[u]==1) {
            int c = dfs(v, min(flow, edge[i].c));
            if (c) {
                edge[i].c -= c;
                edge[i^1].c += c;
                return c;
            }
        }
    }
    return 0;
}
int kas;
void work() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", cnt[i]+1);
    }
    m = strlen(cnt[1]+1);
    init();

    int all = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s+1);
        for (int j = 1; j <= m; ++j) {
            if (s[j] == 'L') ++all, add(0, id1(i,j), 1);
        }
    }

    int pcnt = id2(n, m)+1, ans=0, ret;
    while (bfs(0)) {
        for (int i = 0; i < pcnt; ++i) cur[i] = ne[i];
        while (ret = dfs(0, inf)) ans += ret;
    }
    ans = all-ans;
    printf("Case #%d: ", ++kas);
    if (!ans) puts("no lizard was left behind.");
    else if (ans==1) puts("1 lizard was left behind.");
    else printf("%d lizards were left behind.\n", ans);
}
int main() {
    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
