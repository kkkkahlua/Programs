#include <cstdio>
#include <cstring>
#define maxn 1030
int c[maxn][maxn], s, n;
inline int lowbit(int x) { return x & (-x); }
void update(int x, int y, int a) {
    for (int i = x; i <= n; i += lowbit(i)) {
        for (int j = y; j <= n; j += lowbit(j)) {
            c[i][j] += a;
        }
    }
}
int query(int x, int y) {
    if (x == 0 || y == 0) return 0;
    int ret = 0;
    for (int i = x; i; i -= lowbit(i)) {
        for (int j = y; j; j -= lowbit(j)) {
            ret += c[i][j];
        }
    }
    return ret;
}
void work() {
    memset(c, 0, sizeof(c));
    while (scanf("%d", &s)) {
        if (s == 3) return;
        if (s == 1) {
            int x, y, a;
            scanf("%d%d%d", &x, &y, &a);
            ++x; ++y;
            update(x, y, a);
        }
        else {
            int l, b, r, t;
            scanf("%d%d%d%d", &l, &b, &r, &t);
            ++r; ++t;
            printf("%d\n", query(r, t) - query(l, t) - query(r, b) + query(l, b));
        }
    }
}
int main() {
    freopen("in.txt", "r", stdin);
    while (scanf("%d%d", &s, &n) != EOF) work();
    return 0;
}
