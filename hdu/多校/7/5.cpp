#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
void work() {
    int n;
    scanf("%d", &n);
    int ans = 0;
    if (n & 1) ans = n - (n + 1) / 2 + 1 + 1;
    else ans = n - n / 2 + 1;
    printf("%d\n", ans);
}
int main() {
//    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
