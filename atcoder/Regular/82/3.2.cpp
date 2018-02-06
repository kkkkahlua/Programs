#include <bits/stdc++.h>
#define maxn 100010
typedef long long LL;
using namespace std;
const LL mod = 998244353;
LL x[maxn], y[maxn], P[maxn];
int fa[maxn], sz[maxn];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void unionn(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (sz[x] > sz[y]) swap(x, y);
    fa[x] = y; sz[y] += sz[x];
}
struct node { int p, q; LL dx, dy; };
bool cmp(node u, node v) { return u.dx < v.dx || (u.dx == v.dx && u.dy < v.dy); }
vector<node> seg;
LL GCD(LL x, LL y) { return y ? GCD(y, x % y) : x; }
int main() {
    LL n;
    scanf("%lld", &n);
    for (int i = 0; i < n; ++i) scanf("%lld%lld", &x[i], &y[i]);
    P[0] = 1;
    for (int i = 1; i <= n; ++i) (P[i] = P[i-1] << 1) %= mod;

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            LL dx = x[i]-x[j], dy = y[i]-y[j];
            LL gcd = GCD(dx, dy);
            dx /= gcd, dy /= gcd;
            if (dx < 0) dx = -dx, dy = -dy;
            seg.push_back(node{i, j, dx, dy});
        }
    }
    sort(seg.begin(), seg.end(), cmp);

    LL ans = P[n] - 1 - n;
    int i = 0, j = 0;
    for (; i < seg.size(); i = j+1) {
        for (int k = 0; k < n; ++k) fa[k] = k, sz[k] = 1;
        for (j = i; ; ++j) {
            unionn(seg[j].p, seg[j].q);
            if (j+1 >= seg.size() || seg[i].dx != seg[j+1].dx || seg[i].dy != seg[j+1].dy) break;
        }
        for (int k = 0; k < n; ++k) {
            if (fa[k] == k) ((ans -= (P[sz[k]] - sz[k] - 1)) += mod) %= mod;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
