#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long giant;
int read() {
    int x=0,f=1;
    char c=getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=-1;
    for (;isdigit(c);c=getchar()) x=x*10+c-'0';
    return x*f;
}
const int maxn=1e5+1;
const int maxj=17;
const int q=1e9+7;
int bin[maxn],n;
inline int Multi(int x,int y) {return (giant)x*y%q;}
inline int mi(int x,int y) {
    int ret=1;
    for (;y;y>>=1,x=Multi(x,x)) if (y&1) ret=Multi(ret,x);
    return ret;
}
struct SET {
    int f[maxn];
    void init(int n) {for (int i=1;i<=n;++i) f[i]=i;}
    int find(int x) {return f[x]==x?x:f[x]=find(f[x]);}
    int merge(int x,int y) {
        int fx=find(x),fy=find(y);
        if (fx!=fy) f[fx]=fy;
    }
} st[maxj];
int main() {
    freopen("in.txt","r",stdin);
    n=read();
    for (int i=2;i<=n;++i) bin[i]=bin[i>>1]+1;
    for (int i=bin[n];i>=0;--i) st[i].init(n);
    for (int m=read();m;--m) {
        int x=read(),y=read(),l=read(),r=read(),len=r-l+1,d=bin[len];
        st[d].merge(x,l);
        st[d].merge(y-(1<<d)+1,r-(1<<d)+1);
    }
    for (int j=bin[n];j;--j) {
        for (int i=1;i+(1<<j)-1<=n;++i) {
            int p=st[j].find(i);
            st[j-1].merge(i,p);
            st[j-1].merge(i+(1<<(j-1)),p+(1<<(j-1)));
        }
    }
    int cnt=0;
    for (int i=1;i<=n;++i) cnt+=(st[0].find(i)==i);
    int ans=Multi(9,mi(10,cnt-1));
    printf("%d\n",ans);
    return 0;
}
