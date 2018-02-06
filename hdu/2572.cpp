//2572.cpp

#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#define maxn 20
int nn[maxn];
using namespace std;
int kmp(string s,string t);
void findnn(string s);
int main()
{
	int T,x1,x2,minn,maxx,i;
	string s1,s2,s3;
	cin >> T;
	while (T--)
	{
		cin >> s1 >> s2 >> s3;
		tot1 = kmp(s1,s2,1);
		tot2 = kmp(s1,s3,2);
		
		cout << x1 << " " << x2 << endl;
		if (x1==-1 || x2==-1)
		{
			cout << "No\n";
			continue;
		}
		minn = min(x1,x2);
		maxx = max(x1+s2.size()-1,x2+s3.size()-1);
		for (i=minn;i<=maxx;++i)
			cout << s1[i];
		cout << endl;
	}
	return 0;
}
void findnn(string s)
{
	int p,len,i;
	nn[0] = 0;
	p = 0;
	len = s.size();
	for (i=1;i<len;++i)
	{
		while (p>0 && s[i]!=s[p])
			p = nn[p-1];
		if (s[i]==s[p])
			++ p;
		nn[i] = p;
	}		
}
int kmp(string s,string t,int k)
{
	int p,len,i,l,tot;
	findnn(t);
	p = 0;
	l = s.size();
	len = t.size();
	tot = 0;
	for (i=0;i<l;++i)
	{
		while (p>0 && s[i]!=t[p])
			p = nn[p-1];
		if (s[i] = t[p])
			++ p;
		if (p==len)
			if (k==1)
				ans[tot++] = i-p+1;
			else
				ans2[tot++] = i-p+1;
	}
	return tot;
}
