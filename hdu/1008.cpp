//1008.cpp

#include <iostream>
int main()
{
	using namespace std;
	int n,y,up,down,now;
	while (cin >> n && n!=0)
	{
		up = down = 0;
		now = 0;
		for (int i=0;i<n;++i)
		{
			cin >> y;
			if (y>now)
				up += y-now;
			else
				down += now-y;
			now = y;
		}
		cout << up*6+down*4+n*5 << endl;
	}
	
	return 0;
}
