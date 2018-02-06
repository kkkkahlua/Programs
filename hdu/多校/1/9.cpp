#include <bits/stdc++.h>
#define maxm 2010
#define maxn 1010
typedef long long LL;
int kas, ne[maxn], tot, n, m, k, dfn[maxn], low[maxn], cnt, sum;
unsigned ans;
bool in[maxn];
using namespace std;
vector<int> cur, vec, vnew;
struct qnode {
    int le, ri, val;
    qnode(int a = 0, int b = 0, int c = 0) : le(a), ri(b), val(c) {}
    bool operator < (const qnode& nd) const {
        return val < nd.val;
    }
};
priority_queue<qnode> q;
stack<int> s;
inline int min(int a, int b) { return a < b ? a : b; }
struct Edge {
    int from, to, d, ne;
    Edge(int b = 0, int a = 0, int dist = 0, int c = 0) : from(b), to(a), d(dist), ne(c) {}
}edge[maxm * 2];
void add(int u, int v, int d) {
    edge[tot] = Edge(u, v, d, ne[u]);
    ne[u] = tot++;
}
bool cmp(int a, int b) { return a > b; }
void merge(vector<int>& v) {
    sort(v.begin(), v.end(), cmp);
//    for (auto x : v) printf("%d ", x); printf("\n");
    if (cur.empty()) {
        int sz = min(k, v.size());
        for (int i = 0; i < sz; ++i) {
            cur.push_back(v[i]);
        }
        return;
    }
    vnew.clear();
    while (!q.empty()) q.pop();
    int sz = min(k, v.size()), a0 = cur[0];
    for (int i = 0; i < sz; ++i) q.push(qnode(0, i, a0 + v[i]));
    int no = 0;
    while (true) {
        qnode nd = q.top(); q.pop(); ++no;
        vnew.push_back(nd.val);
        if (nd.le + 1 != cur.size()) q.push(qnode(nd.le + 1, nd.ri, cur[nd.le + 1] + v[nd.ri]));
        if (no == k || q.empty()) break;
    }
    cur = vnew;
}
void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++cnt;
    for (int i = ne[u]; i != -1; i = edge[i].ne) {
        Edge e = edge[i]; int v = e.to;
        if (v == fa) continue;
        if (!dfn[v]) {
            s.push(i);
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u]) {
                Edge e;
                vec.clear();
                while (true) {
                    int idx = s.top(); s.pop();
                    e = edge[idx];
                    vec.push_back(e.d);
                    if (idx == i) break;
                }
//                printf("%d\n", vec.size());
                if (vec.size() > 1) merge(vec);
            }
        }
        else if (dfn[v] < dfn[u] && v != fa) {
            s.push(i);
            low[u] = min(low[u], dfn[v]);
        }
    }
}
void work() {
    memset(ne, -1, sizeof(ne)); tot = 0; sum = ans = 0;
    memset(dfn, 0, sizeof(dfn)); memset(low, 0, sizeof(low));
    memset(in, 0, sizeof(in));
    cur.clear();
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
        add(y, x, z);
        sum += z;
    }
    scanf("%d", &k);
    for (int i = 1; i <= n; ++i) if (!dfn[i]) tarjan(i, -1);
    int sz = min(cur.size(), k);
    if (sz == 0) ans = sum;
    else for (int i = 0; i < sz; ++i) ans += (LL)(i + 1) * (sum - cur[i]);
    printf("Case #%d: %u\n", ++kas, ans);
}
int main() {
//    freopen("in.txt", "r", stdin);
    freopen("多校联合训练第一场标程及数据-复件/数据/1009.in", "r", stdin);
    freopen("09.out", "w", stdout);
    while (scanf("%d%d", &n, &m) != EOF) work();
    return 0;
}
