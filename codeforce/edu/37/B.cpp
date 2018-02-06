#include <bits/stdc++.h>
#define maxn 1010
using namespace std;
typedef long long LL;
struct node {
    int l, r, id;
}a[maxn];
int ans[maxn];
bool cmp(node a, node b) {
    return (a.l < b.l) || (a.l==b.l && a.id<b.id);
}
void work() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i].l, &a[i].r);
        a[i].id = i;
    }
    sort(a, a+n, cmp);
    int time = 0;
    for (int i = 0; i < n; ++i) {
        if (time <= a[i].l) {
            time = a[i].l;
            ans[a[i].id] = time;
            ++time;
        }
        else {
            if (time <= a[i].r) {
                ans[a[i].id] = time;
                ++time;
            }
            else {
                ans[a[i].id] = 0;
            }
        }
    }
    printf("%d", ans[0]);
    for (int i = 1; i < n; ++i) printf(" %d", ans[i]); puts("");
}
int main() {
//    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
