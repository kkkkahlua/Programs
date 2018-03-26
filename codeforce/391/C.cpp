#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 1000010
using namespace std;
typedef long long LL;
int n, m, x, y;
LL f[maxn];
vector<int> v[maxn];
const LL mod=1e9+7;
void init() {
    f[0] = 1;
    F2(i, 1, m) f[i] = f[i-1]*i%mod;
}
int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%d%d", &n,&m);
    F(i, 0, n) {
        scanf("%d", &x);
        F(j, 0, x) {
            scanf("%d", &y);
            v[y].push_back(i);
        }
    }
    init();
    sort(v+1, v+1+m);
    int cnt=1; LL ans=1;
    F2(i, 2, m) {
        if (v[i]==v[i-1]) ++cnt;
        else {
            (ans *= f[cnt]) %= mod;
            cnt=1;
        }
    }
    (ans *= f[cnt]) %= mod;
    printf("%I64d\n", ans);
    return 0;
}
