#include <stdio.h>
#include <algorithm>
#include <map>
#define maxn 10010
#define maxl 10000010
using namespace std;
typedef long long LL;
int l[maxn], r[maxn], fa[maxl];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void work() {
    int n;
    scanf("%d", &n);
    int tot=0;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &l[i], &r[i]);
    }
    for (int i=0; i<=maxl-9; ++i) fa[i] = i;

    int cnt=0;
    for (int i=n-1; i>=0; --i) {
        if (find(l[i]) > r[i]) continue;
        ++cnt;
        for (int j=find(l[i]); j<=r[i]; j=find(j)) {
            fa[find(j)] = find(r[i]+1);
        }
    }

    printf("%d\n", cnt);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
