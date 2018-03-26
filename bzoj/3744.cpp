#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 50010
#define maxb 310
using namespace std;
typedef long long LL;
int a[maxn], mp[maxn], c[maxn], cnt[maxb][maxn], bl[maxn];
int n, m, nn, num, blo;
struct node { int l, r; }b[maxb];
int f[maxb][maxn];
inline int read(){
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1; c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0'; c=getchar();}
    return x*f;
}
inline int lowbit(int x) { return x & -x;}
inline int query(int x) { int ret=0; while (x) ret += c[x], x-=lowbit(x); return ret; }
inline void add(int x, int v) { while (x<=nn) c[x] += v, x+=lowbit(x); }
void init(int s) {
    b[s].l=s*blo, b[s].r=(s==num-1?n:b[s].l+blo);
    memset(c, 0, sizeof c);
    F(i, b[s].l, n) {
        f[s][i] = f[s][i-1] + i-b[s].l-query(a[i]);
        add(a[i], 1);
    }
    F(i, b[s].l, b[s].r) ++cnt[s][a[i]];
    F2(i, 1, nn) cnt[s][i] += cnt[s][i-1];
    F2(i, 1, nn) cnt[s][i] += cnt[s-1][i];
}
int ask(int l, int r) {
    int ret=0;
    if (bl[l]==bl[r]) {
        memset(c, 0, sizeof c);
        F2(i, l, r) {
            ret += i-l-query(a[i]);
            add(a[i], 1);
        }
    }
    else {
        ret += f[bl[l]+1][r];
        memset(c, 0, sizeof c);
        F(i, l, b[bl[l]].r) {
            ret += i-l-query(a[i]);
            add(a[i], 1);
            ret += cnt[bl[r]-1][a[i]-1]-cnt[bl[l]][a[i]-1];
        }
        int ex=b[bl[l]].r-l;
        F2(i, b[bl[r]].l, r) ret += ex-query(a[i]);
    }
    return ret;
}
int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &n); blo = sqrt(n);
    F(i, 0, n) a[i]=mp[i]=read(), bl[i]=i/blo;
    sort(mp, mp+n);
    nn = unique(mp, mp+n)-mp;
    F(i, 0, n) a[i] = lower_bound(mp, mp+nn, a[i])-mp+1;
    num = bl[n-1]+1;
    F(i, 0, num) init(i);
    int lastans=0;
    scanf("%d", &m);
    F(i, 0, m) {
        int l=read(),r=read();
        l^=lastans, r^=lastans;
        --l, --r; if (l>r) swap(l, r);
        if (l<0||r>=n) continue;
        printf("%d\n", lastans=ask(l,r));
    }
    return 0;
}
