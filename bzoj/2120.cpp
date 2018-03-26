#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 10010
#define maxm 1000010
using namespace std;
typedef long long LL;
int n,m,l,r,temp, cnt[maxm], a[maxn], t[maxn], bl[maxn], blo,ans[maxn];
struct qnode {
    int l,r,tim,id;
    bool operator < (const qnode& nd) const {
        return bl[l]==bl[nd.l] ? (bl[r]==bl[nd.r] ? tim<nd.tim : bl[r]<bl[nd.r]) : bl[l]<bl[nd.l];
    }
}q[maxn];
struct rnode { int x, ya, yb; }c[maxn];
inline void add(int x) { if (!cnt[x]) ++temp; ++cnt[x]; }
inline void del(int x) { --cnt[x]; if (!cnt[x]) --temp; }
inline void cha1(rnode& nd) { if (l<=nd.x&&nd.x<=r) del(nd.yb), add(nd.ya); a[nd.x] = nd.ya; }
inline void cha2(rnode& nd) { if (l<=nd.x&&nd.x<=r) del(nd.ya), add(nd.yb); a[nd.x] = nd.yb; }
int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d%d",&n,&m); blo = sqrt(n);
    F2(i, 1, n) scanf("%d", &a[i]), t[i]=a[i], bl[i]=(i-1)/blo+1;
    int tim=0,cnt1=0,cnt2=0;
    F(i, 0, m) {
        char ch; int x, y;
        scanf("\n%c%d%d", &ch,&x,&y);
        if (ch=='R') ++tim, c[++cnt2] = {x,y,t[x]}, t[x]=y;
        else q[cnt1] = {x,y,tim,cnt1}, cnt1++;
    }
    sort(q,q+cnt1);
    r=0, l=1; tim=0;
    F(i, 0, cnt1) {
        while (tim<q[i].tim) cha1(c[++tim]);
        while (tim>q[i].tim) cha2(c[tim--]);
        while (r<q[i].r) add(a[++r]);
        while (r>q[i].r) del(a[r--]);
        while (l<q[i].l) del(a[l++]);
        while (l>q[i].l) add(a[--l]);
        ans[q[i].id] = temp;
    }
    F(i, 0, cnt1) printf("%d\n", ans[i]);
    return 0;
}
