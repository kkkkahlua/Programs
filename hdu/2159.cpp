//2159.cpp

#include <iostream> 
using namespace std;
#define maxn 110
#include <climits>
#include <cstring>
int lp[maxn],exp[maxn],dp[maxn*20][maxn*20];
int main()
{
	int n,m,k,s,i,j,kk,minn;
	bool flag;
	while (cin >> n >> m >> k >> s)
	{
		flag = false;
		memset(dp,0,sizeof(dp));
		for (i=0;i<k;++i)
		{
			cin >> exp[i] >> lp[i];
			if (exp[i]>n)
				dp[n][lp[i]] = 1;
		}
		for (i=1;i<=n;++i)
			for (j=1;j<=m;++j)
			{
				minn = INT_MAX;
				for (kk=0;kk<k;++kk)
					if ((i-exp[kk]>0 && j-lp[kk]>0 && dp[i-exp[kk]][j-exp[kk]]) || (i-lp[kk]==0 && j-lp[kk]==0))
						minn = min(minn,dp[i-exp[kk]][j-lp[kk]]+1);
				if (minn<=s)
					dp[i][j] = minn;
			}
/*		for (i=1;i<=n;++i)
		{
			for (j=1;j<=m;++j)	
				cout << dp[i][j] << " ";
			cout << endl;
		}*/
		for (i=1;i<=m;++i)
				if (dp[n][i])
				{
					cout << m-i << endl;
					flag = true;
					break;
				}
		if (!flag)
			cout << "-1" << endl;
	}
	return 0;
}
