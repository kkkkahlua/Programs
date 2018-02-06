//1506.cpp

#include <iostream> 
#define maxn 100010
int a[maxn];
using namespace std;
int main()
{
    int n,i,k,minn,maxx,ans;
    while (cin >> n && n)
    {
        for (i=0;i<n;++i)
            cin >> a[i];
        for (i=0;i<n;++i)
        {
            minn = maxx = a[i];
            for (k=1;k<=i;++k)
            {
                minn = min(minn,a[i-k]);
                maxx = max(maxx,minn*(k+1));
                ans = max(ans,maxx);
            }
        }
        cout << ans << endl;
    }
    return 0;    
}
