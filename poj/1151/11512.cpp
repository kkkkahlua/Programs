#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const int N=205;
#define lson x<<1,l,mid
#define rson x<<1|1,mid+1,r
#define lc x<<1
#define rc x<<1|1
inline int read(){
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int n;
double x1,y1,x2,y2;
struct Seg{
    double l,r,y;
    int f;
    Seg(double l=0,double r=0,double y=0,int f=0):l(l),r(r),y(y),f(f){}
    bool operator <(const Seg &a)const{return y<a.y;}
}a[N];
double mp[N];int m;
void iniMP(){
    sort(mp+1,mp+1+m);
    int p=0;
    mp[++p]=mp[1];
    for(int i=2;i<=m;i++) if(mp[i]!=mp[i-1]) mp[++p]=mp[i];
    m=p;
}
inline int Bin(double v){
    int l=1,r=m;
    while(l<=r){
        int mid=(l+r)>>1;
        if(v==mp[mid]) return mid;
        else if(v<mp[mid]) r=mid-1;
        else l=mid+1;
    }
    return 0;
}
struct node{
    double sum;
    int cov;
    node():sum(0),cov(0){}
}t[N<<2];
void pushUp(int x,int l,int r){
    if(t[x].cov) t[x].sum=mp[r+1]-mp[l];
    else if(l==r) t[x].sum=0;
    else t[x].sum=t[lc].sum+t[rc].sum;
}
void segCov(int x,int l,int r,int ql,int qr,int v){
    if(ql<=l&&r<=qr) t[x].cov+=v,pushUp(x,l,r);
    else{
        int mid=(l+r)>>1;
        if(ql<=mid) segCov(lson,ql,qr,v);
        if(mid<qr) segCov(rson,ql,qr,v);
        pushUp(x,l,r);
    }
}

int cas=0;
int main(int argc, const char * argv[]) {
    freopen("1151.in", "r", stdin);
    freopen("11512.out", "w", stdout);
    while((n=read())){
        m=0;
        for(int i=1;i<=n;i++){
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            a[i*2-1]=Seg(x1,x2,y1,1);
            a[i*2]=Seg(x1,x2,y2,-1);
            mp[++m]=x1;mp[++m]=x2;
        }
        iniMP();
        n<<=1;
        sort(a+1,a+1+n);
        memset(t,0,sizeof(t));
        double ans=0;
        for(int i=1;i<=n-1;i++){
            int ql=Bin(a[i].l),qr=Bin(a[i].r)-1;
            if(ql<=qr) segCov(1,1,m,ql,qr,a[i].f);
            ans+=t[1].sum*(a[i+1].y-a[i].y);
        }
        printf("Test case #%d\n",++cas);
        printf("Total explored area: %.2f\n\n",ans);
    }

    return 0;
}
