#include <cstdio>
#include <cstring>
#define maxn 100000
int tot[maxn+10], fa[maxn+10], sz[maxn+10], n;
inline max(int a, int b) { return a > b ? a : b; }
int findfa(int x) {
    if (fa[x] == x) return x;
    return fa[x] = findfa(fa[x]);
}
void unioni(int x, int y) {
    int fax = findfa(x), fay = findfa(y);
    if (sz[fax] < sz[fay]) { fa[fax] = fay; sz[fay] += sz[fax]; }
    else { fa[fay] = fax; sz[fax] += sz[fay]; }
}
void work() {
    memset(tot, 0, sizeof(tot));
    for (int i = 0; i < maxn; ++i) { fa[i] = i; sz[i] = i; }
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a; --b;
        unioni(a, b);
    }
    for (int i = 0; i < maxn; ++i) {
//        printf("%d ", findfa(i));
        ++tot[findfa(i)];
    }
    int ans = 0;
    for (int i = 0; i < maxn; ++i) ans = max(ans, tot[i]);
    printf("%d\n", ans);
}
int main() {
    while (scanf("%d", &n) != EOF) work();
    return 0;
}
