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
template<typename T>
inline T abs(T x) { return x > 0 ? x : -x; }
bool cmp(node u, node v) { return u.val < v.val; }
void work() {
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        sum[i].val = sum[i - 1].val + a[i];
        sum[i].p = i;
    }
    sort(sum, sum+1+n, cmp);
//    for (int i = 0; i <= n; ++i) {
//        printf("%lld %d\n", sum[i].val, sum[i].p);
//    }
    while (k--) {
        LL t;
        scanf("%lld", &t);
        int l = 0, r = 1, al, ar;
        LL diff = inf, ans;
        while (true) {
            if (l == n + 1) break;
            bool flag = false;
            while (r <= n) {
                LL d = sum[r].val - sum[l].val;
//                printf("hh %d %d %lld %lld\n", l, r, d, abs(t - d));
                if (abs(t - d) < diff) {
                    diff = abs(t - d);
                    ans = d;
                    al = sum[l].p, ar = sum[r].p;
                    if (al > ar) swap(al, ar);
                    ++al;
                }
                if (d == t) flag = true;
                if (d >= t) break;
                ++r;
            }
            if (r == n + 1 || flag) break;
            ++l;
            if (l == r) ++r;
        }
        printf("%lld %d %d\n", ans, al, ar);
    }
}
int main() {
    freopen("2566.in", "r", stdin);
    freopen("2566.out", "w", stdout);
//    freopen("in.txt", "r", stdin);
    while (scanf("%d%d", &n, &k) != EOF && n + k) work();
    return 0;
}
