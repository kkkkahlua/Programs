//1087.cpp

#include <iostream>
#include <cmath>
#define maxn 1000
using namespace std;
int main()
{
	int n,i,j,maxx;
	int a[maxn],sum[maxn];
	while (cin >> n && n!=0)
	{
		cin >> a[0];
		sum[0] = a[0];
		for (i=1;i<n;++i)
		{
			cin >> a[i];
			maxx = 0;
			for (j=0;j<i;++j)
				if (a[j]<a[i])
					maxx = max(sum[j],maxx);
			sum[i] = maxx+a[i];
		}
		maxx = 0;
		for (i=0;i<n;++i)
			maxx = max(maxx,sum[i]);
		cout << maxx << endl;
	}
	return 0;
}
