#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    int n;
    scanf("%d", &n);
    int cnt = 0, x;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        if (x&1) ++cnt;
    }
    int ans1 = 1;
    for (int i = 1; i <= n; ++i) {
        ans1 *= 3;
    }
    int ans2 = 1;
    for (int i = 1; i <= n-cnt; ++i) {
        ans2 *= 2;
    }
    printf("%d\n", ans1-ans2);
    return 0;
}
