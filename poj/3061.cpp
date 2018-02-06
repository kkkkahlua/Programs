#include <cstdio>
#define maxn 100010
#define inf 0x3f3f3f3f
typedef long long LL;
LL a[maxn];
inline int min(int a, int b) { return a < b ? a : b; }
void work() {
    int n; LL s;
    scanf("%d%lld", &n, &s);
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    int l = 0, r = 0, ans = inf;
    LL sum = 0;
    while (true) {
        while (r < n && sum < s) {
            sum += a[r++];
        }
        if (sum < s) break;
        ans = min(r - l, ans);
        sum -= a[l++];
    }
    if (ans == inf) ans = 0;
    printf("%d\n", ans);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
