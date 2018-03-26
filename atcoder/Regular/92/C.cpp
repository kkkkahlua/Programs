#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 1010
using namespace std;
typedef long long LL;
bool flag[maxn];
struct Point {
    int x, y;
    bool operator < (const Point& p) const {
        return x < p.x && y < p.y;
    }
}a[maxn], b[maxn];
typedef long long LL;
struct Edge {
    int to, ne;
    Edge(int _to=0, int _ne=0) : to(_to), ne(_ne) {}
}edge[20000];
int tot, ne[maxn], match[maxn], vis[maxn];
void add(int u, int v) {
    edge[tot] = Edge(v, ne[u]);
    ne[u] = tot++;
}
int find(int u) {
    for (int i = ne[u]; ~i; i = edge[i].ne) {
        int v = edge[i].to;
        if (!vis[v]) {
            vis[v] = true;
            if (!match[v] || find(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}
int main() {
    memset(ne, -1, sizeof ne);
    int n, x, y;
    scanf("%d", &n);
    F(i, 0, n) scanf("%d%d", &a[i].x, &a[i].y);
    F(i, 0, n) scanf("%d%d", &b[i].x, &b[i].y);
    F(i, 0, n) {
        F(j, 0, n) {
            if (a[i]<b[j]) add(i+1, j+n+1), add(j+n+1, i+1);
        }
    }
    int cnt=0;
    F2(i, 1, n) {
        memset(vis, 0, sizeof vis);
        if (find(i)) ++cnt;
    }
    printf("%d\n", cnt);
    return 0;
}
