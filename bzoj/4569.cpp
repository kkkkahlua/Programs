#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 100000
#define maxk 17
using namespace std;
typedef long long LL;
bool vis[maxn+10];
int sz[maxk+1][maxn+10], fa[maxk+1][maxn+10], Log[maxn+10], bi[maxk+1], n, m;
inline int find(int dep, int x) {
    return fa[dep][x]==x ? x : fa[dep][x]=find(dep, fa[dep][x]);
}
inline void unionn(int dep, int x, int y) {
    x = find(dep, x), y = find(dep, y);
    if (x==y) return;
    if (sz[dep][x]>sz[dep][y]) swap(x, y);
    fa[dep][x] = y;
}
void init() {
    Log[0] = -1; bi[0] = 1;
    F2(i, 1, maxn) Log[i] = Log[i>>1]+1;
    int k=Log[n];
    F2(i, 1, maxk) {
        bi[i] = bi[i-1]<<1;
    }
    F2(i, 0, maxk) F2(j, 1, n) fa[i][j]=j, sz[i][j]=1;
}
const LL mod=1e9+7;
LL poww(LL a, LL b) {
    LL ret=1;
    while (b) {
        if (b&1) (ret*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return ret;
}
int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%d%d", &n,&m);
    init();
    F(i, 0, m) {
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        int dep=Log[r1-l1+1];
        unionn(dep, l1, l2);
        unionn(dep, r1-bi[dep]+1, r2-bi[dep]+1);
    }
    dF(dep, maxk, 0) {
        F2(i, 1, n) {
            int x=find(dep, i);
            unionn(dep-1, i, x);
            unionn(dep-1, i+bi[dep-1], x+bi[dep-1]);
        }
    }
    int ans=0;
    F2(i, 1, n) ans += (find(0, i)==i);
    printf("%lld\n", poww(10, ans-1)*9%mod);
    return 0;
}
