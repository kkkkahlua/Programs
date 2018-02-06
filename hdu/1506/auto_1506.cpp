//auto_1506.cpp

#include <iostream>
#include <cstdio>
#include <ctime>
#define n 100010
#define range 1000000010
using namespace std;
int main()
{
	freopen("1506.in","w",stdout);
	int T=10,i;
	srand(time(NULL));
	while (T--)
	{
		cout << n << " ";
		for (i=0;i<n;++i)
			cout << rand() %range+1 << " ";
		cout << endl;
	}
	cout << 0 << endl;
	fclose(stdout);
	return 0;
}
