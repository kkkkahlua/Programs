//1058.cpp

#include <iostream> 
using namespace std;
int ans[5000];
#include <cmath>
int main()
{
	int p2,p3,p5,p7,i,minn,n,last,last2;
	ans[1] = 1;
	p2 = p3 = p5 = p7 = 1;
	for (i=2;i<=5842;++i)
	{
		minn = min(ans[p2]*2,ans[p3]*3);
		minn = min(minn,ans[p5]*5);
		minn = min(minn,ans[p7]*7);
		ans[i] = minn;
		if (minn==ans[p2]*2)
			++p2;
		if (minn==ans[p3]*3)
			++p3;
		if (minn==ans[p5]*5)
			++p5;
		if (minn==ans[p7]*7)
			++p7;
	}
	while (cin >> n && n)
	{
		cout << "The " << n;
		last = n%10;
		last2 = n%100;
		switch (last)
		{
			case 1: 
			{
				if (last2==11)
					cout << "th ";
				else
					cout << "st ";
				break;
			}
			case 2: 
			{
				if (last2==12)
					cout << "th ";
				else
					cout << "nd ";
				break;
			}
			case 3: 
			{
				if (last2==13)
					cout << "th ";
				else
					cout << "rd ";
				break;
			}
			default: cout << "th "; break;
		}
		cout << "humble number is " << ans[n] << ".\n";
	}
	return 0;
}
