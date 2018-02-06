#include <bits/stdc++.h>
#define maxn 200010
#define maxl 60
using namespace std;
typedef long long LL;
struct Edge { int to, ne; LL d; } edge[maxn<<1];
LL d[maxn], b[maxn];
int tot, ne[maxn], cnt;
bool vis[maxn];
void add(int u, int v, LL d) {
    edge[tot] = {v, ne[u], d};
    ne[u] = tot++;
    edge[tot] = {u, ne[v], d};
    ne[v] = tot++;
}
void dfs(int u, LL dd) {
    d[u] = dd; vis[u] = true;
//    printf("%d %lld\n", u, dd);
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (vis[v]) b[cnt++] = d[u] ^ edge[i].d ^ d[v];
        else dfs(v, d[u] ^ edge[i].d);
    }
}
struct LinearBasis {
    LL a[maxl+1];
    LinearBasis() { memset(a, 0, sizeof a); }
    void insert(LL t) {
        for (int i = maxl; i >= 0; --i) {
            if (!(t >> i & 1)) continue;
            if (a[i]) t ^= a[i];
            else {
                for (int j = 0; j < i; ++j) if (t >> j & 1) t ^= a[j];
                for (int j = i+1; j <= maxl; ++j) if (a[j] >> i & 1) a[j] ^= t;
                a[i] = t;
                return;
            }
        }
    }
    LL condMax(LL t) {
        LL ret = t;
        for (int i = maxl; i >= 0; --i) {
            if (!(a[i] >> i & 1)) continue;
            if (ret >> i & 1) continue;
            ret ^= a[i];
        }
        return ret;
    }
};
int main() {
    freopen("in.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);

    tot = 0; memset(ne, -1, sizeof ne);
    for (int i = 0; i < m; ++i) {
        int u, v; LL d;
        scanf("%d%d%lld", &u, &v, &d);
        add(u, v, d);
    }
    dfs(1, 0);

    LinearBasis lb;
    for (int i = 0; i < cnt; ++i) {
        if (b[i]) lb.insert(b[i]);
    }

    printf("%lld\n", lb.condMax(d[n]));

    return 0;
}
