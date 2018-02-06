#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
typedef long long LL;
using namespace std;
struct qnode {
    LL src, r;
    LL dist;
    qnode(LL _src = 0, LL _r = 0, LL _d = 0) : src(_src), r(_r), dist(_d) {}
    bool operator < (const qnode& q) const { return dist > q.dist; }
};
struct Edge {
    LL to, ne; LL dist;
    Edge(LL v = 0, LL d = 0, LL next = 0) : to(v), dist(d), ne(next) {}
}edge[10];
LL tot, ne[10], d[10];
void add(LL u, LL v, LL d) {
    edge[tot] = Edge(v, d, ne[u]);
    ne[u] = tot++;
}
priority_queue<qnode> q;
LL dist[5][60010], k;
inline LL min(LL a, LL b) { return a < b ? a : b; }
void bfs(LL src) {
    LL mod = 2LL * min(d[1], d[2]);
    for (LL i = 1; i <= 4; ++i) {
        for (LL j = 0; j < mod; ++j) dist[i][j] = inf;
    }
    q.push(qnode(src, 0, 0)); dist[2][0] = 0;
    while (!q.empty()) {
//        printf("%d\n", q.size());
        qnode nowf = q.top(); q.pop();
        LL u = nowf.src, x = nowf.r;
        if (nowf.dist > dist[u][x] || nowf.dist >= k + mod) continue;
        for (LL i = ne[u]; i != -1; i = edge[i].ne) {
            Edge e = edge[i]; LL v = e.to, nx = (x + e.dist) % mod;
            if (dist[u][x] + e.dist < dist[v][nx]) {
                dist[v][nx] = dist[u][x] + e.dist;
                q.push(qnode(v, nx, dist[v][nx]));
            }
        }
    }
    LL kmod = k % mod;
    LL diff = mod;
    for (LL i = 0; i < mod; ++i) {
        if (dist[2][i] <= k) {
            if (i >= kmod) diff = min(diff, (LL)i - kmod);
            else diff = min(diff, (LL)mod - (kmod - i));
        }
        else diff = min(diff, dist[2][i] - k);
    }
    printf("%lld\n", k + diff);
}
void work() {
    memset(ne, -1, sizeof(ne)); tot = 0;
    scanf("%lld%lld%lld%lld%lld", &k, &d[1], &d[2], &d[3], &d[4]);
    for (LL i = 1; i <= 4; ++i) {
        LL from = i, to = i % 4 + 1;
        add(from, to, d[i]); add(to, from, d[i]);
    }
    bfs(2);
}
int main() {
    freopen("多校第四场标程和数据/数据/1005.in", "r", stdin);
//    freopen("03.out", "w", stdout);
//    freopen("in.txt", "r", stdin);
    LL T;
    scanf("%lld", &T);
    while (T--) work();
    return 0;
}
