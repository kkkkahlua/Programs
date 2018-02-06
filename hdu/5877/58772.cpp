
/*Sherlock and Watson and Adler*/
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<bitset>
#include<cmath>
#include<complex>
#include<string>
#include<algorithm>
#include<iostream>
#define eps 1e-9
#define LL long long
#define PI acos(-1.0)
#define bitnum(a) __builtin_popcount(a)
using namespace std;
const int N = 100005;
const int M = 20005;
const __int64 inf = 1e18+1;
const int mod = 1000000007;
struct edge
{
    int v,to;
}e[N];
int p,q,h[N],a[N],c[2*N];
bool vis[N];
__int64 k,s[2*N],ans;
void add_edge(int u,int v)
{
    e[p].v=v;
    e[p].to=h[u];
    h[u]=p++;
}
int lowbit(int t)
{//计算c[t]展开的项数
    return t&(-t);
}
void update(int i,int x)
{
    while(i<=q)
    {
        c[i]=c[i]+x;
        i+=lowbit(i);
    }
}
int Sum(int n) //求前n项的和.
{
    int sum=0;
    while(n>0)
    {
         sum+=c[n];
         n-=lowbit(n);
    }
    return sum;
}
void dfs(int x)
{
    int i;
    ans+=Sum(lower_bound(s,s+q,a[x]?k/a[x]:inf)-s+1);
    update(lower_bound(s,s+q,a[x])-s+1,1);
    for(i=h[x];i+1;i=e[i].to)
        dfs(e[i].v);
    update(lower_bound(s,s+q,a[x])-s+1,-1);
}
int main()
{
    freopen("5877.in", "r", stdin);
    freopen("58772.out", "w", stdout);
    int t,n,i,u,v;
    scanf("%d",&t);
    while(t--)
    {
        p=q=0;
        ans=0;
        memset(h,-1,sizeof(h));
        memset(c,0,sizeof(c));
        memset(vis,false,sizeof(vis));
        scanf("%d%I64d",&n,&k);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            s[q++]=a[i];
            if(!a[i])
                s[q++]=inf;
            else
                s[q++]=k/a[i];
        }
        sort(s,s+q);
        q=unique(s,s+q)-s;
        for(i=1;i<n;i++)
        {
            scanf("%d%d",&u,&v);
            vis[v]=true;
            add_edge(u,v);
        }
        for(i=1;i<=n;i++)
            if(!vis[i])
                dfs(i);
        printf("%I64d\n",ans);
    }
    return 0;
}
