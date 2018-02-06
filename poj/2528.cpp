#include <stdio.h>
#include <algorithm>
#include <map>
#define maxn 100010
using namespace std;
typedef long long LL;
int a[maxn], l[maxn], r[maxn], fa[maxn], b[maxn];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
map<int,int> mp;
void work() {
    int n;
    scanf("%d", &n);
    int tot=0;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &l[i], &r[i]);
        a[++tot] = l[i], a[++tot] = r[i];
    }
    sort(a+1,a+tot+1);
    tot = unique(a+1,a+tot+1)-a-1;

    b[1] = a[1]; int cnt = 1;
    for (int i = 2; i <= tot; ++i) {
        if (a[i]-a[i-1] == 1) b[++cnt] = a[i];
        else b[++cnt] = a[i-1] + 1, b[++cnt] = a[i];
    }
    for (int i=0; i<=cnt; ++i) fa[i] = i;

    int ans=0;
    for (int i = n-1; i >= 0; --i) {
        int pl = lower_bound(b+1, b+1+cnt, l[i]) - b,
            pr = lower_bound(b+1, b+1+cnt, r[i]) - b;
//        printf("%d %d\n", pl, pr);
        if (find(pr)<pl) continue;
        ++ans;
        for (int j = find(pr); j >= pl; j = find(j-1)) {
            fa[find(j)] = find(pl-1);
        }
    }
    printf("%d\n", ans);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
