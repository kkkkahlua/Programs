//455.cpp

#include <iostream>
#define maxn 100010
typedef long long LL;
int a[maxn];
LL sum[maxn],dp[maxn][2];
using namespace std;
int main() {
//	freopen("455.in","r",stdin);
//	freopen("455.out","w",stdout);
	int n,i,maxx = 0,minn = maxn;
	cin >> n;
	for (i=0;i<n;++i) {
		cin >> a[i];
		sum[a[i]] += a[i];
		maxx = max(maxx,a[i]);
		minn = min(minn,a[i]);
	}
	dp[minn][0] = 0;
	dp[minn][1] = sum[minn];
	for (i=minn+1;i<=maxx;++i) {
		dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
		dp[i][1] = dp[i-1][0] + sum[i];
	}
	cout << max(dp[maxx][1],dp[maxx][0]) << endl;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
