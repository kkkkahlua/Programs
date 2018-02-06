#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

const int maxn = 200100;
int n, ca, c[maxn], dfn[maxn], tot;
ll sz[maxn], ans;
vector<int> ed[maxn];
stack<int> vec[maxn];

void dfs(int t, int fa){
	dfn[t] = ++tot;
	sz[t] = 1;
	for(auto v : ed[t]){
		if(v == fa) continue;
		dfs(v, t);
		sz[t] += sz[v];
		int tmp = sz[v];
		while(!vec[c[t]].empty() && dfn[vec[c[t]].top()] > dfn[t]){
			tmp -= sz[vec[c[t]].top()];
			vec[c[t]].pop();
		}
		ans -= (ll)tmp * (tmp - 1) / 2;
	}
	vec[c[t]].push(t);
}

int main(){
	while(~scanf("%d", &n)){
		for(int i = 1; i <= n; ++i)	scanf("%d", c + i);
		for(int i = 1; i < n; ++i){
			int u, v;
			scanf("%d%d", &u, &v);
			ed[u].pb(v);
			ed[v].pb(u);
		}
		tot = 0;
		ans = (ll)n * n * (n - 1) / 2;
		dfs(1, 0);
		for(int i = 1; i <= n; ++i){
			ed[i].clear();
			int tmp = n;
			while(!vec[i].empty()){
				tmp -= sz[vec[i].top()];
				vec[i].pop();
			}
			ans -= (ll)tmp * (tmp - 1) / 2;
		}
		printf("Case #%d: %lld\n", ++ca, ans);
	}
	return 0;
}
