#include <cstdio>
#include <cstring>
#define maxn 100000
#define maxm 20010
int a[maxm], c[maxn + 10], cnt[maxn + 10], le1[maxm], le2[maxm], gr1[maxm], gr2[maxm];
typedef long long LL;
inline int lowbit(int x) { return x & (-x); }
void add(int x) {
    while (x <= maxn) {
        ++c[x];
        x += lowbit(x);
    }
}
int query(int x) {
    int ret = 0;
    while (x) {
        ret += c[x];
        x -= lowbit(x);
    }
    return ret;
}
void work() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    memset(c, 0, sizeof(c));
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        le1[i] = query(x);
        gr1[i] = i - le1[i];
        add(x);
    }
    memset(c, 0, sizeof(c));
    for (int i = n - 1; i >= 0; --i) {
        int x = a[i];
        le2[i] = query(x);
        gr2[i] = (n - 1 - i) - le2[i];
        add(x);
    }
//    for (int i = 1; i < n - 1; ++i) {
//        printf("%d %d %d %d\n", le1[i], le2[i], gr1[i], gr2[i]);
//    }
    LL ans = 0;
    for (int i = 1; i < n - 1; ++i) {
        ans += le1[i] * gr2[i] + le2[i] * gr1[i];
    }
    printf("%lld\n", ans);
}
int main() {
    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
