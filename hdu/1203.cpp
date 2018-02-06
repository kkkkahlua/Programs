//1203.cpp

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
using namespace std;
#define maxn 10010
double sum[maxn],prob[maxn];
int price[maxn];
int main()
{
	freopen("data.txt","r",stdin);
	freopen("1203.out","w",stdout);
	int n,m,i,j;
	double x,ans;
	while (cin >> n >> m && n+m)
	{
		sum[0] = 1;
		for (i=0;i<m;++i)
		{
			cin >> price[i] >> x;
			prob[i] = 1-x;
		}
		for (i=0;i<=n;++i)
			sum[i] = 1;
		ans = 1;
		for (i=0;i<m;++i)
			for (j=n;j>=0;--j)
			{
				if (j-price[i]>=0)
					sum[j] = min(sum[j],sum[j-price[i]]*prob[i]);
				ans = min(ans,sum[j]);
			}
		ans = 1-ans;
		ans *= 100;
		cout << fixed << setprecision(1) << ans << "%\n";
	}
	fclose(stdin);
    fclose(stdout);
	return 0;
}
