#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
int ans[maxn];
struct node {
    int idx, val;
    bool operator < (const node nd) const { return val > nd.val; }
}a[maxn];
void work() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i].val);
        a[i].idx = i;
    }
    sort(a+1, a+1+n);
    for (int i = 2; i <= n; ++i) {
        int j = 1;
        for (; j <= n; ++j) if (a[j].idx % i) break;
        ans[i] = a[j].val;
    }
    printf("%d", ans[2]);
    for (int i = 3; i <= n; ++i) printf(" %d", ans[i]); printf("\n");
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
