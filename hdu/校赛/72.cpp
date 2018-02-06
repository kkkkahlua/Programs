//72.cpp

#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
using namespace std;
int h[15], a[15], time[15], ans[15], tempA[15], tempT[15], tot[15], prior[15][15];
bool vis[15];
int test(int n) {
	for (int i = 0; i < n; ++i) {
		tempA[i] = a[ans[i]];
		tempT[i] = time[ans[i]];
	}
	memset(tot, 0, sizeof(tot));
	tot[0] = tempT[0];
	for (int i = 1; i < n; ++i) {
		tot[i] = tot[i-1] + tempT[i];
	}
	for (int i = 0; i < n; ++i) --tot[i];
	int sum = 0;
	for (int i = 0; i < n; ++i) sum += tot[i] * tempA[i];
	return sum;
}
int ret = INT_MAX;
bool check(int p, int x) {
	for (int i = 0; i <= p; ++i) {
		if (ans[i] != x && prior[ans[i]][x] == -1) return false;
	}
	return true;
}
void dfs(int x,int p,int tot) {
	ans[p] = x;
	if (p == tot-1) {
		int sum = test(tot);
		ret = min(sum, ret);
//		for (int i = 0;i < tot; ++i)
//			cout << ans[i];
//		cout << endl;
		return;
	}
	for (int i = 0; i < tot;++i)
		if (!vis[i] && check(p, i)) {
			vis[i] = true;
			dfs(i,p+1,tot);
			vis[i] = false;
		}
}
int main() {
	int n, ata;
	while (cin >> n >> ata) {
		ret = INT_MAX;
		for (int i = 0; i < n; ++i) {
			cin >> h[i] >> a[i];
			time[i] = ceil((double)h[i]/ata);
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i != j) {
					if (h[i] == h[j] && a[i] <= a[j]) {
						prior[j][i] = 1;
						prior[i][j] = -1;
					}
					if (a[i] == a[j] && h[i] >= h[j]) {
						prior[j][i] = 1;
						prior[i][j] = -1;
					}
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			vis[i] = true;
			dfs(i, 0, n);
			vis[i] = false;
		}
		cout << ret << endl;
	}
	return 0;
}
