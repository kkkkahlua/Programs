//1005.cpp

#include <iostream>
/*int ans,a,b;
int calc(int n);
int main()
{
	using namespace std;
	int n;
	while (cin >> a >> b >> n && a!=0)
	{
		a = a%7;
		b = b%7;
		cout << calc(n) << endl;
	}
}
int calc(int n)
{
	if (n==1 || n==2)
		return 1;
	return (a*(calc(n-1)%7)+b*(calc(n-2)%7))%7;
}
*/
int main()
{
	using namespace std;
	int f[3];
	int n,a,b,i,now,past;
	while (cin >> a >> b >> n && a!=0)
	{
		f[1] = f[2] = 1;
		a = a%7;
		b = b%7;
		n = n%49;
		for (i=3;i<=n;++i)
		{
			now = (i+1)%2+1;
			past = i%2+1;
			f[now] = ((a*f[past])%7+(b*f[now])%7)%7;
		}
		cout << f[(n+1)%2+1] << endl;
	}
	return 0;
}
