#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 50010
using namespace std;
typedef long long LL;
LL temp, ans[maxn];
int n, nn, blo, m, cnt, bl[maxn], a[maxn], mp[maxn], c[maxn];
struct node {
    int l, r, id;
    bool operator < (const node& nd) const {
        return bl[l]==bl[nd.l] ? r<nd.r : bl[l]<bl[nd.l];
    }
}q[maxn];
inline int lowbit(int x) { return x&(-x); }
inline int query(int x) { int ret=0; while (x) ret+=c[x], x-=lowbit(x); return ret; }
inline void add(int x, int v) { while (x<=nn) c[x]+=v, x+=lowbit(x); }
inline void addt(int x) { temp+=cnt-query(x); ++cnt; add(x,1); }
inline void delt(int x) { --cnt; add(x,-1); temp-=cnt-query(x); }
inline void adds(int x) { temp+=query(x-1); ++cnt; add(x,1); }
inline void dels(int x) { --cnt; add(x,-1); temp-=query(x-1); }
void discrete() {
    sort(mp+1, mp+n+1);
    nn = unique(mp+1, mp+n+1)-(mp+1);
    F2(i, 1, n) a[i] = lower_bound(mp+1,mp+nn+1,a[i])-mp;
}
int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%d", &n); blo=sqrt(n);
    F2(i, 1, n) scanf("%d", &a[i]), mp[i]=a[i], bl[i]=(i-1)/blo;
    discrete();
    scanf("%d", &m);
    F(i, 0, m) {
        scanf("%d%d", &q[i].l, &q[i].r);
        q[i].id = i;
    }
    sort(q,q+m);
    int r=0, l=1, cnt=0;
    F(i, 0, m) {
        while (r<q[i].r) addt(a[++r]);
        while (r>q[i].r) delt(a[r--]);
        while (l<q[i].l) dels(a[l++]);
        while (l>q[i].l) adds(a[--l]);
        ans[q[i].id] = temp;
    }
    F(i, 0, m) printf("%lld\n", ans[i]);
    return 0;
}
