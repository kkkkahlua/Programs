//1009.cpp

#include <iostream>
#include <algorithm>
#include <cstdio>
#define maxn 1010
using namespace std;
struct node{
	double f,j,worth;
}a[maxn];
bool cmp(node a,node b);
int main()
{
	int m,n,i,x,y,tot = 0;
	double ans;
	while (scanf("%d%d",&m,&n) && !(m==-1 && n==-1))
	{
		ans = tot = 0;
		for (i=0;i<n;++i)
		{
			scanf("%d%d",&x,&y);
			if (y == 0)
			{
				ans += x;
				continue;
			}
			a[tot].j = x; a[tot].f = y;
			a[tot].worth = (double)a[tot].j/a[tot].f;
			++ tot;
		}
		sort(a,a+tot,cmp);
		for (i=0;i<tot;++i)
			if (m-a[i].f >= 0)
			{
				m -= a[i].f;
				ans += a[i].j;
			}
			else
			{
				ans += (double)m*a[i].worth;
				break;
			}
		printf("%.3lf\n",ans);
	}
	return 0;
}
bool cmp(node a,node b)
{
	return a.worth > b.worth;
}
