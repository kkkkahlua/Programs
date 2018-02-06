#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
void work() {
    in (n * m & 1) { puts("0"); return; }
    if (n < m) swap(n, m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < (1<<m); ++k) {
                LL* pre = dp[0], *cur = dp[1];
                if ((k>>j) & 1) {
                    if (i > 1) cur[k] += pre[]
                }
            }
        }
    }
}
int main() {
    freopen("in.txt", "r", stdin);
    while (scanf("%d%d", &n, &m) != EOF && n && m) work();
    return 0;
}
