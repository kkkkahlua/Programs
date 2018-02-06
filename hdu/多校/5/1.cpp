#include <bits/stdc++.h>
#define maxn 50010
using namespace std;
bool ans[maxn], exist[maxn];
bitset<maxn> aa, xx;
inline int max(int a, int b) { return a > b ? a : b; }
void work() {
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    int ma = 0, mb = 0;
    aa.reset(); xx.reset();
    memset(exist, 0, sizeof(exist));
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        aa.set(x);
        ma = max(ma, x);
    }
    for (int i = 0; i < m; ++i) {
        int x;
        scanf("%d", &x);
        mb = max(mb, x);
        exist[x] = true;
    }
    for (int i = mb; i >= 0; --i) {
        ans[i] = ((xx << i) & aa).count() & 1;
        if (exist[i]) {
            for (int j = 0; j <= ma; j += i) xx.flip(j);
        }
    }
    while (q--) {
        int x;
        scanf("%d", &x);
        printf("%d\n", ans[x]);
    }
}
int main() {
//    freopen("in.txt", "r", stdin);
    freopen("多校第五场数据和标程/数据/1001.in", "r", stdin);
    freopen("01.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
