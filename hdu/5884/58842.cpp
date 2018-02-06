#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi (4*atan(1.0))
const int N=1e5+10,M=1e6+10,inf=1e9+10,mod=1e9+7;
const ll INF=1e18+10;
ll n,m;
ll a[N];
int check(int x)
{
    queue<ll>q;
    queue<ll>d;
    int yy=(n-1)%(x-1);
    if(yy!=0)
    {
        for(int i=0;i<x-1-yy;i++)
        q.push(0);
    }
    for(ll i=1;i<=n;i++)
    q.push(a[i]);
    ll ans=0;
    while(!q.empty()||!d.empty())
    {
        ll sum=0;
        for(int i=0;i<x;i++)
        {
            if(q.empty()&&d.empty())
                break;
            if(q.empty())
            {
                sum+=d.front();
                d.pop();
            }
            else if(d.empty())
            {
                sum+=q.front();
                q.pop();
            }
            else
            {
                int u=q.front();
                int v=d.front();
                if(u<v)
                {
                    sum+=u;
                    q.pop();
                }
                else
                {
                    sum+=v;
                    d.pop();
                }
            }
        }
        ans+=sum;
        if(q.empty()&&d.empty())
        break;
        d.push(sum);
    }
    if(ans>m)
        return 0;
    return 1;
}
int main()
{
    freopen("5884.in", "r", stdin);
    freopen("58842.out", "w", stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld",&n,&m);
        for(ll i=1;i<=n;i++)
        scanf("%lld",&a[i]);
        sort(a+1,a+n+1);
        int st=2,en=n;
        while(st<en)
        {
            int mid=(st+en)/2;
            if(check(mid))
            en=mid;
            else
            st=mid+1;
        }
        printf("%d\n",st);
    }
    return 0;
}
