//1231.cpp

#include <cstdio>
using namespace std;
#define maxn 10010
int sum[maxn],beg[maxn],a[maxn];
int main()
{
	int n,i,p;
	while (scanf("%d",&n)!=EOF && n)
	{
		for (i=0;i<n;++i)
			scanf("%d",&a[i]);
		sum[0] = a[0];
		beg[0] = 0;
		for (i=1;i<n;++i)
			if (sum[i-1]<0)
			{
				sum[i] = a[i];
				beg[i] = i;
			}
			else
			{
				sum[i] = sum[i-1]+a[i];
				beg[i] = beg[i-1];
			}
		p = n-1;
		for (i=n-2;i>=0;--i)
			if (sum[p]<=sum[i])
				p = i;
		if (sum[p]<0)
			printf("%d %d %d\n",0,a[0],a[n-1]);
		else
			printf("%d %d %d\n",sum[p],a[beg[p]],a[p]);
	}
	return 0;
}
