//21592.cpp

#include <iostream>
#include <cstdio>
using namespace std;
#define maxn 110
#include <cstring>
int exp[maxn],lp[maxn],dp[maxn][maxn];
int main()
{
//	freopen("data.txt","r",stdin);
//	freopen("21592.out","w",stdout);
	int n,m,s,k,i,j,kk,ans;
	bool flag;
	while (cin >> n >> m >> k >> s)
	{
		for (i=0;i<k;++i)
			cin >> exp[i] >> lp[i];
		memset(dp,0,sizeof(dp));
		for (i = 1; i <= s; ++ i)
			for (j = 1; j<=m;++j)
				for (kk=0;kk<k;++kk)
				{
					if (j-lp[kk]>=0)
					dp[i][j] = max(dp[i][j],dp[i-1][j-lp[kk]]+exp[kk]);
				}
		flag = false;
		ans = 0;
		for (i=1;i<=s;++i)
		{
			for (j=1;j<=m;++j)
			{
				if (dp[i][j]>=n)
				{
					flag = true;
					ans = max(m-j,ans);
					break;
				}
			}
		}
		if (flag)
			cout << ans << endl;
		else
			cout << "-1" << endl;
	}
//	fclose(stdin);
//	fclose(stdout);
}
