#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define maxn 50010
struct Node
{
    int sum;
    int l,r;
} node[maxn*4];
int a[maxn];
void build(int root,int l,int r)
{
    if(l==r)
    {
        node[root].l=l;
        node[root].r=r;
        node[root].sum=a[l];
        return;
    }
    int mid=(l+r)>>1;
    node[root].l=l;
    node[root].r=r;
    build(root<<1,l,mid);
    build(root<<1|1,mid+1,r);
    node[root].sum=node[root<<1].sum+node[root<<1|1].sum;
}
void update(int root,int pos,int change)
{
    if(node[root].l==pos&&node[root].r==pos)
    {
        node[root].sum+=change;
        return;
    }

    int mid=(node[root].l+node[root].r)>>1;
    if(pos<=mid)
        update(root<<1,pos,change);
    else
        update(root<<1|1,pos,change);

    node[root].sum=node[root<<1].sum+node[root<<1|1].sum;
}

int  query(int root,int start,int end)
{
    static int sum=0;
    if(root==1) sum=0;
    if(node[root].l==start&&node[root].r==end)
    {
        sum+=node[root].sum;
        return sum;
    }

    int mid=(node[root].l+node[root].r)>>1;
    if(mid<start)
    {
        query(root<<1|1,start,end);

    }
    else if(mid>=end)
    {
        query(root<<1,start,end);
    }
    else
    {
        query(root<<1,start,mid);
        query(root<<1|1,mid+1,end);

    }
    return sum;
}
int main()
{
	freopen("1166.in","r",stdin);
	freopen("11662.out","w",stdout);	
    int t;
    int Case=0;
    cin>>t;
    while(t--)
    {
        printf("Case %d:\n",++Case);
        int n,i;
        cin>>n;
        for(i=1; i<=n; i++)
        {
            scanf("%d",a+i);
        }
        build(1,1,n);

        char s[8];
        while(~scanf("%s",s)&&s[0]!='E')
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(s[0]=='Q')
                cout<<query(1,x,y)<<endl;
            else if(s[0]=='A')
                update(1,x,y);
            else if(s[0]=='S')
                update(1,x,-y);
        }


    }
	fclose(stdin);
	fclose(stdout);
    return 0;
}

