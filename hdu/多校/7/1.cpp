#include <bits/stdc++.h>
#define maxn 200010
using namespace std;
typedef long long LL;
LL ds[110],ss[110],fx[110],ans,n,k;
LL calc(LL dep,LL n){
    if (dep == 1) return 1;
    if (dep == 2){
        if (n & 1) return n;
        else return n ^ 1;
    }
    LL ls = ss[dep] - n, nlcnt = ls / ds[dep - 1], ncnt = ds[dep - 1] - nlcnt;
    if (ls % ds[dep - 1]) --ncnt;
    LL tmp = n;
    if (ncnt & 1) tmp ^= fx[dep - 1];
    if (nlcnt & 1) tmp ^= fx[dep - 2];
    if (ls % ds[dep - 1]) return tmp ^ calc(dep -1, ss[dep - 1] - ls % ds[dep - 1]);
    else return tmp;
}
void work() {
    scanf("%lld %lld", &n, &k);
    memset(ds, 0, sizeof ds);
    memset(ss, 0, sizeof ss);
    memset(fx, 0, sizeof fx);
    LL dep = 1;
    bool flag = k & 1;
    ds[1] = ss[1] = fx[1] = 1;
    for(int i=2;i<110;++i){
        ds[i] = ds[i-1] * k;
        ss[i] = ss[i-1] + ds[i];
        if (flag) fx[i] = fx[i-1] ^ ss[i];
        else fx[i] = ss[i];
        if (ss[i] >= n || ds[i - 1] > 1e18 / k) {
            dep = i;
            break;
        }
    }
    ans = calc(dep, n);
    printf("%lld\n",ans);
}
int main() {
    //freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
