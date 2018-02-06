#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
typedef long long LL;
int cnt0[maxn], cnt1[maxn], diff[maxn], a[maxn], pos2[maxn<<1], pos1[maxn<<1];
int main() {
//    freopen("in.txt", "r", stdin);
    int n;
    scanf("%d\n", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%c", &a[i]);
        a[i] -= '0';
        cnt0[i] = cnt0[i-1] + !a[i];
        cnt1[i] = cnt1[i-1] + a[i];
        diff[i] = cnt1[i] - cnt0[i]+maxn-10;
    }
    diff[0] = maxn-10;
    for (int i = 0; i <= n; ++i) pos2[diff[i]] = i;
    for (int i = n; i >= 0; --i) pos1[diff[i]] = i;
    int ans = 0;
    for (int i = 0; i <= (maxn<<1)-20; ++i) ans = max(ans, pos2[i] - pos1[i]);
    printf("%d\n", ans);
    return 0;
}
