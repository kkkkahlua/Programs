//1013.cpp

#include <iostream>
#include <string>
#include <cstring>
int calc(int n);
int main()
{
	using namespace std;
	int n,ans;
	string s;
	while (cin >> s && s[0]!='0')
	{
		n = 0;
		for (int i=0;i<s.size();++i)
			n += s[i]-'0';
		ans = calc(n);
		while (ans>=10)
			ans = calc(ans);
		cout << ans << endl;
	}
	return 0;
}
int calc(int n)
{
	int ans=0;
	while (n>0)
	{
		ans += n%10;
		n /= 10;
	}
	return ans;
}
