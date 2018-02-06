#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
using namespace std;
int num,d[66],f[2066],jc[2066];
int T,n,a,p,k,ci[30];
int l,r,mid,ans,now;
const int inf=1000000000;

inline void dvd(){
    num=0,n=sqrt(p+0.5);
    for(int i=2;i<=n;i++) if(!(p%i)){
        d[++num]=i;
        while(!(p%i)) p/=i;
        if(p==1) break;
    }

    if(p!=1) d[++num]=p;

    for(int S=0;S<ci[num];S++){
        jc[S]=1;
        for(int j=0;j<num;j++) if(ci[j]&S) jc[S]*=d[j+1];
    }
}

//<=x的数中有多少与p互质
inline int get(int x){
    int an=0;
    for(int s=0;s<ci[num];s++) an+=f[s]*(x/jc[s]);
    return an;
}

int main(){
    freopen("in.txt", "r", stdin);
    ci[0]=1;
    for(int i=1;i<=20;i++) ci[i]=ci[i-1]<<1;
    f[0]=1;
    for(int i=1;i<=2055;i++) f[i]=-f[i^(i&-i)];

    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&a,&p,&k);
        dvd();
        l=a+1,r=inf,now=get(a);
        while(l<=r){
            mid=l+r>>1;
            if(get(mid)-now<k) l=mid+1;
            else ans=mid,r=mid-1;
        }

        printf("%d\n",ans);
    }

    return 0;
}
