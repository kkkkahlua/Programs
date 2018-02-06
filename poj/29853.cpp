#include <cstdio>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <cstring>
#define maxn 200010
using namespace std;
int fa[maxn], sz[maxn], n, m, c[maxn], num;
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
int lowbit(int x) { return x & (-x); }
void add(int i, int x) { for (; i <= n; i += lowbit(i)) c[i] += x; }
int sum(int i) { int ret = 0; for (; i; i -= lowbit(i)) ret += c[i]; return ret; }
void unionn(int u, int v) {
    int fau = find(u), fav = find(v);
    if (fau == fav) return;
    add(sz[fau], -1), add(sz[fav], -1);
    if (sz[fau] > sz[fav]) swap(fau, fav);
    fa[fau] = fav; sz[fav] += sz[fau];
    add(sz[fav], 1);
    --num;
}
int calc(int k) {
    int cnt = 0, ans = 0;
    for (int i = 20; i >= 0; --i) {
        ans += (1 << i);
        if (ans > n || cnt + c[ans] >= k) ans -= (1 << i);
        else cnt += c[ans];
    }
    return ans + 1;
}
void work() {
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; ++i) fa[i] = i, sz[i] = 1;
    add(1, n);
    num = n;
    while (m--) {
        int x, u, v, k;
        scanf("%d", &x);
        if (x == 0) {
            scanf("%d%d", &u, &v);
            unionn(u, v);
        }
        else {
            scanf("%d", &k);
            printf("%d\n", calc(num-k+1));
        }
    }
}
int main() {
    freopen("in.txt", "r", stdin);
    while (scanf("%d%d", &n, &m) != EOF) work();
    return 0;
}