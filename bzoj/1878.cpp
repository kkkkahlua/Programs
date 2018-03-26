#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 50010
#define maxm 200010
#define maxl 1000010
using namespace std;
typedef long long LL;
int temp, bl[maxn], a[maxn], ans[maxm], cnt[maxl];
struct node {
    int l,r,id;
    bool operator < (const node& nd) const {
        return bl[l]==bl[nd.l] ? r<nd.r : bl[l]<bl[nd.l];
    }
}q[maxm];
inline void add(int x) { if (!cnt[x]) ++temp; ++cnt[x]; }
inline void del(int x) { --cnt[x]; if (!cnt[x]) --temp; }
int main() {
//    freopen("in.txt", "r", stdin);
    int n, blo, m;
    scanf("%d", &n); blo = sqrt(n);
    F2(i, 1, n) scanf("%d", &a[i]), bl[i]=(i-1)/blo+1;
    scanf("%d", &m);
    F(i, 0, m) {
        scanf("%d%d",&q[i].l,&q[i].r);
        q[i].id = i;
    }
    sort(q,q+m);
    int r=0,l=1;
    F(i, 0, m) {
        while (r<q[i].r) add(a[++r]);
        while (r>q[i].r) del(a[r--]);
        while (l<q[i].l) del(a[l++]);
        while (l>q[i].l) add(a[--l]);
        ans[q[i].id] = temp;
    }
    F(i, 0, m) printf("%d\n", ans[i]);
    return 0;
}
