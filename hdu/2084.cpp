//2084.cpp

#include <cstdio>
#include <iostream>
#define maxn 110
#include <cmath>
#include <cstring>
using namespace std;
int a[maxn][maxn],dp[maxn][maxn];
int main()
{
	int T,i,j,ans,n;
	scanf("%d",&T);
	while (T--)
	{
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		scanf("%d",&n);
		for (i=1;i<=n;++i)
			for (j=1;j<=i;++j)
				scanf("%d",&a[i][j]);
		dp[1][1] = a[1][1];
		for (i=2;i<=n;++i)
		{
			dp[i][1] = dp[i-1][1]+a[i][1];
			dp[i][i] = dp[i-1][i-1]+a[i][i];
			for (j=2;j<i;++j)
				dp[i][j] = max(dp[i-1][j-1],dp[i-1][j])+a[i][j];
		}
		ans = dp[n][1];
		for (i=2;i<=n;++i)
			ans = max(ans,dp[n][i]);
/*		for (i=1;i<=n;++i)
		{
			for (j=1;j<=n;++j)
				printf("%d ",dp[i][j]);
			printf("\n");
		}*/
		printf("%d\n",ans);
	}
	return 0;
}
