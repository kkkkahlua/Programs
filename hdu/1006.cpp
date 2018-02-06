//	1006
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
bool check(double x, double y, double d) {
	return fabs(x - y) >= d && 360 - d >= fabs(x - y);
}
double hr[50050], mi[50050], se[50050];
int main() {
	for (int i = 0; i < 12; ++i) {
		int hr1 = i * 30, ti1 = i * 3600;
		for (int j = 0; j < 60; ++j) {
			int hr2 = hr1 + j * 0.5;
			int mi1 = j * 6;
			int ti2 = ti1 + j * 60;
			for (int k = 0; k < 60; ++k) {
				int ti = ti2 + k;
//				cout << ti << " : " << hr2 + k * 0.5 / 60 << endl;
				hr[ti] = hr2 + k * 0.5 / 60;
				mi[ti] = mi1 + k * 0.1;
				se[ti] = k * 6;
			}
		}
	}
//	for (int i = 0; i < 43200; ++i) {
//		cout << hr[i] << " " << mi[i] << " " << se[i] << endl;
//	}
	double d;
	while (cin >> d && !fabs(d + 1) < 0.001) {
		int tot = 0;
		for (int i = 0; i < 43200; ++i) {
			if (check(hr[i], mi[i], d) && check(hr[i], se[i], d) && check(mi[i], se[i], d)) ++tot;
//			else cout << i << endl;
		}
		cout << fixed << setprecision(3) << (double)tot*100 / 43200 << endl;
	}
	return 0;
}
