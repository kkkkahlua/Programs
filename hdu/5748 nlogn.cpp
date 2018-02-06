//bellovin.cpp

#include <iostream> 
int main()
{
	using namespace std;
	int T;
	for (tt=0;tt<T;++tt)
	{
		cin >> n;
		for (i=0;i<n;++i)
			cin >> a[i];
		c[0] = a[0];
		for (i=1;i<n;++i)
		{
			p = FindThePosition(c,a[i],i);
			w
		}
		
	}
}
int FindThePosition(int a[],int x,int tot)
{
	int left,right,mid;
	left = 0;
	right = tot-1;
	while (left<=right)
	{
		mid = (left+right)/2;
		if (x<a[mid])
			right = mid-1;
		else if (x>a[mid])
			left = mid+1;
		else return mid;
	}
	return left;
}
