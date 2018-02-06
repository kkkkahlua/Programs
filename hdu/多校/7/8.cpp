#include <bits/stdc++.h>
#define eps 1e-6
#define PI acos(-1.0)
#define maxn 50010
typedef long long LL;
using namespace std;
struct node {
    int x, y;
    double a;
    LL v;
    bool operator < (const node nd) const {
        return a < nd.a;
    }
}p[maxn];
void work() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%lld", &p[i].x, &p[i].y, &p[i].v);
        if (p[i].x == 0) p[i].a = PI / 2;
        else p[i].a = atan((double)p[i].y / p[i].x);
    }
    sort(p, p + n);
//    for (int i = 0; i < n; ++i) printf("%d %d %.3f\n", p[i].x, p[i].y, p[i].a);
    LL lsum = 0, rsum = 0;
    for (int i = 0; i < n; ++i) {
        if (p[i].x >= 0) rsum += p[i].v;
        else lsum += p[i].v;
    }
    LL ans = rsum * lsum;
    for (int i = 0; i < n; ++i) {
        if (p[i].x >= 0) {
            rsum -= p[i].v;
            lsum += p[i].v;
        }
        else {
            lsum -= p[i].v;
            rsum += p[i].v;
        }
        ans = max(ans, rsum * lsum);
    }
    printf("%lld\n", ans);
}
int main() {
    freopen("多校第七场数据和标程/数据/1008.in", "r", stdin);
    freopen("08.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
