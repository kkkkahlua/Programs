#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 5010
int up[maxn], down[maxn], ans[maxn], n, m;
using namespace std;
typedef long long LL;
LL vec(LL x1, LL y1, LL x2, LL y2, LL x0, LL y0) {
    return (x1-x0) * (y2-y0) - (x2-x0) * (y1-y0);
}
void work() {
    memset(ans, 0, sizeof ans);
    int x1, y1, x2, y2;
    scanf("%d%d%d%d%d", &m, &x1, &y1, &x2, &y2);
    for (int i = 1; i <= n; ++i) scanf("%d%d", &up[i], &down[i]);
    up[0] = down[0] = x1, up[n+1] = down[n+1] = x2;
    while (m--) {
        int x, y;
        scanf("%d%d", &x, &y);
        int p2 = lower_bound(down, down+n+1, x) - down,
            p1 = lower_bound(up, up+n+1, x) - up;
        printf("%d %d\n", p1, p2);
        if (p1 == p2) { ++ans[p1-1]; continue; }
        if (p1 > p2) swap(p1, p2);
        for (int i = p1; i <= p2; ++i) {
            if (vec(up[i], y1, down[i], y2, x, y) < 0) { ++ans[i-1]; break; }
        }
    }
    for (int i = 0; i <= n; ++i) printf("%d: %d\n", i, ans[i]);
    printf("\n");
}
int main() {
//    freopen("in.txt", "r", stdin);
    while (scanf("%d", &n) && n) work();
    return 0;
}
