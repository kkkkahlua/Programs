//2.cpp

#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
struct node {
	int dis, val;
}a[20020];
double sum[20020];
using namespace std;
bool cmp(node a, node b) {
	return a.dis < b.dis;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		memset(sum, 0, sizeof(sum));
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a[i].dis >> a[i].val;
		}
		sort(a, a + n, cmp);
		sum[0] = a[0].val;
		for (int i = 1; i < n; ++i) {
			sum[i] = sum[i-1] + a[i].val;
		}
		double ans = -1000;
		ans += sum[n-1];
		for (int i = 0; i < n-1; ++i) {
			ans += (double)sum[i]/(i+1);
		}
		cout << fixed << setprecision(2) << ans << endl;
	}
	return 0;
}
