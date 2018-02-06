//2570.cpp

#include <iostream> 
#include <iomanip>
#include <cstring>
using namespace std;
#define maxn 110
int p[maxn],ans[maxn];
int main()
{
	int T,n,v,w,i,j;
	cin >> T;
	while (T--)
	{
		cin >> n >> v >> w;
		memset(ans,0,sizeof(ans));
		for (i=0;i<n;++i)
			cin >> p[i];
		ans[0] = 0; //ans[1] = p[0];
		for (i=0;i<n;++i)
			for (j=n;j>=1;--j)
				if (ans[j-1] || j-1==0)
					if (ans[j])			
						ans[j] = min(ans[j],ans[j-1]+p[i]);
					else
						ans[j] = ans[j-1]+p[i];
/*		for (i=0;i<=n;++i)
			cout << ans[i] << " ";
		cout << endl;*/
		i = n;
		while (i && ans[i]/(double)i-w>1e-6)
			--i;
		if (i==0)
			cout << "0 0.00\n";
		else
			cout << i*v << " " << fixed << setprecision(2) << ans[i]/(100.0*i) << endl;
	}
	return 0;
}
