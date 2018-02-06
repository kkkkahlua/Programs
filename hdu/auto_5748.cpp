//data.txt

#include <iostream>
#include <cstdio>
#include <ctime>
#define maxn 1000000000
#define maxx 100
using namespace std;
int main()
{
	freopen("data.txt","w",stdout);
	int T=1,i; 
	cout << T << endl;
	srand(time(NULL));
	int x;
	while (T--)
	{
		x = rand() %maxx+1;
	cout << x << endl;
	for (i=0;i<x;++i)
		cout << (rand() %maxn) << " ";
	cout << endl;
}
	return 0;
	fclose(stdout);
}
