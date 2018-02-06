//1001.cpp

#include <iostream>
int main()
{
	using namespace std;
	unsigned long long n;
	while (cin >> n)
	{
		unsigned long long ans = (double)n/2*(n+1);
		cout << ans << endl << endl;
	}
	
	return 0;
}
