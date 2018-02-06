//21593.cpp others for duipai
#include<iostream>  
#include<stdio.h>  
#include<string.h>  
#include<string>  
using namespace std;  
  
int v[105];  
int w[105];  
int dp[105][105];  
  
int main()  
{  
	freopen("data.txt","r",stdin);
	freopen("21593.out","w",stdout);
    int n,m,k,s;  
    int i,j,p;  
    while(scanf("%d%d%d%d",&n,&m,&k,&s)!=EOF)//还需的经验值，保留的忍耐度，怪的种数和最多的杀怪数  
    {  
        memset(dp,0,sizeof(dp));  
        memset(v,0,sizeof(v));  
        memset(w,0,sizeof(w));  
  
        for(i = 1; i <= k; i++)  
        {  
            scanf("%d%d",&v[i],&w[i]);//v得到的经验值，w损失的忍耐度  
        }  
  
        for(i = 1; i <= k; i++)//第几个怪物  
            for(j = 1; j <= s; j++)//怪物个数  
                for(p = w[i]; p <= m; p++)//忍耐度  
                    dp[j][p] = max(dp[j][p],dp[j-1][p-w[i]]+v[i]);  
        if(dp[s][m] < n)  
            printf("-1\n");//不能升级  
        else  
        {  
            int minvalue = 0x3f3f3f3f;  
            for(j = 0; j <= s; j++)  
                for(p = 0; p <= m; p++)  
                    if(dp[j][p] >= n && p < minvalue)  
                        minvalue = p;  
            printf("%d\n",m - minvalue);  
        }  
    }  
    fclose(stdin);
    fclose(stdout);
    return 0;  
}  
