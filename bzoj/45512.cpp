#include <bits/stdc++.h>
#include <vector>
#define maxn 100010
#define inf 0x3f3f3f3f
using namespace std;
struct Edge {
    int to, ne;
    Edge(int a = 0, int b = 0) : to(a), ne(b) {}
}edge[maxn * 2];
struct op {
    char c; int x;
    op(char a = ' ', int b = 0) : c(a), x(b) {}
}a[maxn];
int tot, ne[maxn], setfa[maxn], trfa[maxn], col[maxn], first[maxn];
vector<int> ans;
void add(int u, int v) {
    edge[tot] = Edge(v, ne[u]);
    ne[u] = tot++;
}
inline int find(int x) {
    if (setfa[x] == x) return x;
    return setfa[x] = find(setfa[x]);
}
inline void unionn(int x, int y) { setfa[x] = find(y); }
void dfs(int u, int fa, int c) {
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (v == fa) continue;
        trfa[v] = u;
        if (!setfa[v]) setfa[v] = c;
        dfs(v, u, setfa[v]);
    }
}
int n, q;
void work() {
    tot = 0; memset(ne, -1, sizeof(ne));
    memset(setfa, 0, sizeof(setfa));
    memset(first, 0, sizeof(first));
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v); add(v, u);
    }
    for (int i = 1; i <= q; ++i) {
        int x; char c;
        scanf("\n%c%d", &c, &x);
        a[i] = op(c, x);
        if (c == 'C') setfa[x] = x, col[i] = x; //  ++col[x];
    }
    for (int i = q; i > 0; --i) first[col[i]] = i;
    first[1] = inf;
//    dfs(1, -1);
    setfa[1] = 1;
    dfs(1, -1, 1);
    ans.clear();
    for (int i = q; i > 0; --i) {
        op oper = a[i];
        if (oper.c == 'Q') ans.push_back(find(oper.x));
        else if (i == first[oper.x]) unionn(oper.x, trfa[oper.x]);
//        else {
//            --col[oper.x];
//            if (!col[oper.x]) setfa[oper.x] = trfa[oper.x];
//        }
    }
    for (vector<int>::reverse_iterator it = ans.rbegin(); it != ans.rend(); ++it) printf("%d\n", *it);
}
int main() {
    freopen("in.txt", "r", stdin);
    while (scanf("%d%d", &n, &q) != EOF) work();
    return 0;
}
