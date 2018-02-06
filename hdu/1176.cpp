//1176.cpp

#include <cstdio>
#define maxn 110000
#include <cmath>
#include <iostream>
using namespace std;
int x[maxn],T[maxn],sum[maxn];
void qsort(int l,int r,int x[maxn],int T[maxn]);
int main()
{
    int n,i,j,maxx;
	while (scanf("%d",&n) && n!=0)
    {
        for (i=1;i<=n;++i)
            scanf("%d %d",&x[i],&T[i]);
        x[0] = 5;
        T[0] = 0;
        sum[0] = 0;
        qsort(1,n,x,T);
        for (i=1;i<=n;++i)
        {
            maxx = 0;
            for (j=0;j<i;++j)
                if (abs(x[i]-x[j])<=T[i]-T[j])
                    maxx = max(maxx,sum[j]+1);
            sum[i] = maxx;
        }
        maxx = 0;
        for (i=0;i<=n;++i)
            maxx = max(maxx,sum[i]);
        printf("%d\n",maxx);
    }
    return 0;
}
void qsort(int l,int r,int x[maxn],int T[maxn])
{
    int key,keyy;
    if (l<r)  
    {  
        int i = l, j = r, key = T[l], keyy = x[l];
        while (i<j)  
        {
            while(i<j && T[j]>=key) 
                j--;    
            if(i<j)   
            {
                T[i] = T[j];
                x[i++] = x[j];
            }
            while(i<j && T[i]<key)
                i++;    
            if(i<j)   
            {
                T[j] = T[i];  
                x[j--] = x[i];
            }
        }  
        T[i] = key;  
        x[i] = keyy;
        qsort(l,i-1,x,T);
        qsort(i+1,r,x,T);  
    }  
}  
