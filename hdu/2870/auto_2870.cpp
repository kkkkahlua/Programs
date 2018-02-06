//auto_2870.cpp

#include <iostream>
#define m 1000
char c[] = {'a','b','c','w','x','y','z'};
#include <cstdio>
#include <ctime>
using namespace std;
int main()
{
	freopen("2870.in","w",stdout);
	int i,j;
	srand(time(NULL));
	int t=10;
	while (t--)
	{
	cout << m << " " << m << endl;
	for (i=0;i<m;++i)
	{
		for (j=0;j<m;++j)
			cout << c[rand()%7];
		cout << endl;
	}
}
	fclose(stdout);
	return 0;
}
