#include <bits/stdc++.h>
#include <queue>
namespace fastIO {
    #define BUF_SIZE 100000
    //fread -> read
    bool IOerror = 0;
    inline char nc() {
        static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
        if(p1 == pend) {
            p1 = buf;
            pend = buf + fread(buf, 1, BUF_SIZE, stdin);
            if(pend == p1) {
                IOerror = 1;
                return -1;
            }
        }
        return *p1++;
    }
    inline bool blank(char ch) {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    }
    inline void read(int &x) {
        char ch;
        while(blank(ch = nc()));
        if(IOerror)
            return;
        for(x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');
    }
    #undef BUF_SIZE
};
using namespace fastIO;
using namespace std;
#define maxn 100010
int ne[maxn], tot, deg[maxn];
bool vis[maxn];
struct Edge {
    int from, to, ne;
    Edge(int c = 0, int a = 0, int b = 0) : from(c), to(a), ne(b) {}
}edge[maxn * 2];
void add(int u, int v) {
    edge[tot] = Edge(u, v, ne[u]);
    ne[u] = tot++;
}
queue<int> q;
void work() {
    int n, k;
    read(n); read(k);
    memset(ne, -1, sizeof(ne));
    memset(deg, 0, sizeof(deg));
    memset(vis, 0, sizeof(vis));
    tot = 0;
    for (int i = 2; i <= n; i++) {
        int x;
        read(x);
        add(x, i); add(i, x);
        ++deg[x]; ++deg[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 1) q.push(i);
    }
    int ans = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (deg[u] != 1) continue;
        int p;
        for (int i = ne[u]; ~i; i = edge[i].ne) {
            int v = edge[i].to;
            if (vis[v]) continue;
            p = v;
        }
        vis[u] = vis[p] = true;
        --deg[u]; --deg[p];
        k -= 2; ++ans;
        if (k <= 0) break;
        for (int i = ne[p]; ~i; i = edge[i].ne) {
            int v = edge[i].to;
            if (vis[v]) continue;
            --deg[v]; --deg[p];
            if (deg[v] == 1) q.push(v);
        }
    }
    if (k <= 0) printf("%d\n", ans);
    else printf("%d\n", ans + k);
}
int main() {
    freopen("in.txt", "r", stdin);
    int T;
    read(T);
    while (T--) work();
}
