//1069.cpp

#include <iostream>
#include <cmath>
#define maxn 200
int a[maxn],b[maxn],c[maxn],sum[maxn];
using namespace std;
void sort(int a[],int b[],int c[],int n);
int main()
{
	int n,i,j,tot,maxx,ans,test=0;
	while (cin >> n && n!=0)
	{
		++ test;
		tot = n;
		for (i = 0; i < n; ++ i)
		{
			cin >> a[i] >> b[i] >> c[i];
			if (a[i]==b[i] && b[i]==c[i])
				continue;
			if (a[i] == b[i])
			{
				a[tot] = c[tot] = a[i]; b[tot] = c[i];
				b[tot] = c[tot] = a[i]; a[tot++] = c[i];
				continue;
			}
			if (b[i] == c[i])
			{
				a[tot] = b[tot] = b[i]; c[tot] = a[i];
				a[tot] = c[tot] = b[i]; b[tot++] = a[i];
				continue;
			}
			if (a[i] == c[i])
			{
				a[tot] = b[tot] = a[i]; c[tot] = b[i];
				b[tot] = c[tot] = a[i]; a[tot++] = b[i];
				continue;
			}
			a[tot] = a[i]; b[tot] = c[i]; c[tot++] = b[i];
			a[tot] = b[i]; b[tot] = a[i]; c[tot++] = c[i];
			a[tot] = b[i]; b[tot] = c[i]; c[tot++] = a[i];
			a[tot] = c[i]; b[tot] = a[i]; c[tot++] = b[i];
			a[tot] = c[i]; b[tot] = b[i]; c[tot++] = a[i];
		}
		sort(a,b,c,tot);
		sum[0] = c[0];
		ans = 0;
		for (i = 1; i < tot; ++ i)
		{
			maxx = 0;
			for (j = 0; j < i; ++ j)
				if (a[j] > a[i] && b[j] > b[i])
					maxx = max(maxx, sum[j]);
			sum[i] = maxx + c[i];
			ans = max(ans, sum[i]);
		}
		cout << "Case " << test << ": maximum height = " << ans << endl;
	}
	return 0;
}
void sort(int a[],int b[],int c[],int n)
{
	int i, j, temp;
	for (i = 0; i < n; ++ i)
		for (j = i+1; j < n; ++ j)
		{
			if (a[i] < a[j])
			{
				temp = a[i]; a[i] = a[j]; a[j] = temp;
				temp = b[i]; b[i] = b[j]; b[j] = temp;
				temp = c[i]; c[i] = c[j]; c[j] = temp;
			}
			if (a[i] == a[j] && b[i] < b[j])
			{
				temp = b[i]; b[i] = b[j]; b[j] = temp;
				temp = c[i]; c[i] = c[j]; c[j] = temp;
			}
		}
}
