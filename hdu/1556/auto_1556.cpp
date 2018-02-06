//auto_1556.cpp

#include <iostream>
#include <ctime>
#include <cstdio>
using namespace std;
#define n 100010
int main()
{
	freopen("1556.in","w",stdout);
	int t=10,x,y,i;
	srand(time(NULL));
	while (t--)
	{
		cout << n << endl;
		for (i=0;i<n;++i)
		{
		x = rand() %(n-1)+1;
		y = rand() %(n-x) + x;
		cout << x << " " << y << endl;
	}
	}
	cout << 0 << endl;
	fclose(stdout);
	return 0;
}
