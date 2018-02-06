#include <bits/stdc++.h>
#define maxn 200010
using namespace std;
typedef long long LL;
int ne[maxn], tot, n, m, tag[maxn], l[maxn], r[maxn];
struct Edge { int to, ne; }edge[maxn<<1];
void add(int u, int v) {
    edge[tot] = {v, ne[u]};
    ne[u] = tot++;
}
vector<int> ans;
void bfs(int src) {
    queue<int> q;
    q.push(src);
    int sz = 0;
    while (!q.empty()) {
        ++sz;
        int u = q.front(); q.pop();
        for (int i = ne[u]; ~i; i = edge[i].ne) {
            tag[edge[i].to] = u;
        }
        for (int i = r[0]; i <= n; i = r[i]) {
            if (i != src && tag[i] != u) {
                q.push(i); r[l[i]] = r[i]; l[r[i]] = l[i];
            }
        }
    }
    ans.push_back(sz);
}
int main() {
    memset(ne, -1, sizeof ne);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v); add(v, u);
    }
    for (int i = 1; i <= n; ++i) r[i] = i+1, l[i] = i-1;
    r[0] = 1; l[n+1] = n;
    for (int i = r[0]; i <= n; ) {
        bfs(i);
        int temp = r[i];
        r[l[i]] = r[i], l[r[i]] = l[i];
        i = temp;
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (auto x : ans) printf("%d ", x); puts("");
    return 0;
}
