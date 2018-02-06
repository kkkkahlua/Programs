//auto_1166.cpp

#include <iostream>
#include <string>
#include <ctime>
#include <cstdio>
#define n 100
#define range 100
using namespace std;
const string list[3] = {"Query","Add","Sub"};
int main()
{
	freopen("1166.in","w",stdout);
	int t = 10,i,x,y;
	srand(time(NULL));
	cout << t << endl;
	while (t--)
	{
		cout << n << endl;
		for (i=0;i<n;++i)
			cout << rand() %range << " ";
		cout << endl;
		for (i=0;i<n;++i)
		{
			x = rand()% (n-1)+1;
			y = rand()%(n-x)+x;
			cout << list[rand()%3] << " " << x << " " << y << endl;
		}
		cout << "End\n";
	}
	fclose(stdout);
	return 0;
}
