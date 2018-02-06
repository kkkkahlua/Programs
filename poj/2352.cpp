#include <cstdio>
#include <cstring>
#define maxn 32001
#define maxm 15010
inline int lowbit(int x) { return x & (-x); }
int n, level[maxm], c[maxn + 10];
void update(int x) {
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
//    memset(level, 0, sizeof(level));
//    memset(c, 0, sizeof(c));
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        update(++x);
        ++level[query(x)];
    }
    for (int i = 1; i <= n; ++i) printf("%d\n", level[i]);
}
int main() {
    while (scanf("%d", &n) != EOF) work();
    return 0;
}
