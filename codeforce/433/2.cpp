#include <bits/stdc++.h>
#define maxn
using namespace std;
typedef long long LL;
void work() {
}
int main() {
//    freopen("in.txt", "r", stdin);
//    int T;
//    while (T--) work();
    LL n, k;
    scanf("%I64d%I64d", &n, &k);
    if (n == k || k == 0 || n == 0) printf("0 0\n");
    else {
        printf("1 ");
        if (3 * k <= n) printf("%I64d\n", (LL)2*k);
        else printf("%I64d\n", n-k);
    }
    return 0;
}
