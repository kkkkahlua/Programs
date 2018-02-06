#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
typedef long long LL;
struct Edge {
    int to, ne;
}edge[maxn];
int c[maxn], p[maxn], n, tot, ne[maxn];
void add(int u, int v) {
    edge[tot] = {v, ne[u]};
    ne[u] = tot++;
}
int ans;
queue<int> q;
void bfs(int src) {
    while (!q.empty()) q.pop();
    q.push(src);
    ans = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = ne[u]; ~i; i = edge[i].ne) {
            int v = edge[i].to;
            if (c[u] != c[v]) ++ans;
            q.push(v);
        }
    }
}
int main() {
    tot = 0; memset(ne, -1, sizeof ne);
    scanf("%d", &n);
    for (int i = 2; i <= n; ++i) {
        scanf("%d", &p[i]);
        add(p[i], i);
    }
    for (int i = 1; i <= n; ++i) scanf("%d", &c[i]);
    bfs(1);
    printf("%d\n", ans);
    return 0;
}
