//1789.cpp

#include <iostream>
#include <algorithm>
#include <cstring>
struct courses
{
	int ddl,value;
};
#define maxn 1010
courses a[maxn];
bool exist[maxn];
int arr[maxn];
using namespace std;
bool cmp(courses a,courses b);
int main()
{
	int T,n,i,p,sum,tot,maxx;
	cin >> T;
	while (T--)
	{
		cin >> n;
		maxx = 0;
		memset(exist,0,sizeof(exist));
		memset(arr,0,sizeof(arr));
		for (i=0;i<n;++i)
		{
			cin >> a[i].ddl;
			maxx = max(maxx,a[i].ddl);
		}
		tot = 0;
		for (i=0;i<n;++i)
		{
			cin >> a[i].value;
			tot += a[i].value;
		}
		sort(a,a+n,cmp);
		for (i=0;i<n;++i)
		{
			p = a[i].ddl;
			while (p>=0 && exist[p])
				--p;
			if (p<0)
				continue;
			exist[p] = true;
			arr[p] = a[i].value;
		}
		sum = 0;
		for (i=1;i<=maxx;++i)
			sum += arr[i];
		cout << tot-sum << endl;
	}
	return 0;
}
bool cmp(courses a,courses b)
{
	if (a.value>b.value)
		return true;
	if (a.value==b.value && a.ddl>b.ddl)
		return true;
	return false;
}
