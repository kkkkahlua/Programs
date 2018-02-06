#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL base[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000}, cnt;
int l, d;
int digit(int x) {
    int ret=0;
    for (; x; x /= 10, ++ret);
    return ret;
}
void dfs(int p, LL tot, LL mul) {
    printf("%d %lld %lld\n", p, tot, mul);
    if (p == l/2) {
        if (tot == d) cnt += mul;
        cout << cnt << endl;
        return;
    }
    for (int i = -9; i <= 0; ++i) {
        printf("%d %d\n", p, i);
        dfs(p+1, tot + i * (base[l-1-p]-base[p]), mul * (i+10));
    }
    for (int i = 1; i <= 9; ++i) {
        dfs(p+1, tot + i * (base[l-1-p]-base[p]), mul * (10-i));
    }
}
int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%d", &d);
    int len = digit(d);
    int lo = len, hi = (len<<1) - 2;
    l = lo;
    for (l = lo; l <= hi; ++l) {
        for (int i = 0; i <= 8; ++i) dfs(1, i * (base[l-1] - base[0]), 9-i);
    }
    printf("%lld\n", cnt);
    return 0;
}
