#include <bits/stdc++.h>
#define maxn 200010
using namespace std;
typedef long long LL;
int cnt[maxn], flag[maxn];
int main() {
    int n, k, q;
    scanf("%d%d%d", &n, &k, &q);
    int mn = maxn, mx = 0, l, r, x, y;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &l, &r);
        ++cnt[l], --cnt[r+1];
        mn = min(mn, l), mx = max(mx, r);
    }
    for (int i = 1; i <= 200000; ++i) {
        cnt[i] += cnt[i-1];
        if (cnt[i] >= k) flag[i] = 1;
    }
    for (int i = 1; i <= 200000; ++i) flag[i] += flag[i-1];
    while (q--) {
        scanf("%d%d", &x, &y);
        printf("%d\n", flag[y] - flag[x-1]);
    }
    return 0;
}
