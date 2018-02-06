//1506.cpp

#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
stack<long long> l,r;
#define maxn 100010
long long le[maxn],ri[maxn],a[maxn];
int main()
{
//	freopen("1506.in","r",stdin);
//	freopen("15062.out","w",stdout);
	long long n,i,ans,x;
	while (cin >> n && n)
	{
		while (!l.empty())
			l.pop();
		while (!r.empty())
			r.pop();
		for (i=0;i<n;++i)
			cin >> a[i];
		l.push(0);
		le[0] = 0;
		r.push(n-1);
		ri[n-1] = n-1;
		for (i=1;i<n;++i)
		{
			if (a[l.top()] >= a[i])
			{
				while (!l.empty() && a[l.top()] >= a[i])
				{
					x = l.top();
					l.pop();
				}
				le[i] = le[x];
			}
			else
				le[i] = i;
			l.push(i);
		}
//		for (i=0;i<n;++i)
//			cout << le[i] << " ";
//		cout << endl;
		for (i=n-2;i>=0;--i)
		{
			if (a[r.top()] >= a[i])	
			{
				while (!r.empty() && a[r.top()] >= a[i])
				{
					x = r.top();
					r.pop();
				}
				ri[i] = ri[x];
			}
			else
				ri[i] = i;
			r.push(i);
		}
//		for (i=0;i<n;++i)
//			cout << ri[i] << " ";
		ans = 0;
		for (i=0;i<n;++i)
			ans = max(ans,(ri[i]-le[i]+1)*a[i]);
		cout << ans << endl;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
