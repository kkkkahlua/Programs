//2870.cpp

#include <iostream>
using namespace std;
#define maxn 1010
#include <cstring>
struct tri
{
	short a,b,c;
};
tri h[maxn][maxn],l[maxn][maxn],r[maxn][maxn];
char c[maxn][maxn];
int main()
{
//	freopen("2870.in","r",stdin);
//	freopen("2870.out","w",stdout);
	int m,n,i,j,k,ans;
	while (cin >> m >> n)
	{
	memset(h,0,sizeof(h));
	for (i=1;i<=m;++i)
		for (j=1;j<=n;++j)
		{
			cin >> c[i][j];
			if (c[i][j] == 'a' || c[i][j] == 'w' || c[i][j] == 'y' || c[i][j] == 'z')
				h[i][j].a = h[i-1][j].a + 1;
			if (c[i][j] == 'b' || c[i][j] == 'w' || c[i][j] == 'x' || c[i][j] == 'z')
				h[i][j].b = h[i-1][j].b + 1;
			if (c[i][j] == 'c' || c[i][j] == 'x' || c[i][j] == 'y' || c[i][j] == 'z')
				h[i][j].c = h[i-1][j].c + 1;
		}
	for (i=1;i<=m;++i)
		for (j=1;j<=n;++j)
		{
			if (h[i][j].a)
			{
				k = j;
				while (h[i][k-1].a >= h[i][j].a && (c[i][k-1] == 'a' || c[i][k-1] == 'w' || c[i][k-1] == 'y' || c[i][k-1] == 'z'))
					-- k;
				l[i][j].a = k;
			}
			if (h[i][j].b)
			{
				k = j;
				while (h[i][k-1].b >= h[i][j].b && (c[i][k-1] == 'b' || c[i][k-1] == 'w' || c[i][k-1] == 'x' || c[i][k-1] == 'z'))
					-- k;
				l[i][j].b = k;
			}
			if (h[i][j].c)
			{
				k = j;
				while (h[i][k-1].c >= h[i][j].c && (c[i][k-1] == 'c' || c[i][k-1] == 'x' || c[i][k-1] == 'y' || c[i][k-1] == 'z'))
					-- k;
				l[i][j].c = k;
			}
		}
	for (i=1;i<=m;++i)
		for (j=1;j<=n;++j)
		{
			if (h[i][j].a)
			{
				k = j;
				while (h[i][k+1].a >= h[i][j].a && (c[i][k+1] == 'a' || c[i][k+1] == 'w' || c[i][k+1] == 'y' || c[i][k+1] == 'z'))
					++ k;
				r[i][j].a = k;
			}
			if (h[i][j].b)
			{
				k = j;
				while (h[i][k+1].b >= h[i][j].b && (c[i][k+1] == 'b' || c[i][k+1] == 'w' || c[i][k+1] == 'x' || c[i][k+1] == 'z'))
					++ k;
				r[i][j].b = k;
			}
			if (h[i][j].c)
			{
				k = j;
				while (h[i][k+1].c >= h[i][j].c && (c[i][k+1] == 'c' || c[i][k+1] == 'x' || c[i][k+1] == 'y' || c[i][k+1] == 'z'))
					++ k;
				r[i][j].c = k;
			}
		}
	ans = 0;

	for (i=1;i<=m;++i)
		for (j=1;j<=n;++j)
		{
			if (l[i][j].a)
				ans = max(ans,(r[i][j].a-l[i][j].a+1) * h[i][j].a);
			if (l[i][j].b)
				ans = max(ans,(r[i][j].b-l[i][j].b+1) * h[i][j].b);
			if (l[i][j].c)
				ans = max(ans,(r[i][j].c-l[i][j].c+1) * h[i][j].c);
		}
	cout << ans << endl;
}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
