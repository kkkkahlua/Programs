//11763.cpp

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxx 11
#define maxn 110000
int a[maxx][maxn],dp[maxx][maxn];
bool can[maxx][maxn];
int main()
{
    freopen("1176.in","r",stdin);
    freopen("1176.out","w",stdout);
    int ans,n,maxT,i,j,x,y;
    memset(can,0,sizeof(can));
    for (i=0;i<=5;++i)
       	for (j=5-i;j<=5+i;++j)
       		can[j][i] = true;
    for (i=0;i<=10;++i)
    	for (j=6;j<=maxn;++j)
    		can[i][j] = true;
    while (scanf("%d",&n) && n!=0)
    {
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        maxT = 0;
        for (i=0;i<n;++i)
        {
            cin >> x >> y;
            ++a[x][y];
            maxT = max(maxT,y);
        }
        ans = 0;
        for (i=4;i<=6;++i)
        {
            dp[i][1] = a[i][1];   
            ans = max(ans,dp[i][1]);
        }
        for (i=2;i<=maxT;++i)
        {
        	if (can[0][i])
	            dp[0][i] = max(dp[0][i-1],dp[1][i-1])+a[0][i];
	        if (can[10][i])
	            dp[10][i] = max(dp[10][i-1],dp[9][i-1])+a[10][i];
            for (j=1;j<=9;++j)
            	if (can[j][i])
	            {
    	            dp[j][i] = max(dp[j+1][i-1],dp[j][i-1]);
        	        dp[j][i] = max(dp[j][i],dp[j-1][i-1]);
            	    dp[j][i] += a[j][i];
	            }
	        for (j=0;j<=10;++j)
	        	ans = max(ans,dp[j][i]);
        }
        printf("%d\n",ans);
/*        for (i=0;i<=10;++i)
        {
            for (j=0;j<=maxT;++j)
                printf("%d ",dp[i][j]);
            printf("\n");
        }*/
    }
//    fclose(stdin);
//    fclose(stdout);
    return 0;
}
