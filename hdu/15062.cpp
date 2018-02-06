//1506.cpp

#include <iostream> 
#include <cstdio>
#define maxn 100010
__int64 a[maxn],l[maxn],r[maxn];
using namespace std;
int main()
{
	__int64 n,i,j,k,ans;
	while (scanf("%I64d",&n) && n)
	{
		for (i=0;i<n;++i)
			scanf("%I64d",&a[i]);
		for (i=0;i<n;++i)
		{
			j = i;
			while (j-1>=0 && a[j-1]>=a[i])
				-- j;
			l[i] = j;
		}
		for (i=0;i<n;++i)
		{
			j = i;
			while (j+1<=n-1 && a[j+1]>=a[i])
				++ j;
			r[i] = j;
		}
		ans = 0;
		for (i=0;i<n;++i)
			ans = max(ans,(r[i]-l[i]+1)*a[i]);
		printf("%I64d\n",ans);
	}
	return 0;	
}
