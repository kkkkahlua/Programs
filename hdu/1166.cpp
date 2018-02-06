//1166.cpp

#include <iostream>
using namespace std;
void build(int id,int l,int r);
void query(int id,int l,int r,int &ans);
void modify(int id,int x,int del,char ch);
void change(int id,int del,char ch);
struct node
{
	int l,r,sum;
}tree[50050*4];
int main()
{
//	freopen("1166.in","r",stdin);
//	freopen("1166.out","w",stdout);
	int T,t=0,n,x,y,ans;
	char s[8];
	cin >> T;
	while (T--)
	{
		++ t;
		cout << "Case " << t << ":\n";
		cin >> n;
		build(1,1,n);
		while (scanf("%s",&s) && s[0]!='E')
		{
			scanf("%d%d",&x,&y);
			switch (s[0])
			{
				case 'Q': ans = 0; query(1,x,y,ans); cout << ans << endl; break;
				case 'A': modify(1,x,y,'A');break;
				case 'S': modify(1,x,y,'s');break;
			}
		}
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
void build(int id,int l,int r)
{
	tree[id].l = l;
	tree[id].r = r;
	if (l==r)
	{
		cin >> tree[id].sum;
		return;
	}
	int m = (l+r) >> 1;
	build(id*2,l,m);
	build(id*2+1,m+1,r);
	tree[id].sum = tree[id*2].sum+tree[id*2+1].sum;
}
void query(int id,int l,int r,int &ans)
{
	if (tree[id].l>=l && tree[id].r<=r)
	{
		ans += tree[id].sum;
		return;
	}
	int m = (tree[id].l + tree[id].r) >> 1;
	if (r <= m)
		query(id*2,l,r,ans);
	else if (l>m)
		query(id*2+1,l,r,ans);
	else
	{
		query(id*2,l,m,ans);
		query(id*2+1,m+1,r,ans);
	}
}
void modify(int id,int x,int del,char ch)
{
	if (tree[id].l==tree[id].r)
	{
		change(id,del,ch);
		return;
	}
	int m = (tree[id].l+tree[id].r) >> 1;
	if (x<=m)
		modify(id*2,x,del,ch);
	else
		modify(id*2+1,x,del,ch);
	change(id,del,ch);
}
void change(int id,int del,char ch)
{
	if (ch=='A')
		tree[id].sum += del;
	else
		tree[id].sum -= del;	
}
