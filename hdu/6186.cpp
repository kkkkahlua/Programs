#include <bits/stdc++.h>
#define maxn 100010
typedef long long LL;
LL a[maxn], and1[maxn], and2[maxn], or1[maxn], or2[maxn], xor1[maxn], xor2[maxn];
LL n, q;
void work() {
    for (LL i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    and1[1] = or1[1] = xor1[1] = a[1], and2[n] = or2[n] = xor2[n] = a[n];
    for (LL i = 2; i <= n; ++i) {
        and1[i] = and1[i-1] & a[i];
        or1[i] = or1[i-1] | a[i];
        xor1[i] = xor1[i-1] ^ a[i];
    }
    for (LL i = n-1; i >= 1; --i) {
        and2[i] = and2[i+1] & a[i];
        or2[i] = or2[i+1] | a[i];
        xor2[i] = xor2[i+1] ^ a[i];
    }
    while (q--) {
        LL x, ans1, ans2, ans3;
        scanf("%lld", &x);
        if (x == 1) ans1 = and2[2], ans2 = or2[2], ans3 = xor2[2];
        else if (x == n) ans1 = and1[n-1], ans2 = or1[n-1], ans3 = xor1[n-1];
        else ans1 = and1[x-1] & and2[x+1], ans2 = or1[x-1] | or2[x+1], ans3 = xor1[x-1] ^ xor2[x+1];
        printf("%lld %lld %lld\n", ans1, ans2, ans3);
    }
}
int main() {
    while (scanf("%lld%lld", &n, &q) != EOF) work();
    return 0;
}
