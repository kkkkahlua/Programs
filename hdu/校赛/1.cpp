//1.cpp

#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	int a, b, n;
	double ans;
	while (cin >> a >> b >> n) {
		if (a > b) ans = 1;
		else if (a + n <= b) ans = 0;
		else {
			ans = (double)(a + n - b) / (n+1);
		}
		cout << fixed << setprecision(3) << ans << endl;
	}
	return 0;
}
