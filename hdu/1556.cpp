//1556.cpp

#include <iostream> 
#define maxn 1000010
#include <cstring>
using namespace std;
void init(int id,int l,int r);
void insert(int id,int l,int r);
void add(int id);
struct node
{
	int l,r,n;
}a[maxn];
int ans[maxn];
int main()
{
	freopen("1556.in","r",stdin);
	freopen("1556.out","w",stdout);

	int n,i,x,y;
	while (cin >> n && n)
	{
		memset(ans,0,sizeof(ans));
		init(1,1,n);
		for (i=0;i<n;++i)
		{
			scanf("%d%d",&x,&y);
			insert(1,x,y);
		}
		add(1);
		for (i=1;i<n;++i)
			printf("%d ",ans[i]);
		printf("%d\n",ans[n]);
	}
	
    fclose(stdin);
    fclose(stdout);
	return 0;
}
void init(int id,int l,int r)
{
	a[id].l = l;
	a[id].r = r;
	a[id].n = 0;
	if (l==r)
		return;
	int mid = (l+r)/2;
	init(id*2,l,mid);
	init(id*2+1,mid+1,r);
}
void insert(int id,int l,int r)
{
	if (l==a[id].l && r==a[id].r)
	{
		++ a[id].n;
		return;
	}
	int mid = (a[id].l+a[id].r)/2;
	if (r<=mid)
		insert(id*2,l,r);
	else if (l>mid)
		insert(id*2+1,l,r);
	else
	{
		insert(id*2,l,mid);
		insert(id*2+1,mid+1,r);
	}
	
}
void add(int id)
{
	int i;
	for (i=a[id].l;i<=a[id].r;++i)
		ans[i] += a[id].n;
	if (a[id].l==a[id].r)
		return;
	add(id*2);
	add(id*2+1);
}
