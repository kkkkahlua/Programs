#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
typedef long long LL;
const LL mod = 1e9+7;
struct node {
    int x, y;
}a[maxn];
int fa[maxn], sz[maxn], f[maxn], id[maxn], m[maxn];
bool circ[maxn], vis[maxn];
vector<int> v[maxn];
set<int> sx, sy;
bool cmp1(int i, int j) {
    return a[i].x < a[j].x || (a[i].x == a[j].x && a[i].y < a[j].y);
}
bool cmp2(int i, int j) {
    return a[i].y < a[j].y || (a[i].y == a[j].y && a[i].x < a[j].x);
}
LL poww(LL a, LL b) {
    LL ret = 1;
    while (b) {
        if (b & 1) (ret *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return ret;
}
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void unionn(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) { circ[a] = true; return; }
    if (sz[a] > sz[b]) swap(a, b);
    fa[a] = b; sz[b] += sz[a];
    circ[b] |= circ[a];
}
int main() {
//    freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i].x, &a[i].y);
    }
    for (int i = 0; i < n; ++i) id[i] = i;
    for (int i = 0; i < n; ++i) fa[i] = i, sz[i] = 1;

    sort(id, id+n, cmp1);
    for (int i = 1; i < n; ++i) {
        if (a[id[i]].x == a[id[i-1]].x) unionn(id[i-1], id[i]);
    }
    sort(id, id+n, cmp2);
    for (int i = 1; i < n; ++i) {
        if (a[id[i]].y == a[id[i-1]].y) unionn(id[i-1], id[i]);
    }
    for (int i = 0; i < n; ++i) fa[i] = find(i);

    int tot = -1;
    for (int i = 0; i < n; ++i) {
        if (!vis[fa[i]]) vis[fa[i]] = true, f[++tot] = fa[i], m[fa[i]] = tot;
        v[m[fa[i]]].push_back(i);
    }
    LL ans = 1;
    for (int i = 0; i <= tot; ++i) {
        sx.clear(), sy.clear();
        for (auto idx : v[i]) {
            sx.insert(a[idx].x), sy.insert(a[idx].y);
        }
        LL mul = poww(2, sx.size()+sy.size());
        if (!circ[f[i]]) (mul += mod-1) %= mod;
        (ans *= mul) %= mod;
    }
    printf("%I64d\n", ans);
    return 0;
}
