//1506.cpp

#include <iostream>
#include <stack>
#define maxn 100010
long long a[maxn];
using namespace std;
long long maxi(long long l,long long r);
int main()
{
	freopen("1506.in","r",stdin);
	freopen("1506.out","w",stdout);
	
	long long n,i;
	while (cin >> n && n)
	{
		for (i=0;i<n;++i)
			cin >> a[i];
		cout << maxi(0,n-1) << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
long long maxi(long long l,long long r)
{
	if (r-l==1)
		return max(max(a[r],a[l]),min(a[r],a[l])*2);
	if (r==l)
		return a[l];
//	cout << l << " " << r << endl;
	stack<long long> left,right;
	long long i,j,low,len,ans;
	long long mid = (l+r) >> 1;
	long long maxl = maxi(l,mid);
//	cout << l << " " << r << " " << maxl << endl;
	long long maxr = maxi(mid+1,r);
//	cout << l << " " << r << " " << maxr << endl;
	for (i=l;i<=mid;++i)
		left.push(a[i]);
	for (i=r;i>mid;--i)
		right.push(a[i]);
	low = INT_MAX;
	len = ans = 0;
	while (!left.empty() || !right.empty())
	{
		if (!left.empty() && left.top()>=low)
		{
			++ len;
			ans = max(ans,low*len);
			left.pop();
		}
		else if (!right.empty() && right.top()>=low)
		{
			++ len;
			ans = max(ans,low*len);
			right.pop();
		}
		else if (!left.empty() && !right.empty())
		{
			if (left.top() <= right.top())
			{
				++ len;
				low = right.top();
				ans = max(ans,low*len);
				right.pop();
			}
			else
			{
				++ len;
				low = left.top();
				ans = max(ans,low*len);
				left.pop();
			}
		}
		else if (!left.empty())
		{
			++ len;
			low = min(low,left.top());
			ans = max(ans,len*low);
			left.pop();
		}
		else if (!right.empty())
		{
			++ len;
			low = min(low,right.top());
			ans = max(ans,len*low);
			right.pop();
		}
	}
//	cout << l << " " << r << " " << max(max(maxl,maxr),ans) << endl;
	return max(max(maxl,maxr),ans);
}
