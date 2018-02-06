#include <bits/stdc++.h>
#define PI acos(-1.0)
#define maxn 200010
typedef long long LL;
using namespace std;
struct node {
    LL x, y;
}s, t, p[maxn];
bool cmp1(node u, node v) { return u.y < v.y; }
bool cmp2(node u, node v) { return u.y > v.y; }
LL a[maxn];
int main() {
    scanf("%lld%lld%lld%lld", &s.x, &s.y, &t.x, &t.y);
    double ans = 1.0 * (abs(s.x-t.x)+abs(s.y-t.y)) * 100;
    LL n;
    scanf("%lld", &n);
    for (LL i = 0; i < n; ++i) scanf("%lld%lld", &p[i].x, &p[i].y);
    if (s.x == t.x) {
        LL lo = s.y, hi = t.y;
        if (lo > hi) swap(lo, hi);
        bool flag = false;
        for (LL i = 0; i < n; ++i) {
            if (p[i].x == s.x && p[i].y > lo && p[i].y < hi) { flag = true; break; }
        }
        if (flag) ans += (PI * 10 - 20);
    }
    else {
        if (s.x > t.x) swap(s, t);
        if (s.y < t.y) {
            sort(p, p + n, cmp1);
            LL i = 0, tot = 0, cnt = 0;
            vector<LL> v(n+1, 1e18);
            while (p[i].y < s.y) ++i;
            for (; i < n; ++i) {
                if (p[i].y > t.y) break;
                if (p[i].x < s.x || p[i].x > t.x) continue;
                *lower_bound(v.begin(), v.end(), p[i].x) = p[i].x;
            }
            cnt = lower_bound(v.begin(), v.end(), 1e18) - v.begin();
            if (cnt == min(t.y-s.y, t.x-s.x)+1) {
                --cnt;
                ans += (PI * 5 - 20) * cnt;
                ans += (PI * 10 - 20);
            }
            else ans += (PI * 5 - 20) * cnt;
        }
        else if (s.y > t.y) {
            sort(p, p + n, cmp2);
            LL i = 0, tot = 0, cnt = 0;
            vector<LL> v(n+1, 1e18);
            while (p[i].y > s.y) ++i;
            for (; i < n; ++i) {
                if (p[i].y < t.y) break;
                if (p[i].x < s.x || p[i].x > t.x) continue;
                *lower_bound(v.begin(), v.end(), p[i].x) = p[i].x;
            }
            cnt = lower_bound(v.begin(), v.end(), 1e18) - v.begin();
            if (cnt == min(s.y-t.y, t.x-s.x)+1) {
                --cnt;
                ans += (PI * 5 - 20) * cnt;
                ans += (PI * 10 - 20);
            }
            else ans += (PI * 5 - 20) * cnt;
        }
        else {
            bool flag = false;
            for (LL i = 0; i < n; ++i) {
                if (p[i].y == s.y && p[i].x > s.x && p[i].x < t.x) { flag = true; break; }
            }
            if (flag) ans += (PI * 10 - 20);
        }
    }
    printf("%.15f\n", ans);
    return 0;
}
/*
0 0 5 3
4
1 0
2 1
3 2
4 3
*/
