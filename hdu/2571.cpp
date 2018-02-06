//2571.cpp

#include <iostream>
#define maxn 30
#define maxm 1010
#include <cstring>
#include <cmath>
int a[maxn][maxm],dp[maxn][maxm];
using namespace std;
int main()
{
	int T,n,m,i,j,k;
	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		memset(dp,0,sizeof(dp));
		for (i=1;i<=n;++i)
			for (j=1;j<=m;++j)
				cin >> a[i][j];
		dp[1][1] = a[1][1];
		for (i=2;i<=n;++i)
			dp[i][1] = dp[i-1][1] + a[i][1];
		for (i=1;i<=n;++i)
			for (j=2;j<=m;++j)
			{
				dp[i][j] = dp[i][j-1];
				for (k=1;k<=j-1;++k)
					if (j%k==0)
						dp[i][j] = max(dp[i][j],dp[i][k]);
				if (i>=2)
					dp[i][j] = max(dp[i][j],dp[i-1][j]);
				dp[i][j] += a[i][j];
			}
/*		for (i=1;i<=n;++i)
		{
			for (j=1;j<=m;++j)
				cout << dp[i][j] << " ";
			cout << endl;
		}*/
		cout << dp[n][m] << endl;
	}
	return 0;
}
