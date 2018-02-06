#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
//    freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    LL s = 0;
    for (int i = 0; i < n; ++i) {
        LL x, y;
        scanf("%I64d%I64d", &x, &y);
        if (x > s) s = x;
        else {
            int k = (s-x) / y+1;
            s = x + k * y;
        }
    }
    printf("%I64d\n", s);
    return 0;
}
