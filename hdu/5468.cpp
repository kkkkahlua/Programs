#include <bits/stdc++.h>
#include <vector>
#define maxn 100000
#define maxm maxn + 10
using namespace std;
int mu[maxm], prime[maxm], cnt[maxm], kas, ans[maxm], ne[maxm], tot, val[maxm];
bool check[maxm];
vector<int> fac[maxm];
struct Edge {
    int to, ne;
    Edge(int a = 0, int b = 0) : to(a), ne(b) {}
}edge[maxn * 2];
void add(int u, int v) {
    edge[tot] = Edge(v, ne[u]);
    ne[u] = tot++;
}
void init() {
    int tot = 0; mu[1] = 1;
    for (int i = 1; i <= maxn; ++i) fac[i].push_back(1);
    for (int i = 2; i <= maxn; ++i) {
        if (!check[i]) {
            prime[tot++] = i;
            mu[i] = -1;
        }
        for (int j = 0; j < tot; ++j) {
            if (i * prime[j] > maxn) break;
            check[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                break;
            }
            mu[i * prime[j]] = -mu[i];
        }
        if (mu[i] != 0) {
            for (int j = i; j <= maxn; j += i) fac[j].push_back(i);
        }
    }
}
void dfs(int u, int fa) {
    vector<int> pre;
    ans[u] = 0;
    for (auto x : fac[val[u]]) {
        pre.push_back(cnt[x]);
        ++cnt[x];
    }
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (v == fa) continue;
        dfs(v, u);
    }
    vector<int>& ve = fac[val[u]];
    int sz = ve.size();
    for (int i = 0; i < sz; ++i) {
        ans[u] += mu[ve[i]] * (cnt[ve[i]] - pre[i]);
    }
}
int n;
void work() {
    memset(cnt, 0, sizeof(cnt));
    memset(ne, -1, sizeof(ne));
    tot = 0;
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v); add(v, u);
    }
    for (int i = 1; i <= n; ++i) scanf("%d", &val[i]);
    dfs(1, -1);
    printf("Case #%d: %d", ++kas, ans[1]);
    for (int i = 2; i <= n; ++i) printf(" %d", ans[i]); printf("\n");
}
int main() {
    freopen("in.txt", "r", stdin);
    init();
    while (scanf("%d", &n) != EOF) work();
    return 0;
}
