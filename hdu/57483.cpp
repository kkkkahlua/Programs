#include <iostream>  
#include<stdio.h>  
using namespace std;  
int a[1000000],b[1000000],c[1000000];  
int find(int *a,int len,int n)//若返回值为x,则a[x]>=n>a[x-1]  
{  
    int left=0,right=len,mid=(left+right)/2;  
    while(left<=right)  
    {  
        if(n>a[mid]) left=mid+1;  
        else if(n<a[mid]) right=mid-1;  
        else return mid;  
        mid=(left+right)/2;  
    }  
    return left;  
}  
void fill(int *a,int n)  
{  
    for(int i=0;i<=n;i++)  
        a[i]=1000000010;  
}  
int main()  
{  
	freopen("data.txt","r",stdin);
	freopen("57483.out","w",stdout);
    int max,i,j,n;  
    int t;  
    scanf("%d",&t);  
    while(t--)  
    {  
        scanf("%d",&n);  
        fill(c,n+1);  
        for(int i=0;i<n;i++)  
        {  
            scanf("%d",&a[i]);  
        }  
        c[0]=-1;//     …………………………………1  
        c[1]=a[0];//         …………………………2  
        b[0]=1;//      …………………………………3  
        for(i=1;i<n;i++)//           ………………4  
        {  
            j=find(c,n+1,a[i]);//  …………………5  
            c[j]=a[i];// ………………………………6  
            b[i]=j;//……………………………………7  
        }  
        for(int i=0;i<n-1;i++)  
        {  
            printf("%d ",b[i]);  
        }  
        printf("%d\n",b[n-1]);  
    }  
    fclose(stdin);
    fclose(stdout);
}  
