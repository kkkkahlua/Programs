#include <bits/stdc++.h>
#define MAXN 5010
#define mod 998244353
using namespace std;
typedef long long LL;
LL inv[MAXN];
LL fac[MAXN];
LL Com(int n,int m){
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
void init(){
    inv[0]=fac[0]=1;
    inv[1]=1;
    for(int i=1;i<MAXN;i++){
        fac[i]=fac[i-1]*i%mod;
    }
    inv[1]=1;
    for(int i=2;i<MAXN;i++){
        inv[i]=(LL)(mod-mod/i)*inv[mod%i]%mod;
    }
    inv[0]=1;
    for(int i=1;i<MAXN;i++){
        inv[i]=inv[i-1]*inv[i]%mod;
    }
}
LL add(LL a, LL b) { return (a+b) % mod; }
LL mul(LL a, LL b) { return a * b % mod; }
LL f(int a, int b) {
    int lim = min(a, b);
    LL ret = 0;
    for (int i = 1; i <= lim; ++i) ret = add(ret, mul(mul(Com(a, i), Com(b, i)), fac[i]));
    return ret;
}
int main() {
//    freopen("in.txt", "r", stdin);
    init();
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    LL x1 = f(a, b), x2 = f(a, c), x3 = f(b, c);
    LL ans = add(1, add(x1, add(x2, x3)));
    ans = add(ans, add(mul(x1, x2), add(mul(x1, x3), mul(x2, x3))));
    ans = add(ans, mul(x1, mul(x2, x3)));
    printf("%I64d", ans);
    return 0;
}
