//1004.cpp

#include <iostream> 
#include <string>
#define maxl 16
#define maxn 1000
using namespace std;
struct color
{
	string c;
	int tot;
}a[maxn];
int main()
{
	int n,tot,i,j,k,max;
	string s;
	while (cin>>n && n!=0)
	{
		tot = 0;
		for (k=0;k<n;++k)
		{
			cin >> s;
			for (i=0;i<tot;++i)
				if (s==a[i].c)
				{
					++a[i].tot;
					break;
				}
			if (i==tot)
			{
				a[tot].c = s;
				a[tot++].tot = 1;				
			}
		}
		max = 0;
		for (i=0;i<tot;++i)
			if (a[i].tot>max)
			{
				k = i;
				max = a[i].tot;
			}
		cout << a[k].c << endl;
	}
}
