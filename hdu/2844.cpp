//2844.cpp

#include <iostream>
int power[10] = {1,2,4,8,16,32,64,128,256,512};
using namespace std;
#define maxm 100010
#define maxn 110
#include <cstring>
bool dp[maxm];
int a[maxn],c[maxn],b[maxn*10];
void pro(int a[],int c[],int x,int &tot);
int main()
{
	int n,n0,m,i,j,ans,tot;
	while (cin >> n >> m && n+m)
	{
		for (i=0;i<n;++i)
			cin >> a[i];
		for (i=0;i<n;++i)
			cin >> c[i];
		tot = 0;
		for (i=0;i<n;++i)
			pro(b,c,i,tot);
/*		for (i=0;i<tot;++i)
			cout << b[i] << " ";
		cout << endl;*/
		memset(dp,0,sizeof(dp));
		dp[0] = true;
		for (i=0;i<tot;++i)
			for (j=m;j>=b[i];--j)
				if (dp[j-b[i]])
					dp[j] = true;
		ans = 0;
		for (i=1;i<=m;++i)
			if (dp[i])
				++ans;
		cout << ans << endl;
	}
	return 0;
}
void pro(int b[],int c[],int x,int &tot)
{
	int t = 0;
	while (t<=10 && power[t]<=c[x])
	{
		b[tot++] = a[x]*power[t];
		c[x] -= power[t++];
	}
	if (c[x])
		b[tot++] = a[x]*c[x];
}
