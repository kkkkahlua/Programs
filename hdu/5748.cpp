//bellovin.cpp

#include <iostream> 
#define maxn 100000
int main()
{
	freopen("data.txt","r",stdin);
	freopen("5748.out","w",stdout);
	using namespace std;
	int T;
	int t,n,min,max,tt,i,j;
	int no[maxn],a[maxn];
	cin >> T;
	for (tt=0;tt<T;++tt)
	{
		int n;
		cin >> n;
		cin >> a[0];
		no[0] = 1;
		for (i=1;i<n;++i)
		{
			cin >> a[i];
			max = 0;
			for (t=0;t<i;++t)
				if (no[t]>=max && a[t]<a[i])
					max = no[t];
			no[i] = max+1;
		}
		for (i=0;i<n-1;++i)
			cout << no[i] << " ";
		cout << no[n-1]
		 << endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
