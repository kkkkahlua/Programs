//3.cpp

#include <iostream>
#include <string>
#include <cstring>
#define LEN 1440
int ring[2020];
using namespace std;
int main() {
	int n, m;
	while (cin >> n >> m) {
		int t;
		cin >> t;
		memset(ring, 0, sizeof(ring));
		int hr, mi;
		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			hr = (s[0]-'0')*10 + s[1] - '0';
			mi = (s[3]-'0')*10 + s[4] - '0';
			int time = (hr - 0)*60 + mi;
			while (time <= LEN) {
				++ring[time];
				time += t;
			}
		}
		int tot = 0, i = 0;
		for (; i <= LEN; ++i) {
			tot += ring[i];
			if (tot >= m) break;
		}
		hr = i / 60, mi = i % 60;
		if (hr < 10) cout << "0" << hr << ":";
		else cout << hr << ":";
		if (mi < 10) cout << "0" << mi << "\n";
		else cout << mi << "\n";
	}
	return 0;
}
