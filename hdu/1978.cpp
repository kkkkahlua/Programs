//1978.cpp

#include <iostream>
int f(int x);
#define maxn 200
#include <cstring>
int map[maxn][maxn],dp[maxn][maxn];
using namespace std;
int main()
{
	int T,n,m,i,j,k,kk;
	cin >> T;
	while (T--)
	{
		memset(dp,0,sizeof(dp));
		cin >> n >> m;
		for (i=0;i<n;++i)
			for (j=0;j<m;++j)
				cin >> map[i][j];
		dp[0][0] = 1;
		for (i=0;i<n;++i)
			for (j=0;j<m;++j)
				for (k=0;k<=map[i][j] && i+k<n;++k)
					for (kk=0;kk<=map[i][j]-k && j+kk<m;++kk)
						if (k+kk)
							dp[i+k][j+kk] = (dp[i+k][j+kk] + dp[i][j]) % 10000;
		cout << dp[n-1][m-1] << endl;
	}
	return 0;
}
