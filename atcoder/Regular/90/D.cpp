#include <bits/stdc++.h>
#define lim1 10000000
#define lim2 22500000
using namespace std;
typedef long long LL;
int f[lim2+10];
const LL mod = 1e9+7;
void init() {
    int l = 1, r = 10;
    for (int k = 1; k <= 7; ++k) {
        for (int i = l; i < r; ++i) f[i] = k;
        l = r; r *= 10;
    }
    for (int i = lim1; i <= lim2; ++i) f[i] = 8;
}
LL poww(LL a, LL b) {
    LL ret = 1;
    while (b) {
        if (b & 1) (ret *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return ret;
}
LL count1(LL x) {
    int l = 1, r = 1, ret = 0; LL sum = 0;
    while (true) {
        while (r <= lim2 && sum < x) sum += f[r++];
        if (sum < x) break;
        if (sum == x) (ret += 1) %= mod;
        sum -= f[l++];
        if (l == lim1) break;
    }
    return ret;
}
LL count2(LL x) {
    LL upp = x/8,
        ret = upp;
    for (int t = 1; t <= upp; ++t) {
        if (x % t == 0) {
            int len = x / t;
            LL sub = 9 * poww(10, len-1) % mod;
            (sub += mod - t) %= mod;
            (ret += sub) %= mod;
        }
    }
    return ret;
}
int main() {
//    freopen("in.txt", "r", stdin);
    init();
    LL n;
    scanf("%lld", &n);
    LL ans1 = count1(n), ans2 = count2(n);
    printf("%lld\n", (ans1+ans2)%mod);
    return 0;
}
