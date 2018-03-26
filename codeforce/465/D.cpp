#include <bits/stdc++.h>
#define maxn 100010
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
typedef long long LL;
const LL mod = 1e9+7;
int a[maxn], b[maxn];
LL rec[maxn*2];
LL poww(LL a, LL b) {
    LL ret = 1;
    while (b) {
        if (b&1) (ret *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return ret;
}
LL f(LL p, LL q) {
    return p * poww(q, mod-2) % mod;
}
LL GCD(LL a, LL b) { return b ? GCD(b, a%b) : a; }
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    LL NUM = (1LL*m*m%mod-m+mod)%mod * poww(2, mod-2) % mod;
    int tot=0;
    F(i, 0, n) { scanf("%d", &a[i]); if (!a[i]) ++tot; }
    F(i, 0, n) { scanf("%d", &b[i]); if (!b[i]) ++tot; }
    rec[0] = 1;
    F2(i, 1, tot) rec[i] = rec[i-1]*m%mod;
    LL q = poww(m, tot), p=0;
    int cnt=0, prev=0;
    F(i, 0, n) {
        if (a[i]&&b[i]) {
            if (a[i]>b[i]) (p += rec[cnt+tot-prev]) %= mod;
            if (a[i]!=b[i]) { printf("%I64d\n", f(p, q)); return 0; }
        }
        else if (!a[i] && !b[i]) {
            prev += 2;
            (p += (rec[cnt+tot-prev] * NUM % mod)) %= mod;
            ++cnt;
        }
        else {
            ++prev;
            if (a[i]) (p += rec[cnt+tot-prev] * (a[i]-1) % mod) %= mod;
            else (p += (rec[cnt+tot-prev] * (m-b[i]) % mod)) %= mod;
        }
    }
    LL gcd = GCD(p, q);
    p /= gcd, q /= gcd;
    printf("%I64d\n", f(p, q));
    return 0;
}
