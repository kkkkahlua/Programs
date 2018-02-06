//1505.cpp

#include <iostream>
#include <string>
#define maxn 1010
int map[maxn][maxn],minim[maxn][maxn];
using namespace std;
int main()
{
	int T,m,n,i,j,ans,k,x,anss;
	string s;
	char ch;
	cin >> T;
	while (T--)
	{
		cin >> m >> n;
		for (i=1;i<=m;++i)
			for (j=1;j<=n;++j)
			{ 
				cin >> ch;
				if (ch=='F') 
					map[i][j] = map[i][j-1]+1;
				else
					map[i][j] = 0;
			}
		anss = 0;
		for (i=1;i<=m;++i)
			for (j=1;j<=n;++j)
			{
				x = ans = map[i][j];
				for (k=1;k<=i-1;++k)
				{
					if (map[i-k][j]==0)
						break;
					x = min(x,map[i-k][j]);
					ans = max(ans,x*(k+1));
				}
				anss = max(anss,ans);
			}
		cout << anss*3 << endl;
		getline(cin,s);
	}
	return 0;
}
