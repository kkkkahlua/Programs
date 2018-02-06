//7.cpp

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct node {
	int blo, att, time, hurt;
}a[15];
int time[15];
bool cmp(node a, node b) {
	return (a.att > b.att) || (a.att = b.att && a.blo < b.blo);
}
int times(int x, int y) {
	if (x % y == 0) return x/y-1;
	return x / y;
}
int main() {
	int n, ata;
	while (cin >> n >> ata) {
		for (int i = 0; i < n; ++i) {
			cin >> a[i].blo >> a[i].att;
			a[i].time = ceil((double)a[i].blo / ata);
//			a[i].hurt = times(a[i].blo, ata) * a[i].att;
		}
		sort(a, a + n, cmp);
		memset(time, 0, sizeof(time));
		time[0] = a[0].time;
		for (int i = 1; i < n; ++i) {
			time[i] = time[i-1] + a[i].time;
		}
		for (int i = 0; i < n; ++i) {
			--time[i];
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			ans += time[i] * a[i].att;
		}
		cout << ans << endl;
//		for (int i = 0; i < n; ++i) {
//			cout << a[i].blo << " " << a[i].att << endl;
//		}
	}
	return 0;
}
