#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 1010
using namespace std;
typedef long long LL;
int d1[maxn], d2[maxn], tot1, tot2, tot, n, a[maxn];
int* d;
vector<int> ans;
void solve() {
//    printf("%d\n", tot);
//    F(i, 0, tot) printf("%d ", d[i]);
    F(i, 1, d[0]) ans.push_back(1);
    dF(i, n, d[tot-1]) ans.push_back(i-d[0]+1);
    F2(i, 1, tot-1) {
        int lim=(d[i]-d[i-1])>>1;
        dF(j, 1+lim, 1) ans.push_back(j);
    }
}
int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &n);
    int p=1;
    F2(i, 1 ,n) {
        scanf("%d", &a[i]);
        p = a[i] > a[p] ? i : p;
    }
    LL sum;
    if (a[p]<=0) d1[tot++]=p, sum=a[p], d=d1;
    else {
        LL sum1=0, sum2=0;
        for (int i = 1; i <= n; i += 2) if (a[i]>0) d1[tot1++]=i, sum1+=a[i];
        for (int i = 2; i <= n; i += 2) if (a[i]>0) d2[tot2++]=i, sum2+=a[i];
        d = sum1 < sum2 ? d2 : d1;
        tot = sum1 < sum2 ? tot2 : tot1;
        sum = max(sum1, sum2);
    }
    solve();
    printf("%lld\n%d\n", sum, ans.size());
    for (auto x : ans) printf("%d\n", x);
    return 0;
}
