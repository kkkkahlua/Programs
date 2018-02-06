#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
//    freopen("in.txt", "r", stdin);
    int a, b, c, x;
    scanf("%d%d%d%d", &a, &b, &c, &x);
    x /= 50;
    int ans = 0;
    for (int i = 0; i <= min(a, x/10); ++i) {
        for (int j = 0; j <= min(b, (x-i*10)/2); ++j) {
            if (x - i * 10 - j * 2 <= c) ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}
