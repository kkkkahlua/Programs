#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 210
using namespace std;
struct node {
    int x, y, t, v;
    node& operator + (node& nd) { t += nd.t; v += nd.v; return *this;}
}a[maxn], c[maxn][maxn];
int n, t, b[maxn][maxn], num[maxn], dp[40010];
bool cmp(node u, node v) {
    if (u.y == 0) {
        if (u.x > 0) if (v.y != 0) return true;
                    else return (u.x <= v.x || v.x < 0);
        if (u.x < 0) if (v.y != 0) return true;
                    else return u.x >= v.x;
    }
    return (u.y * v.x < u.x * v.y || (u.y * v.x == u.x * v.y && u.y < v.y));
}
void work(int cas) {
    memset(num, 0, sizeof(num));
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%d", &a[i].x, &a[i].y, &a[i].t, &a[i].v);
    }
    sort(a, a + n, cmp);
    b[0][0] = 0; num[0] = 1;
    int tot = 0;
    for (int i = 1; i < n; ++i) {
        node u = a[i - 1], v = a[i];
        if (u.y * v.x != u.x * v.y) ++tot;
        b[tot][num[tot]++] = i;
    }
    ++tot;
//    for (int i = 0; i < n; ++i) {
//        printf("%d %d\n", a[i].x, a[i].y);
//    }
//    for (int i = 0; i < tot; ++i) {
//        for (int j = 0; j < num[i]; ++j) {
//            printf("%d ", b[i][j]);
//        }
//        printf("\n");
//    }
//    printf("%d\n", tot);
    for (int i = 0; i < tot; ++i) {
        c[i][0] = a[b[i][0]];
        for (int j = 1; j < num[i]; ++j) {
            node temp = a[b[i][j]], temp0 = c[i][j - 1];
            temp = temp + temp0;
            c[i][j] = temp;
        }
    }
//    for (int i = 0; i < tot; ++i) {
//        for (int j = 0; j < num[i]; ++j) {
//            printf("%d %d %d %d ", c[i][j].x, c[i][j].y, c[i][j].t, c[i][j].v);
//        }
//        printf("\n");
//    }
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < tot; ++i) {
        for (int j = t; j >= 0; --j) {
            for (int k = 0; k < num[i]; ++k) {
                if (j - c[i][k].t < 0) continue;
                dp[j] = max(dp[j], dp[j - c[i][k].t] + c[i][k].v);
            }
        }
    }
    printf("Case %d: %d\n", cas, dp[t]);
}
int main() {
    freopen("4341.in", "r", stdin);
    int cas = 1;
    while (scanf("%d%d", &n, &t) != EOF) work(cas++);
    return 0;
}
