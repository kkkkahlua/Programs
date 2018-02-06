#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#define maxn 200010
using namespace std;
typedef long long LL;
LL n;
vector<int> col[maxn];
int kas, cnt, tot, ne[maxn], a[maxn * 2];
struct Edge {
    int to, ne;
    Edge(int a = 0, int b = 0) : to(a), ne(b) {}
}edge[maxn * 2];
struct Node {
    int l, r, sz, fa;
    Node(int a = -1, int b = -1, int c = 1) : l(a), r(b), sz(c) {}
}node[maxn];
void add(int x, int y) {
    Edge e(y, ne[x]);
    edge[tot] = e;
    ne[x] = tot++;
}
void dfs(int u, int fa) {
    node[u].fa = fa;
    a[cnt++] = u;
    node[u].sz = 1;
    for (int i = ne[u]; i != -1; i = edge[i].ne) {
        Edge e = edge[i]; int v = e.to;
        if (v == fa) continue;
        dfs(v, u);
        node[u].sz += node[v].sz;
    }
    a[cnt++] = u;
}
bool cmp(int u, int v) { return node[u].l < node[v].l; }
void work() {
    memset(ne, -1, sizeof(ne));
    tot = 0;
    cnt = 1;
    for (int i = 0; i <= n; ++i) {
        col[i].clear();
        node[i].l = node[i].r = -1;
    }
    for (int i = 1; i <= n; ++i) {
        int temp;
        scanf("%d", &temp);
        col[temp].push_back(i);
    }
    add(0, 1); add(1, 0);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y);
        add(y, x);
    }
    dfs(0, -1);
    for (int i = 0; i < cnt; ++i) {
        if (node[a[i]].l == -1) node[a[i]].l = i;
        else node[a[i]].r = i;
    }
//    printf("\n");
//    for (int i = 0; i <= n; ++i) {
//        printf("%d %d %d\n", i, node[i].l, node[i].r);
//    }
    LL ans = (n * (n - 1) >> 1) * n;
    for (int i = 1; i <= n; ++i) {
        if (col[i].empty()) {
            ans -= n * (n - 1) >> 1;
            continue;
        }
        col[i].push_back(0);
        sort(col[i].begin(), col[i].end(), cmp);
//        printf("%d\n", col[i].size());
        for (auto& u : col[i]) {
            for (int ii = ne[u]; ii != -1; ii = edge[ii].ne) {
                Edge e = edge[ii]; int v = e.to;
                if (v == node[u].fa) continue;
                LL sz = node[v].sz;
                node[n + 1].l = node[v].l;
                while (true) {
                    auto it = lower_bound(col[i].begin(), col[i].end(), n + 1, cmp);
                    if (it == col[i].end() || node[*it].l > node[v].r) break;
                    sz -= node[*it].sz;
                    node[n + 1].l = node[*it].r;
                }
//                printf("%d %d %d\n", u, v, sz);
                ans -= sz * (sz - 1) >> 1;
            }
        }
    }
    printf("Case #%d: %lld\n", ++kas, ans);
}
int main() {
//    freopen("多校联合训练第一场标程及数据 - 复件/数据/1003.in", "r", stdin);
//    freopen("03.out", "w", stdout);
    while (scanf("%lld", &n) != EOF) work();
    return 0;
}
