#include <bits/stdc++.h>
#define maxn 200010
using namespace std;
typedef long long LL;
struct Edge {
    int to, ne;
    Edge(int _to=0, int _ne=0): to(_to), ne(_ne) {}
}edge[maxn * 2];
int tot, t, ne[maxn], ans0[maxn], ans1[maxn], val[maxn], cnt[maxn], divi[maxn];
void add(int u, int v) {
    edge[tot] = Edge(v, ne[u]);
    ne[u] = tot++;
}
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
void accum(int x, bool sgn) {
    for (int i = 0; i < t; ++i) {
        if (x % divi[i] == 0) if (sgn==1) ++cnt[i]; else --cnt[i];
    }
}
void dfs(int u, int fa, int dep) {
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (v == fa) continue;
        ans0[v] = gcd(ans0[u], val[v]);
        accum(val[v], 1);
        for (int j = t-1; j >= 0; --j) if (cnt[j] >= dep) { ans1[v] = divi[j]; break; }
        dfs(v, u, dep+1);
        accum(val[v], 0);
    }
}
int main() {
//    freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &val[i]);
    memset(ne, -1, sizeof(ne));
    for (int i = 1; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y), add(y, x);
    }
    for (int i = 1; i*i <= val[1]; ++i) {
        if (i*i == val[1]) divi[t++] = i;
        else if (val[1]%i==0) divi[t++] = i, divi[t++] = val[1]/i;
    }
    ans0[1] = 0;
    sort(divi, divi+t);
    dfs(1, -1, 0);
    printf("%d", val[1]);
    for (int i = 2; i <= n; ++i) printf(" %d", max(ans0[i], ans1[i])); printf("\n");
    return 0;
}
