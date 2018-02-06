//8.cpp

#include <iostream>
int nutri(int x) {
	int tot = 0;
	while (x) {
		++tot;
		x &= x-1;
	}
	return tot;
}
using namespace std;
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, ans = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			ans += nutri(x);
		}
		if (ans & 1) cout << "odd\n";
		else	cout << "even\n";
	}
	return 0;
}
