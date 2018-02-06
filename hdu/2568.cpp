//2568.cpp

#include <iostream>
int calc(int n);
using namespace std;
int main()
{
	int T,n;
	cin >> T;
	while (T--)
	{
		cin >> n;
		cout << calc(n) << endl;
	}
	return 0;
}
int calc(int n)
{
	int ans=0;
	while (n)
	{
		if (n%2==0)
			n /= 2;
		else
		{
			++ans;
			n = (n-1)/2;
		}
	}
	return ans;
}
