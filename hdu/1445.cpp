//1445.cpp

#include <iostream>
#include <cmath>
#include <climits>
#define s 4.5
int main()
{
	using namespace std;
	int n;
	cin >> n;
	int min,i,time,v,t;
	while (n!=0)
	{
		min = INT_MAX;
		for (i=0;i<n;++i)
		{
			cin >> v >> t;
			if (t<0)
				continue;
			time = ceil(s/((double)v/3600)+t);
			if (time<min)
				min = time;
		}
		cout << min << endl;
		cin >> n;
	}
	
	return 0;
}
