//O(n)
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <cassert>
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef long long ll;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 4e5 + 10;
const int M = 2e5;
int n,cas;
vector<int> v[N], u[N];
int col[N];
int in[N], out[N];
LL ans[N];
int pre[N];
list<int> l[N];
int dfn = 1;
template<typename T> inline void readint(T &x) {
    x = 0; T f = 1; char ch = getchar();
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    while (isdigit(ch)) { x = x * 10 + ch - '0'; ch = getchar(); }
    x *= f;
}
void dfs(int x, int fa = -1)
{
    int cx = col[x];
    if (l[cx].empty()) u[M + cx].push_back(x);
    else u[l[cx].back()].push_back(x);
    pre[x] = fa;
    l[cx].push_back(x);
    in[x] = dfn++;
    for (int j = 0; j < v[x].size(); j++)
    {
        int &y = v[x][j];
        if (y == fa) continue;
        dfs(y, x);
    }
    l[cx].pop_back();
    out[x] = dfn;
}
inline bool isson(int x, int y)
{
    return in[y] <= in[x] && in[x] < out[y];
}
inline int treesize(int x)
{
    return out[x] - in[x];
}
void getans(int x, int o = 0)
{
    int p = 0;
    if (x <= M)
    {
        ans[in[x]] += n - o;
        ans[in[x] + 1] -= n - o;
    }
    for (int i = 0; i < v[x].size(); i++)
    {
        int &y = v[x][i];
        if (y == pre[x]) continue;
        int nx = p;
        int sz = treesize(y);
        while (nx < u[x].size() && isson(u[x][nx], y))
        {
            sz -= treesize(u[x][nx]);
            nx++;
        }
        ans[in[y]] += n - sz - o;
        ans[out[y]] -= n - sz - o;
        for (int i = p; i < nx; i++)
        {
            getans(u[x][i], n - sz);
        }
        p = nx;
    }
}
int main()
{
    while(scanf("%d",&n)==1){
        for (int i = 1; i <= n; i++) readint(col[i]);
        MEM(ans, 0);
        for(int i=0;i<N;i++)v[i].clear(),u[i].clear(),l[i].clear();
        dfn=1;
        for (int i = 1; i < n; i++)
        {
            int x, y;
            readint(x);
            readint(y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        dfs(1);
        for (int i = 1; i <= M; i++)
        {
            v[i + M].push_back(1);
            getans(i + M);
        }
        for (int i = 1; i <= n; i++) ans[i] += ans[i - 1];
        ll Ans=0;
        for(int i=1;i<=n;i++)Ans+=ans[in[i]];
        printf("Case #%d: %I64d\n",++cas,(Ans-n)/2);
    }
    return 0;
}





//(Acceptable) O(nlogn)
#include<bits/stdc++.h>
const int N=200010;
using namespace std;
typedef long long ll;
struct Edge{int u,v,next;}G[N<<1];
int tot=0,head[N],a[N],d[N],lpos[N],rpos[N],cnt=0,q[N],fa[N],n;
int c[N*5];
ll w[N],ans;
inline int lowbit(int x){return x&(-x);}
inline void addedge(int u,int v){
	G[++tot].u=u;G[tot].v=v;G[tot].next=head[u];head[u]=tot;
	G[++tot].u=v;G[tot].v=u;G[tot].next=head[v];head[v]=tot;
}
bool cmp(int x,int y){
	if(a[x]==a[y])return d[x]>d[y];
	return a[x]<a[y];
}
inline void add(int x,int val){
	if(!x)return;
	for(int i=lpos[x];i<=n;i+=lowbit(i))c[i]+=val;
}
inline int ask(int x){
	int ans=0;
	for(int i=x;i;i-=lowbit(i))ans+=c[i];
	return ans;
}
void dfs(int u,int f){
	lpos[u]=++cnt;
	for(int i=head[u];i;i=G[i].next){
		int v=G[i].v;if(v==f)continue;
		fa[v]=u;d[v]=d[u]+1;
		dfs(v,u);
	}
	rpos[u]=cnt;
}
inline int size(int x){return ask(rpos[x])-ask(lpos[x]-1);}
inline void solve(int l,int r,int val){
	ans+=w[n];
	for(int i=l;i<=r;i++){
		int u=q[i];
		for(int i=head[u];i;i=G[i].next){
			int v=G[i].v;if(v==fa[u]||a[v]==val)continue;
			ans-=w[size(v)];
		}
		add(fa[u],-size(u));
	}
	if(a[1]!=val)ans-=w[size(1)];
	for(int i=r;i>=l;i--){
		int u=q[i];
		add(fa[u],size(u));
	}
}
inline int read(){
	int f=1,x=0;char ch;
	do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
	do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
	return f*x;
}
int main(){
	int cas=0;
	for(int i=1;i<N;i++)w[i]=1LL*i*i;
	while(scanf("%d",&n)==1){
		for(int i=1;i<=n;i++)a[i]=read();
		ans=0;cnt=0;tot=0;memset(head,0,sizeof(head));
		for(int i=1;i<n;i++){
			int u=read(),v=read();
			addedge(u,v);
		}
		for(int i=1;i<=n;i++)q[i]=i,c[i]=0;
		dfs(1,0);
		sort(q+1,q+n+1,cmp);
		for(int i=1;i<=n;i++)add(i,1);
		int j=0;
		for(int i=1;i<=n;i=j){
			for(j=i;j<=n&&a[q[i]]==a[q[j]];j++);solve(i,j-1,a[q[i]]);
		}
		ans-=n;ans>>=1;
		printf("Case #%d: %I64d\n",++cas,ans);
	}
}
