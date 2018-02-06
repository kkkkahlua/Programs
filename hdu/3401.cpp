//3401.cpp

#include <iostream>
#define maxn 2020
int ap[maxn],bp[maxn],as[maxn],bs[maxn],dp[maxn][maxn];
using namespace std;
struct node
{
	int n,pos;
};
node q[maxn];
int main()
{
	int t,T,maxp,w,i,j,nowf,front,rear,ans;
	cin >> t;
	while (t--)
	{
		cin >> T >> maxp >> w;
		for (i=0;i<T;++i)
			cin >> ap[i] >> bp[i] >> as[i] >> bs[i];
		for (i=0;i<=T;++i)
			for (j=0;j<=maxp;++j)
				dp[i][j] = -0x3f3f3f3f;
		for (i=1;i<=T;++i)
			for (j=0;j<=min(maxp,as[i]);++j)
				dp[i][j] = -ap[i]*j;
		dp[0][0] = 0;
		for (i=1;i<=T;++i)
		{
			for (j=0;j<=maxp;++j)
				dp[i][j] = max(dp[i][j],dp[i-1][j]);
			if (i-w-1<0)
				continue;
			front = rear = 0;
			for (j=maxp;j>=0;--j)
			{
				nowf = dp[i-w-1][j]+j*bp[i];
				while (rear>front && nowf>q[rear-1].n)
					-- rear;
				while (front<rear && q[front].pos-j>bs[i])
					++ front;
				q[rear].n = nowf;
				q[rear++].pos = j;
				dp[i][j] = max(dp[i][j],q[front].n-j*bp[i]);
			}
			front = rear = 0;
			for (j=0;j<=maxp;++j)
			{
				nowf = dp[i-w-1][j]+j*ap[i];
				while (rear>front && nowf>q[rear-1].n)
					-- rear;
				while (front<rear && j-q[front].pos>as[i])
					++ front;
				q[rear].n = nowf;
				q[rear++].pos = j;
				dp[i][j] = max(dp[i][j],q[front].n-j*ap[i]);
			}
		}
		ans = 0;
		for (i=0;i<=maxp;++i)
			ans = max(ans,dp[T][i]);
		cout << ans << endl;
	}
	return 0;	
}
