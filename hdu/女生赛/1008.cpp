//A

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 1e9 + 7;
typedef long long LL;
LL n;
struct Matrix {
	LL a[3][3];
	Matrix() { memset(a, 0, sizeof(a)); }
	Matrix operator * (const Matrix y) {
		Matrix ret;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				for (int k = 0; k < 3; ++k) {
					ret.a[i][j] = (ret.a[i][j] + ((LL)a[i][k] * y.a[k][j]) % MOD) % MOD;
				}
			}
		}
		return ret;
	}
	void operator = (const Matrix y) {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				a[i][j] = y.a[i][j];
			}
		}
	}
};

void work() {
	if (n == 2) { printf("%d\n", 3); return; }
	if (n == 3) { printf("%d\n", 4); return; }
	Matrix ans, mul;
	ans.a[0][0] = 6; ans.a[1][0] = 4; ans.a[2][0] = 3;
	mul.a[0][0] = mul.a[0][2] = mul.a[1][0] = mul.a[2][1] = 1;
	n -= 4;
	while (n) {
		if (n & 1) ans = mul * ans;
		mul = mul * mul;
		n >>= 1;
//		cout << n << endl;
	}
	printf("%I64d\n", ans.a[0][0] % MOD);
}
int main() {
	int T;
	scanf("%d", &T);
	while (scanf("%I64d", &n) != EOF) work();
	return 0;
}
