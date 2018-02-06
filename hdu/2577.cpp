//2577.cpp

#include <iostream>
#include <cstring>
using namespace std;
#define maxn 110
char ch[maxn];
int f(int x);
int main()
{
	int n,i,j,len,ans,tot1,tot2;
	bool on;
	cin >> n;
	for (i=0;i<n;++i)
	{
		cin >> ch;
		len = strlen(ch);
		tot1 = tot2 = 0;
		ans = 0;
		on = 0;
		for (j=0;j<len;++j)
			if (ch[j]>='A' && ch[j]<='Z')
			{
				tot1++;
				if (tot2)
				{
					if (on)
						if (tot2==1)
							ans += 2;
						else
						{
							ans += 1+tot2;
							on = false;
						}
					else
						ans += tot2;
					tot2 = 0;
				}
			}
			else
			{
				++tot2;
				if (tot1)
				{
					if (on)
						ans += tot1;
					else
						if (tot1==1)
							ans += 2;
						else
						{
							ans += 1+tot1;
							on = true;
						}
					tot1 = 0;
				}
			}
		if (tot2)
			if (on)
				ans += 1+tot2;
			else
				ans += tot2;
		if (tot1)
			if (on)
				ans += tot1+1;
			else
				if (tot1==1)
					ans += 2;
				else
					ans += 2+tot1;
		cout << ans << endl;
	}
	return 0;
}
