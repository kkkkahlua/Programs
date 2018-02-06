#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int cnt[210];
int main() {
    int n,x;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        while (!(x & 1)) {
            x >>= 1;
            ++cnt[i];
        }
    }
    int ans = 100;
    for (int i = 0; i < n; ++i) ans = min(ans, cnt[i]);
    printf("%d\n", ans);
    return 0;
}
