//auto_2159.cpp

#include <iostream>
using namespace std;
#define n 50
#define m 50
#define k 10
#define s 100
#include <ctime>
#include <cstdio>
int main()
{
	freopen("data.txt","w",stdout);
	srand(time(NULL));
	int T = 5;
	while (T--)
	{
	int i;
	cout << n << " " << m << " " << k << " " << s << endl;
	for (i=0;i<k;++i)
		cout << rand() %20+1 << " " << rand() %20+1 << endl;
	}
	fclose(stdout);
	return 0;
}
