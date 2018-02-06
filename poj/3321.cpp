#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100010
using namespace std;
typedef long long LL;
struct Edge {
    int to, ne;
    Edge(int a = 0, int b = 0) : to(a), ne(b) {}
}edge[maxn * 2];
int le[maxn], ri[maxn], ne[maxn], c[maxn], tot, cnt, n;
bool flag[maxn];
inline int max(int a, int b) { return a > b ? a : b; }
void add(int u, int v) {
    edge[tot] = Edge(v, ne[u]);
    ne[u] = tot++;
}
void dfs(int u, int fa) {
    le[u] = ++cnt;
    int maxx = cnt;
    for (int i = ne[u]; i != -1; i = edge[i].ne) {
        Edge e = edge[i]; int v = e.to;
        if (v == fa) continue;
        dfs(v, u);
        maxx = max(maxx, ri[v]);
    }
    ri[u] = maxx;
}
inline int lowbit(int x) { return x & (-x); }
int query(int x) {
    int ret = 0;
    while (x) {
        ret += c[x];
        x -= lowbit(x);
    }
    return ret;
}
void modify(int x, int delta) {
    while (x <= n) {
        c[x] += delta;
        x += lowbit(x);
    }
}
void work() {
    memset(c, 0, sizeof(c)); memset(ne, -1, sizeof(ne)); tot = cnt = 0;
    for (int i = 1; i <= n; ++i) { modify(i, 1); flag[i] = 1; }
    for (int i = 1; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y); add(y, x);
    }
    dfs(1, -1);
    int q;
    scanf("%d", &q);
//    for (int i = 1; i <= n; ++i) printf("%d %d\n", le[i], ri[i]);
    while (q--) {
        char ch; int x;
        scanf("\n%c %d", &ch, &x);
        if (ch == 'Q') {
            printf("%d\n", query(ri[x]) - (le[x] == 1 ? 0 : query(le[x] - 1)));
        }
        else {
            x = le[x];
            if (flag[x]) modify(x, -1);
            else modify(x, 1);
            flag[x] ^= 1;
        }
    }
}
int main() {
    freopen("in.txt", "r", stdin);
    while (scanf("%d", &n) != EOF) work();
    return 0;
}
