#include <bits/stdc++.h>
#define maxn 300010
using namespace std;
typedef long long LL;
void work() {
}
struct node { LL x; int y; }a[maxn];
int anss[maxn];
bool cmp(node u, node v) {
    return u.x > v. x || (u.x == v.x && u.y < v.y);
}
set<int> s;
int main() {
//    freopen("in.txt", "r", stdin);
//    int T;
//    while (T--) work();
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%I64d", &a[i].x);
        a[i].y = i;
    }
    sort(a+1, a+1+n, cmp);
    for (int i = k+1; i <= k+n; ++i) s.insert(i);
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        auto it = s.lower_bound(a[i].y);
        anss[a[i].y] = *it;
        ans += 1LL * (*it - a[i].y) * a[i].x;
        s.erase(it);
    }
    printf("%I64d\n%d", ans, anss[1]);
    for (int i = 2; i <= n; ++i) printf(" %d", anss[i]); printf("\n");
    return 0;
}
