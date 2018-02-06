#include <bits/stdc++.h>
#define maxn 200010
using namespace std;
typedef long long LL;
int n, k;
LL ds[40],ss[40],fx[40],ans;
LL calc(int dep,int n){
    int ls = ss[dep] - n, nlcnt = ls / k, ncnt = ds[dep] - nlcnt - 1;
    LL tmp = 0;
    if (ncnt & 1) tmp ^= fx[dep - 1];
    if (nlcnt & 1) tmp ^= fx[dep - 2];
    return tmp ^ calc(dep -1, ss[dep - 1] - ls % k);
}
void work() {
    scanf("%d %d", &n, &k);
    memset(ds, 0, sizeof ds);
    memset(ss, 0, sizeof ss);
    memset(fx, 0, sizeof fx);
    int dep = 1;
    bool flag = k & 1;
    ds[1] = ss[1] = fx[1] = 1;
    for(int i=2;i<40;++i){
        ds[i] = ds[i-1] * k;
        ss[i] = ss[i-1] + ds[i];
        if (flag) fx[i] = fx[i-1] ^ ss[i];
        else fx[i] = ss[i];
        if (ss[i] > n) {
            dep = i;
            break;
        }
    }
    ans = calc(dep, n);
    printf("%lld",ans);
}
int main() {
    //freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
