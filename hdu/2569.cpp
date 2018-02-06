//2569.cpp

#include <iostream>
#define maxn 50
int a[maxn],b[maxn];
using namespace std;
int main()
{
	int T,i,n;
	cin >> T;
	a[1] = 3; b[1] = 0;
	for (i=2;i<40;++i)
	{
		a[i] = a[i-1]+b[i-1];
		b[i] = a[i-1]*2+b[i-1];
	}
	while (T--)
	{
		cin >> n;
		cout << a[n]+b[n] << endl;
	}
	return 0;
}
