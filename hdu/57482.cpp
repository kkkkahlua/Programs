//5748.cpp

#include <iostream>
#include <cstring>
#define maxn 1000000
int b[maxn],ans[maxn];
int find(int x,int left,int right);
using namespace std;
int main()
{
//	freopen("data.txt","r",stdin);
//	freopen("57482.out","w",stdout);
	int T,n,i,tot=0,x,p,j;
	cin >> T;
	while (T--)
	{
		memset(b,0,sizeof(b));
//		for (i=0;i<maxn;++i)
//			b[i] = 1e9+10;
		cin >> n;
		cin >> x;
		b[0] = x;
		ans[0] = 1;
		tot = 1;
		for (i=1;i<n;++i)
		{
			cin >> x;
			if (x>b[tot-1]) 
			{
				p = tot;
				++tot;
			}
			else
				p = find(x,0,tot-1);
			b[p] = x;
			ans[i] = p+1;
/*			for (j=0;j<tot;++j)
				cout << b[j] << " ";
			cout << endl;*/
		}
		for (i=0;i<n-1;++i)
			cout << ans[i] << " ";
		cout << ans[n-1] << endl;
	}
	return 0;
//	fclose(stdin);
//	fclose(stdout);
}
int find(int x,int left,int right)
{
	if (left==right)
		return right;
	int mid = (left+right) >> 1;
	if (b[mid]<x)
		return find(x,mid+1,right);
	else if (b[mid]>x)
		return find(x,left,mid);
	else
		return mid;
}

