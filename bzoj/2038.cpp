#include <bits/stdc++.h>
#define maxn 50010
using namespace std;
typedef long long LL;
struct frac {
    LL p, q;
}ans[maxn], anss[maxn];
struct node {
    int l, r, id;
}q[maxn];
int n, m, a[maxn], sz, cnt[maxn];
inline int min(int a, int b) { return a < b ? a : b; }
inline int max(int a, int b) { return a > b ? a : b; }
inline LL GCD(LL a, LL b) {
    if (!b) return a;
    return GCD(b, a % b);
}
bool cmp(node u, node v) {
    int l1 = u.l / sz, l2 = v.l / sz,
        r1 = u.r / sz, r2 = v.r / sz;
    return l1 < l2 || (l1 == l2 && r1 < r2);
}
LL C(LL a, LL b) {
    return a * (a - 1) >> 1;
}
LL modify1(int x, int y) {
    if (x == y) return 0;
    LL ret = 0;
    if (x < y) {
        for (int i = x + 1; i <= y; ++i) {
            ret += cnt[a[i]];
            ++cnt[a[i]];
        }
    }
    else {
        for (int i = x; i > y; --i) {
            ret -= (cnt[a[i]] - 1);
            --cnt[a[i]];
        }
    }
    return ret;
}
LL modify2(int x, int y) {
    if (x == y) return 0;
    LL ret = 0;
    if (x < y) {
        for (int i = x; i < y; ++i) {
            ret -= (cnt[a[i]] - 1);
            --cnt[a[i]];
        }
    }
    else {
        for (int i = x - 1; i >= y; --i) {
            ret += cnt[a[i]];
            ++cnt[a[i]];
        }
    }
    return ret;
}
void work() {
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sz = (int)sqrt(n);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &q[i].l, &q[i].r);
        --q[i].l, --q[i].r;
        q[i].id = i;
    }
    sort(q, q + m, cmp);
//    for (int i = 0; i < m; ++i) printf("%d %d %d\n", q[i].l, q[i].r, q[i].id);
    int l0 = q[0].l, r0 = q[0].r, minn = maxn, maxx = 0;
    for (int i = l0; i <= r0; ++i) {
        minn = min(minn, a[i]); maxx = max(maxx, a[i]);
        ++cnt[a[i]];
    }
    for (int i = minn; i <= maxx; ++i) {
        if (cnt[i] > 1) ans[0].p += C(cnt[i], 2);
    }
    ans[0].q = C(r0 - l0 + 1, 2);

    for (int i = 1; i < m; ++i) {
        int l = q[i].l, r = q[i].r;
        ans[i].p = ans[i - 1].p + modify1(r0, r) + modify2(l0, l);
        ans[i].q = C(r - l + 1, 2);
        l0 = l, r0 = r;
    }
    for (int i = 0; i < m; ++i) {
        LL gcd = GCD(ans[i].p, ans[i].q);
        anss[q[i].id].p = ans[i].p / gcd;
        anss[q[i].id].q = ans[i].q / gcd;
    }
    for (int i = 0; i < m; ++i) printf("%lld/%lld\n", anss[i].p, anss[i].q);
}
int main() {
    freopen("in.txt", "r", stdin);
    while (scanf("%d%d", &n, &m) != EOF) work();
    return 0;
}
