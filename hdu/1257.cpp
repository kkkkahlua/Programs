//1257.cpp

#include <cstdio>
#include <climits>
#define maxn 100010
int a[maxn],ans[maxn];
int main()
{
	int n,i,tot,j,p,min;
	bool flag;
	while (scanf("%d",&n)!=EOF)
	{
		for (i=0;i<n;++i)
			scanf("%d",&a[i]);
		ans[0] = a[0];
		tot = 1;
		for (i=1;i<n;++i)
		{
			flag = false;
			min = INT_MAX;
			for (j=0;j<tot;++j)
				if (ans[j]>a[i] && ans[j]<min)
				{
					p = j;
					min = ans[j];
					flag = true;
				}
			if (!flag)
				ans[tot++] = a[i];
			else
				ans[p] = a[i];
		}
		printf("%d\n",tot);
	}
	return 0;
}
