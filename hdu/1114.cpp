//1114.cpp

#include <iostream>
using namespace std;
#define maxw 10010
#define maxn 510
#include <cstring>
int dp[maxw],v[maxn],w[maxn];
int main()
{
	int T,n,e,f,i,wmax,j,ans;
	cin >> T;
	while (T--)
	{
		cin >> e >> f;
		wmax = f-e;
		cin >> n;
		for (i=0;i<n;++i)
			cin >> v[i] >> w[i];
		memset(dp,0,sizeof(dp));
		for (i=0;i<n;++i)
			for (j=w[i];j<=wmax;++j)
				if (dp[j-w[i]] || j-w[i]==0)
					if (dp[j]==0)
						dp[j] = dp[j-w[i]]+v[i];
					else
						dp[j] = min(dp[j],dp[j-w[i]]+v[i]);
		ans = dp[wmax];
		if (ans)
			cout << "The minimum amount of money in the piggy-bank is " << ans << '.' << endl;
		else
			cout << "This is impossible.\n";
	}
	return 0;
}
