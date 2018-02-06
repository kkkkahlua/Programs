//52.cpp

#include <iostream>
using namespace std;
int main() {
	freopen("5.in", "r", stdin);
	freopen("52.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		int a, b, c, n;
		cin >> a >> b >> c >> n;
		int maxA = n/a;
		bool flag = false;
		for (int i = 0; i <= maxA; ++i) {
			if (flag) break;
			int tot = n - i * a;
			int maxB = tot/b;
			for (int j = 0; j <= maxB; ++j) {
				int left = tot - j * b;
				if (left % c == 0) {
					flag = true;
//					cout << i << " " << j << " " << left/c << endl;
					break;
				}
			}
		}
		if (flag) cout << "YES\n";
		else	cout << "NO\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
