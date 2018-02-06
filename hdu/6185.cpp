#include <bits/stdc++.h>
typedef long long LL;
const LL mod = 1e9+7;
LL n;
struct Matrix {
    LL a[5][5];
    Matrix() { memset(a, 0, sizeof(a)); }
    Matrix operator * (const Matrix& m) {
        Matrix ret;
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                for (int k = 0; k < 5; ++k) {
                    (ret.a[i][j] += a[i][k] * m.a[k][j] % mod) %= mod;
                }
            }
        }
        return ret;
    }
}ans, mul;
Matrix poww(Matrix a, LL b) {
    Matrix ret = ans;
    while (b) {
        if (b & 1) ret = ret * a;
        a = a * a;
        b >>= 1;
    }
    return ret;
}
void work() {
    printf("%lld\n", poww(mul, n-1).a[0][0]);
}
int main() {
    ans.a[0][0] = ans.a[0][1] = ans.a[0][2] = 1, ans.a[0][3] = 2;
    mul.a[0][0] = mul.a[0][1] = mul.a[0][2] = 1, mul.a[0][3] = 2;
    mul.a[1][0] = mul.a[2][0] = mul.a[2][4] = 1;
    mul.a[3][0] = mul.a[3][3] = mul.a[4][2] = 1;
    while (scanf("%lld", &n) != EOF) work();
    return 0;
}
