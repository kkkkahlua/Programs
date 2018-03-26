#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 200010
using namespace std;
typedef long long LL;
int a[maxn], b[maxn], bb[maxn];
int main() {
    int n;
    scanf("%d", &n);
    F(i, 0, n) scanf("%d", &a[i]);
    F(i, 0, n) scanf("%d", &b[i]);
    int mod=1, ans=0;
    F(k, 0, 29) {
        F(i, 0, n) bb[i] = b[i] % (mod<<1);
        sort(bb, bb+n);
        int cnt=0;
        F(i, 0, n) {
            int temp=a[i]%(mod<<1);
            int p1=lower_bound(bb, bb+n, mod-temp)-bb,
                p2=lower_bound(bb, bb+n, (mod<<1)-temp)-bb,
                p3=lower_bound(bb, bb+n, mod*3-temp)-bb,
                p4=lower_bound(bb, bb+n, (mod<<2)-temp)-bb;
            cnt += p2-p1+p4-p3;
        }
        ans += cnt&1 ? mod : 0;
        mod <<= 1;
    }
    printf("%d\n", ans);
    return 0;
}
