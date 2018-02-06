//auto_1203.cpp

#include <iostream>
#include <ctime>
#include <cstdio>
#include <iomanip>
#define n 100
#define m 100
using namespace std;
int main()
{
	freopen("data.txt","w",stdout);
	int T=10;
	while (T--)
	{
	srand(time(NULL));
	int i;
	cout << n << " " << m << endl;
	for (i=0;i<m;++i)
		cout << rand()% (n/2) << " " << fixed << setprecision(2) << (rand()%100)/100.0 << endl;
	}
	cout << "0 0\n";
	fclose(stdout);
	return 0;
}
