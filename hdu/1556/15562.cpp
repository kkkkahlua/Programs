//15562.cpp

#include <stdio.h>  
#include <string.h>  
#include <algorithm>  
using namespace std;  
  
int ans[1000000],n;  
  
struct node  
{  
    int l,r,n;  
} a[1000000];  
  
void init(int l,int r,int i)  
{  
    a[i].l = l;  
    a[i].r = r;  
    a[i].n = 0;  
    if(l!=r)  
    {  
        int mid = (l+r)>>1;  
        init(l,mid,2*i);  
        init(mid+1,r,2*i+1);  
    }  
}  
  
void insert(int i,int x,int y)  
{  
    if(a[i].l == x && a[i].r == y)//找到要刷的气球区间，更新其被刷的次数+1  
        a[i].n++;  
    else  
    {  
        int mid = (a[i].l+a[i].r)>>1;  
        if(y<=mid)  
            insert(2*i,x,y);  
        else if(x>mid)  
            insert(2*i+1,x,y);  
        else  
        {  
            insert(2*i,x,mid);  
            insert(2*i+1,mid+1,y);  
        }  
    }  
}  
  
void add(int x)  
{  
    int i;  
    for(i = a[x].l; i<=a[x].r; i++)//该区间所有编号都被刷了一次  
        ans[i]+=a[x].n;  
    if(a[x].l == a[x].r)  
        return;  
    add(2*x);  
    add(2*x+1);  
}  
  
int main()  
{  
	freopen("1556.in","r",stdin);
	freopen("15562.out","w",stdout);
    int x,y,i;  
    while(~scanf("%d",&n),n)  
    {  
        init(1,n,1);  
        for(i = 1; i<=n; i++)  
        {  
            scanf("%d%d",&x,&y);  
            insert(1,x,y);  
        }  
        memset(ans,0,sizeof(ans));  
        add(1);  
        printf("%d",ans[1]);  
        for(i = 2; i<=n; i++)  
            printf(" %d",ans[i]);  
        printf("\n");  
    }  
    fclose(stdin);
    fclose(stdout);
  
    return 0;  
}  
