//A

#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 1000000007
int n, k;
typedef long long LL;
using namespace std;
LL pow(int i, int k) {
	LL ret = 1;
	for (int cnt = 0; cnt < k; ++cnt) {
		ret = ((LL)i * ret) % MAX;
	}
	return ret;
}
void work() {
	LL sum = 0;
	for (int i = 1; i <= n; ++i) {
		sum = (sum + pow(i, k)) % (LL)MAX;
//		cout << sum << endl;
	}
	printf("%I64d\n", sum);
}
int main() {
	int T;
	scanf("%d", &T);
	while (scanf("%d%d", &n, &k) != EOF) work();
	return 0;
}
