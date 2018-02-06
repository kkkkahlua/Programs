//A

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, m;
int gcd_f[100010], gcd_r[100010], a[100010];
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
void work() {
	memset(gcd_f, 0, sizeof(gcd_f));
	memset(gcd_r, 0, sizeof(gcd_r));
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	gcd_f[0] = a[0];
	for (int i = 1; i < n; ++i) {
		gcd_f[i] = gcd(gcd_f[i - 1], a[i]);
	}
	gcd_r[n-1] = a[n-1];
	for (int i = n-2; i >= 0; --i) {
		gcd_r[i] = gcd(gcd_r[i + 1], a[i]);
	}
	int ans = 1;
	ans = gcd_r[1] > ans ? gcd_r[1] : ans;
	ans = gcd_f[n-2] > ans ? gcd_f[n-2] : ans;
	for (int i = 1; i < n-1; ++i) {
		int x = gcd(gcd_f[i - 1], gcd_r[i + 1]);
		ans = x > ans ? x : ans;
	}
//	for (int i = 0; i < n; ++i) {
//		cout << gcd_f[i] << " ";
//	}
//	cout << endl;
//	for (int i = 0; i < n; ++i) {
//		cout << gcd_r[i] << " ";
//	}
//	cout << endl;
	printf("%d\n", ans);
}
int main() {
	int T;
	scanf("%d", &T);
	while (scanf("%d", &n) != EOF) work();
	return 0;
}
