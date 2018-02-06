#include <stdio.h>
#include <iostream>
#define maxn 100010
using namespace std;
typedef long long LL;
int a[maxn], st[maxn], l[maxn];
LL pre[maxn];
int main() {
//    freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        pre[i] = pre[i-1] + a[i];
    }
    int top = 0;
    a[++n] = -1;
    LL ans = -1; int lll, rrr;
    for (int i = 1; i <= n; ++i) {
        int x, ll=i, rr=i-1;
        while (top && a[i] < a[st[top-1]]) {
            x = st[--top], ll = l[x];
            LL temp = a[x] * (pre[rr] - pre[ll-1]);
            if (temp > ans) ans = temp, lll = ll, rrr = rr;
        }
        l[i] = ll; st[top++] = i;
    }
    printf("%lld\n%d %d\n", ans, lll, rrr);
    return 0;
}
