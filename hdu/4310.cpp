//	4310
#include <iostream>
#include <algorithm>
using namespace std;
struct node {
	int dps, hp;
}a[22];
bool cmp(node u, node v) {
	return u.hp * v.dps < v.hp * u.dps;
}
int main() {
	int n;
	while (cin >> n) {
		for (int i = 0; i < n; ++i) {
			cin >> a[i].dps >> a[i].hp;
		}
		sort(a, a + n, cmp);
		int ans = 0;
		for (int i = 0; i < n; ++i) a[i].hp += a[i-1].hp;
		for (int i = 0; i < n; ++i) ans += a[i].hp * a[i].dps;
		cout << ans << endl;
	}
	return 0;
}
