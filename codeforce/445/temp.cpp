#include<vector>
#include<string>
#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int in[30],out[30],flag[30],a[30][30];
string ans;
vector<char>q[30];
void dfs(int x)
{
	flag[x]=0;
	ans+=x+'a';
	for(int i=0;i<q[x].size();i++)
		dfs(q[x][i]);
}
int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		string s;
		cin >> s;
		for(int j=0;j<s.size()-1;j++)
		{
			int x=s[j]-'a';
			int y=s[j+1]-'a';
			if(a[x][y]==0)
			{
				in[y]++;
				out[x]++;
				a[x][y]=1;
				flag[x]=flag[y]=1;
				q[x].push_back(y);
			}
		}
		flag[s[0]-'a']=1;
	}
	for(int i=0;i<26;i++)
		if(in[i]>1 || out[i]>1)
		{

		    printf("%d\n", i);
			printf("NO\n");
			return 0;
		}
	for(int i=0;i<26;i++)
		if(in[i]==0 && flag[i])
			dfs(i);
	for(int i=0;i<26;i++)
		if(flag[i])
		{
		    printf("%d\n", i);
			printf("NO\n");
			return 0;
		}
	cout << ans << endl;
	return 0;
}
