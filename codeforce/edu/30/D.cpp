#include <bits/stdc++.h>
#define maxn 100010
int a[maxn], ans[maxn];
using namespace std;
typedef long long LL;
void work(int l, int r, int k, int pl) {
    if (k > 2*(r-l)-1) { puts("-1"); exit(0); }
    --k;
    if (k==0) { for (int i = l; i < r; ++i) ans[i] = a[pl++]; return; }
    int nl=k>>1, nr = k>>1;
    if (!((k>>1)&1)) --nl, ++nr;
    work(l, l+r>>1, nl, pl+((r-l+1)>>1));
    work(l+r>>1, r, nr, pl);
}
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    if ((!(k&1)) || k>2*n-1) { puts("-1"); exit(0); }
    for (int i = 1; i <= n; ++i) a[i] = i;
    work(0, n, k, 1);
    printf("%d", ans[0]);
    for (int i = 1; i < n; ++i) printf(" %d", ans[i]); puts("");
    return 0;
}
