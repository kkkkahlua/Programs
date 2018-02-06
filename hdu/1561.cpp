//1561.cpp

#include <iostream>
#include <vector>
#include <cstring>
#define maxn 220
using namespace std;
vector<int> a[maxn];
int n, dp[maxn][maxn];
void dfs(int);
int main() {
	int m;
	while (cin >> m >> n && m && n) {
		++n;
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		for (int i=1;i<=m;++i) {
			int x,y;
			cin >> x >> y;
			a[x].push_back(i);
			for (int j=1;j<=n;++j) {
				dp[i][j] = y;
			}
		}
		dfs(0);
		cout << dp[0][n] << endl;
	}
	return 0;
}
void dfs(int x) {
	if (a[x].size() == 0) {
		return;
	}
	for (int i = 0; i < a[x].size(); ++i) {
		dfs(a[x][i]);
		for (int j = n; j >= 1; --j) {
			for (int k = 1; k <= j; ++k) {
				dp[x][j] = max(dp[x][j],dp[x][k]+dp[a[x][i]][j-k]);
			}
		}
	}
}
