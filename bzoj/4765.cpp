#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 100010
#define maxm 320
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
struct node { int to, ne; }edge[maxn<<1];
int ne[maxn], l[maxn], r[maxn], t[maxn], f[maxn][maxm], bl[maxn], v[maxn], vv[maxn];
int tot, nb, n, blo, cnt, m;
LL c[maxn], val[maxn], tag[maxm], pre[maxn];
ULL sum[maxm];
void addEdge(int u, int v) {
    edge[tot] = {v, ne[u]};
    ne[u] = tot++;
}
void dfs(int u, int fa) {
    ++t[bl[u]];
    F2(i, 1, nb) f[u][i] = t[i];
    l[u] = ++cnt;
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (v!=fa) dfs(v,u);
    }
    r[u] = cnt;
    --t[bl[u]];
}
inline int lowbit(int x) { return x & (-x); }
inline void add(int x, LL v) { while (x<=n) c[x]+=v, x+=lowbit(x); }
inline LL query(int x) { LL ret=0; while (x) ret+=c[x], x-=lowbit(x); return ret; }
void init() {
    F2(i, 1, n) val[i] = query(r[i]) - query(l[i]-1);
    F2(i, 1, nb) {
        F2(j, (i-1)*blo+1, min(i*blo, n)) sum[i] += val[j];
    }
}
void modify(int u, int x) {
    LL delta=x-v[u];
    add(l[u], delta);
    F2(i, 1, nb) sum[i] += f[u][i]*delta;
    v[u] = x;
}
ULL ask(int ll, int rr) {
    ULL ret=0;
    F2(i, ll, min(bl[ll]*blo, rr)) ret += query(r[i])-query(l[i]-1);
    if (bl[ll]!=bl[rr]) {
        F2(i, (bl[rr]-1)*blo+1, rr) ret += query(r[i])-query(l[i]-1);
    }
    F(i, bl[ll]+1, bl[rr]) ret += sum[i];
    return ret;
}
int main() {
    scanf("%d%d", &n, &m); blo = sqrt(n);
    F2(i, 1, n) {
        scanf("%d", &v[i]);
        bl[i] = (i-1)/blo+1;
    }
    nb = bl[n];
    int rt;
    memset(ne, -1, sizeof ne);
    F(i, 0, n) {
        int u, v;
        scanf("%d%d", &u, &v);
        if (!u) rt = v;
        else addEdge(u, v), addEdge(v, u);
    }
    dfs(rt, -1);
    F2(i, 1, n) add(l[i], v[i]);
    init();
    F(i, 0, m) {
        int op, l, r;
        scanf("%d%d%d", &op,&l,&r);
        if (op==1) modify(l, r);
        else printf("%llu\n", ask(l, r));
    }
    return 0;
}
