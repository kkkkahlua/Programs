#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    int n, a ,b,c;
    scanf("%d", &n);
    --n;
    scanf("%d%d%d", &a,&b,&c);
    if (n==0) { putchar('0'); exit(0); }
    if (b > a) swap(a,b);
    int ans = b;
    --n;
    if (b > c) ans += n*c;
    else ans += n*b;
    printf("%d\n", ans);
    return 0;
}
