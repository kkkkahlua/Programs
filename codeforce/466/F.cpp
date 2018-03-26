#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 100010
using namespace std;
typedef long long LL;
int n,m,blo,temp,nn,a[maxn],t[maxn], bl[maxn], cnt[maxn<<1], num[maxn<<1], l, r, mp[maxn<<1], tot, ans[maxn],
    cnt1, cnt2, tim;
struct qnode {
    int l,r,tim,id;
    bool operator < (const qnode& nd) const {
        return bl[l]==bl[nd.l] ? (bl[r]==bl[nd.r] ? tim<nd.tim : bl[r]<bl[nd.r]) : bl[l]<bl[nd.l];
    }
}q[maxn];
struct cnode { int x, yt, ys; }c[maxn];
inline void add(int x) { --num[cnt[x]]; ++num[++cnt[x]]; }
inline void del(int x) { --num[cnt[x]]; ++num[--cnt[x]]; }
inline void cha(int x, int y) {
    if (l<=x&&x<=r) del(a[x]), add(y);
    a[x] = y;
}
void discrete() {
    sort(mp, mp+tot);
    nn=unique(mp, mp+tot)-mp;
    F2(i, 1, n) a[i]=lower_bound(mp,mp+nn,a[i])-mp+1;
    F2(i, 1, cnt2) c[i].ys=lower_bound(mp,mp+nn,c[i].ys)-mp+1, c[i].yt=lower_bound(mp,mp+nn,c[i].yt)-mp+1;
}
int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    scanf("%d%d", &n, &m); blo = pow(n, 2.0/3.0);
    F2(i, 1, n) scanf("%d", &a[i]), t[i] = mp[tot++] = a[i], bl[i]=(i-1)/blo;
    F(i, 0, m) {
        int op,l,r;
        scanf("%d%d%d",&op,&l,&r);
        if (op==1) q[cnt1] = {l, r, tim, cnt1}, ++cnt1;
        else ++tim, c[++cnt2] = {l, r, t[l]}, t[l] = r, mp[tot++] = r;
    }
    discrete();
    sort(q, q+cnt1);
    r=0, l=1;
    num[0]=nn+1; tim=0;
    F(i, 0, cnt1) {
        while (tim<q[i].tim) tim++, cha(c[tim].x, c[tim].yt);
        while (tim>q[i].tim) cha(c[tim].x, c[tim].ys), --tim;
        while (r<q[i].r) add(a[++r]);
        while (l>q[i].l) add(a[--l]);
        while (r>q[i].r) del(a[r--]);
        while (l<q[i].l) del(a[l++]);
        int temp=0;
        while (num[temp]) ++temp;
        ans[q[i].id] = temp;
    }
    F(i, 0, cnt1) printf("%d\n", ans[i]);
    return 0;
}
