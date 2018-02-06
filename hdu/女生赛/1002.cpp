//A

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long LL;
int n, m;
LL dp[3010][2];
struct node {
	int x, c;
}a[3010], b[3010];
bool cmp(node u, node v) {
	return u.x < v.x;
}
LL min(LL a, LL b) { return a > b ? b : a; }
void work() {
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &a[i].x, &a[i].c);
	}
	sort(a, a + n, cmp);
	int p = a[0].x, c = a[0].c;
	int tot = 0;
	for (int i = 1; i < n; ++i) {
		if (a[i].x == p) {
			c = a[i].c < c ? a[i].c : c;
		}
		else {
			b[tot].x = p;
			b[tot++].c = c;			
			p = a[i].x;
			c = a[i].c;
		}
	}
	b[tot].x = p; b[tot++].c = c;
//	for (int i = 0; i < tot; ++i) {
//		cout << b[i].x << " " << b[i].c << endl;
//	}
	dp[0][1] = dp[0][0] = b[0].c;
	for (int i = 1; i < tot; ++i) {
		dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + (LL)b[i].c;
		LL dist = b[i].x - b[i-1].x;
		LL ans = dist + dp[i-1][1];
		for (int j = i - 2; j >= 0; --j) {
			dist += (LL)(i - j) * (b[j + 1].x - b[j].x);
			ans = dist + dp[j][1] < ans ? dist + dp[j][1] : ans;
		}
		dp[i][0] = ans;
	}
	printf("%I64d\n", min(dp[tot-1][0], dp[tot-1][1]));
}
int main() {
	int T;
//	scanf("%d", &T);
	while (scanf("%d", &n) != EOF) work();
	return 0;
}
