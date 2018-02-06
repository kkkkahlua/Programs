//2567.cpp

#include <iostream>
#include <cstring>
#define maxn 50
char ch1[maxn],ch2[maxn];
using namespace std;
int main()
{
	int T,len,i;
	cin >> T;
	while (T--)
	{
		cin >> ch1 >> ch2;
		len = strlen(ch1);
		for (i=0;i<len/2;++i)
			cout << ch1[i];
		cout << ch2;
		for (i=len/2;i<len;++i)
			cout << ch1[i];
		cout << endl;
	}
	return 0;
}
