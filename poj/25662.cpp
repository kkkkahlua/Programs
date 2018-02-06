#include <cstdio>
#include <algorithm>
#include <cstring>
#define maxn 100010
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long LL;
LL a[maxn];
struct node {
    LL val; int p;
}sum[maxn];
int n, k;
bool cmp(node u, node v) { return u.val < v.val; }
template<typename T>
inline T abs(T x) { return x > 0 ? x : -x; }
inline LL min(LL a, LL b) { return a < b ? a : b; }
int pos(int i, LL x, LL& dif) {
    node nd; nd.val = x;
    int p = lower_bound(sum, sum+1+n, nd, cmp) - sum;
//    printf("%d\n", p);
    if (p == 0) {
        if (p != i) { dif = sum[0].val - x; return 0; }
        else { dif = sum[1].val - x; return 1; }
    }
    if (p == n + 1) {
        if (p != i) { dif = x - sum[n].val; return n; }
        else { dif = x - sum[n - 1].val; return n - 1; }
    }
    LL dif1, dif2, p1, p2;
    if (p != i) dif1 = sum[p].val - x, p1 = p;
    else {
        if (p == n) dif1 = inf;
        else dif1 = sum[p + 1].val - x, p1 = p + 1;
    }
    if (p - 1 != i) dif2 = x - sum[p - 1].val, p2 = p - 1;
    else {
        if (p >= 2) dif2 = x - sum[p - 2].val, p2 = p - 2;
        else dif2 = inf;
    }
    if (dif1 > dif2) { dif = dif2; return p2; }
    else { dif = dif1; return p1; }
}
void work() {
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        sum[i].val = sum[i - 1].val + a[i];
        sum[i].p = i;
    }
    sort(sum, sum + 1 + n, cmp);
//    for (int i = 0; i <= n; ++i) printf("%lld %d\n", sum[i].val, sum[i].p);
    while (k--) {
        LL q;
        scanf("%lld", &q);
        LL dif = inf, ans; int l, r;
        for (int i = 0; i <= n; ++i) {
            LL dif1, dif2;
            int p1 = pos(i, sum[i].val + q, dif1),
                p2 = pos(i, sum[i].val - q, dif2);
//            printf("p1, p2: %d %d\n", p1, p2);
            if (min(dif1, dif2) < dif) {
                int p;
                if (dif1 < dif2) { p = p1; dif = dif1; }
                else { p = p2; dif = dif2; }
                ans = abs(sum[p].val - sum[i].val);
                l = sum[p].p, r = sum[i].p;
//                printf("l, r : %d %d\n", l, r);
                if (l > r) swap(l, r);
                ++l;
                if (dif == 0) break;
//                printf("%d : %lld %d %d\n", i, dif, l, r);
            }
        }
        printf("%lld %d %d\n", ans, l, r);
    }
}
int main() {
    freopen("2566.in", "r", stdin);
    freopen("25662.out", "w", stdout);
//    freopen("in.txt", "r", stdin);
    while (scanf("%d%d", &n, &k) != EOF && n + k) work();
    return 0;
}
