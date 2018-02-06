//A

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
bool ac[15];
int a[15];
int n, m;
int time(char* s) {
	int hr = s[1] - '0';
	int min = (s[3] - '0') * 10 + s[4] - '0';
	return hr * 60 + min;
}
void work() {
	memset(ac, 0, sizeof(ac));
	memset(a, 0, sizeof(a));
	int pen = 0, tot = 0;
	for (int i = 0; i < m; ++i) {
		int id; char s1[10], s2[10];
		scanf("%d%s%s", &id, s1, s2);
		id -= 1000;
		if (ac[id]) continue;
		if (s2[0] == 'A') {
//			cout << a[id] << " ";
			int t = time(s1);
			a[id] += t;
			pen += a[id];
			ac[id] = true;
			++tot;
		}
		else {
			a[id] += 20;
		}
//		cout << pen << endl;
	}
	printf("%d %d\n", tot, pen);
}
int main() {
	int T;
	scanf("%d", &T);
	while (scanf("%d%d", &n, &m) != EOF) work();
	return 0;
}
