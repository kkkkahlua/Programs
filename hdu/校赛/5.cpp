//5.cpp
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
int exgcd(int a, int b, int& x, int& y) {
	if (b == 0) {
		x = 1; y = 0;
		return a;
	}
	int r = exgcd(b, a%b, x, y);
	int temp = x;
	x = y;
	y = temp - (a/b) * y;
	return r;
}
int x[10];
int main() {
//	freopen("5.in", "r", stdin);
//	freopen("5.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		bool flag = false;
		int n;
		cin >> x[0] >> x[1] >> x[2] >> n;
		sort(x, x+3, cmp);
		int maxA = n/x[0];
		for (int i = 0; i <= maxA; ++i) {
			int tot = n - x[0]*i;
			int GCD = gcd(x[1], x[2]);
			if (tot % GCD == 0) {
				int x1, x2;
				exgcd(x[1], x[2], x1, x2);
				int mul = tot/GCD;
				x1 *= mul;
				x2 *= mul;
				if (x1 >= 0 && x2 >= 0) {
					flag = true;
					break;
				}
				else {
					int add1 = x[2] / GCD, add2 = x[1] / GCD;
					if (x1 < 0) {
						int t = ceil((double)(-x1)/add1);
   						if (x2 - t*add2 >= 0) {
							flag = true;
							break;
						}
					}
					else {
						int t = ceil((double)(-x2)/add2);
						if (x1 - t*add1 >= 0) {
							flag = true;
							break;
						}
					}
				}
			}
		}
		if (flag) cout << "Yes\n";
		else	cout << "No\n";
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
