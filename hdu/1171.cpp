//1171.cpp

#include <cstdio>
#include <cstring>
#define maxn 60
#define maxx 300000
int v[maxn],m[maxn];
bool a[maxx];
int main()
{
	int n,sum,i,max,j,k;
	while (scanf("%d",&n)!=EOF && n>0)
	{
		sum = 0;
		for (i=0;i<n;++i)
		{
			scanf("%d %d",&v[i],&m[i]);
			sum += v[i]*m[i];
		}
		max = sum/2;
		memset(a,0,sizeof(a));
		a[0] = true;
		for (i=0;i<n;++i)		
			for (j=max;j>=0;--j)
				for (k=1;k<=m[i];++k)
					if (j-v[i]*k>=0 && a[j-v[i]*k])
					{
						a[j] = true;
						break;
					}
		i = max;
		while (!a[i])
			--i;
		printf("%d %d\n",sum-i,i);
	}
	return 0;
}
