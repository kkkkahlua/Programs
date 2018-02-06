//1159.cpp

#include <iostream>
#include <cmath>
using namespace std;
#include <string>
#include <cstring>
#define maxn 2000
int a[maxn][maxn];
int main()
{
	string s1,s2;
	while (cin >> s1 >> s2)
	{
		int len1 = s1.size();
		int len2 = s2.size();
		int i,j;
		for (i=0;i<len1;++i)
			for (j=0;j<len2;++j)
				if (s1[i]==s2[j])
					a[i+1][j+1] = a[i][j]+1;
				else
					a[i+1][j+1] = max(a[i][j+1],a[i+1][j]);
		cout << a[len1][len2] << endl;
	}
	return 0;
}
