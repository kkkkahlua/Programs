//1421.cpp
 
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstdio> 
using namespace std;
#define maxn 2010
int a[maxn],dp[maxn][maxn/2];
int main()
{
	freopen("1421.in","r",stdin);
	freopen("1421.out","w",stdout);
    int n,k,i,j,ans;
    while (cin >> n >> k)
    {
    for (i=1;i<=n;++i)
        cin >> a[i];
    sort(a+1,a+n+1);
    for (j=1;j<=k;++j)
        for (i=2*j;i<=n;++i)
        {
            dp[i][j] = dp[i-2][j-1]+(a[i]-a[i-1])*(a[i]-a[i-1]);
            if (i-1>=2*j)
                dp[i][j] = min(dp[i][j],dp[i-1][j]);
        }
/*    for (i=1;i<=n;++i)
    {
    	for (j=1;j<=k;++j)
    		cout << dp[i][j] << " ";
    	cout <<endl;
    }*/
    ans = INT_MAX;
    for (i=2*k;i<=n;++i)        
        ans = min(ans,dp[i][k]);
    cout << ans << endl;
}
	fclose(stdin);
	fclose(stdout);
    return 0;
}
