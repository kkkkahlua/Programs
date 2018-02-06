//1338.cpp

#include <iostream>
#include <algorithm>
#include <cstring>
#define maxn 50
#define max 1001
bool cmp(int a,int b);
int compare(int a[],int b[],int n);
int main()
{
	using namespace std;
	int m,n,i,tot;
	bool exist[max];
	int pip[maxn],pip2[maxn];
	cin >> m >> n;
	int no=0;
	while (m!=0)
	{
		for (i=1;i<=n*m;++i)
			exist[i] = true;
		for (i=0;i<n;++i)
		{
			cin >> pip[i];
			exist[pip[i]] = false;
		}
		tot = 0;
		for (i=n*m;i>0;--i)
		{
			if (exist[i])
			{
				pip2[tot++]	= i;
			}
			if (tot==n)
				break;
		}
		sort(pip,pip+n,cmp);
		cout << "Case " << ++no << ": ";
		cout << compare(pip,pip2,n) << endl;
		cin >> m >> n;
	}
}
bool cmp(int a,int b)
{
	return a > b;
}
int compare(int a[],int b[],int n)
{
	bool flag[maxn];
	memset(flag,0,sizeof(flag));
	int p=0,i;
	for (i=0;i<n;++i)
	{
		if (b[p]<a[i])
			continue;
		p++;
		flag[i] = true;
	}
	int tot=0;
	for (i=0;i<n;++i)
		if (!flag[i])
			++tot;
	return tot;
}
