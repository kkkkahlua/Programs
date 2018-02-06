//A

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n, m, a[100010];
void work() {
	for (int i = 0; i < n-1; ++i) {
		scanf("%d", &a[i]);
	}
	if (n & 1) { printf("No\n"); return; }
	int cnt1, cnt2; cnt1 = cnt2 = 0;
	for (int i = n-2; i  >= 0; --i) {
		if (a[i] == 1) ++cnt1;
		else ++cnt2;
		if (cnt2 > cnt1) {
			printf("No\n"); return;
		}
	}
	printf("Yes\n");
}
int main() {
	int T;
	scanf("%d", &T);
	while (scanf("%d", &n) != EOF) work();
	return 0;
}
