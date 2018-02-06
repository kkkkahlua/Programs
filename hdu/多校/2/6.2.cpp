#include <cstdio>
typedef long long LL;
const LL mod = 1e9 + 7;
struct Matrix {
    LL a[2][2];
    Matrix(LL b = 0, LL c = 0, LL d = 0, LL e = 0) : a{b, c, d, e} {}
    Matrix operator * (const Matrix& temp) const {
        Matrix ret;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    ret.a[i][j] += a[i][k] * temp.a[k][j] % mod;
                    ret.a[i][j] %= mod;
                }
            }
        }
        return ret;
    }
    Matrix operator - (const Matrix& temp) const {
        Matrix ret;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                ret.a[i][j] = a[i][j] - temp.a[i][j];
                ret.a[i][j] %= mod;
            }
        }
        return ret;
    }
};
Matrix poww(Matrix temp, LL n) {
    Matrix ret(1, 0, 0, 1);
    while (n) {
        if (n & 1) ret = ret * temp;
        temp = temp * temp;
        n >>= 1;
    }
    return ret;
}
void work() {
    LL n, m;
    scanf("%lld%lld", &n, &m);
    Matrix temp = poww(Matrix(1, 2, 1, 0), n);
//    printf("%lld %lld\n%lld %lld\n", temp.a[0][0], temp.a[0][1], temp.a[1][0], temp.a[1][1]);
    Matrix ans(0, 0, 0, 0);
    if (n & 1) ans = poww(temp - Matrix(0, 2, 1, -1), m - 1);
    else ans = poww(temp - Matrix(1, 0, 0, 1), m - 1);
    LL anss = ans.a[1][0] + ans.a[1][1]; anss %= mod;
    printf("%lld\n", anss);
}
int main() {
    freopen("多校联合第二场数据和标程/数据/1006.in", "r", stdin);
    freopen("06.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
