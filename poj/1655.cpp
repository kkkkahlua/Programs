//1655.cpp

#include <iostream>
#include <cstring>
#define maxn 100010
struct edge {
	int to;
	edge* next;
}v[maxn];
edge* head[maxn];
using namespace std;
int n, minB = maxn, p, s[maxn], ne;
void build(int a,int b);
void dfs(int x);
int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		ne = 0;
		memset(v,0,sizeof(v));
		memset(s,0,sizeof(s));
		minB = maxn;
		for (int i=1;i<=n;++i) {
			head[i] = NULL;
		}
		int x,y;
		for (int i=0;i<n-1;++i) {
			cin >> x >> y;
			build(x,y);
			build(y,x);
		}
		dfs(1);
		cout << p << " " << minB << endl;
	}
}
void build(int a,int b) {
	v[ne].to = b;
	v[ne].next = head[a];
	head[a] = &v[ne++];
}
void dfs(int x) {
	s[x] = 1;
	int maxT = 0;
	for (edge* i = head[x]; i!=NULL; i = i -> next) {
		if (s[i->to]==0) {
			dfs(i->to);
			s[x] += s[i->to];
			maxT = max(maxT,s[i->to]);
		}
	}
	maxT = max(maxT,n-s[x]);
	if (maxT < minB) {
		minB = maxT;
		p = x;
	}else if (maxT == minB && x < p) {
		p = x;
	}
}
