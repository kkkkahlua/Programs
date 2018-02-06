#include <cstdio>
#include <cstring>
typedef long long LL;
int x, y;
void exgcd(int x, int y, int& x1, int& y1) {
    if (y == 0) { x1 = 1; y1 = 0; return; }
    exgcd(y, x % y, x1, y1);
    int temp = x1;
    x1 = y1;
    y1 = temp - x / y * y1;
}
void work() {
    int x1, y1;
    exgcd(x, y, x1, y1);
//    printf("%d %d\n", x1, y1);
    LL ans;
    if (x1 < 0) {
        int x2 = x1 + y;
        ans = (LL)(x2 - 1) * x + (LL)(y1 - 1) * y;
    }
    else {
        int y2 = y1 + x;
        ans = (LL)(x1 - 1) * x + (LL)(y2 - 1) * y;
    }
    printf("%lld\n", ans - 1);
}
int main() {
    int T;
    scanf("%d\n", &T);
    while (scanf("%d%d", &x, &y) != EOF) work();
    return 0;
}
