#include <bits/stdc++.h>
#define N 210
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;
map<int, int> mp;
int cnt;
struct Matrix {
    LL mat[N][N];
    Matrix() { for (int i = 1; i <= cnt; ++i) for (int j = 1; j <= cnt; ++j) mat[i][j] = inf; }
    void init(LL x){
        memset(mat, 0, sizeof(mat));
    }
    void print() const {
        for (int i = 1; i <= cnt; ++i) {
            for (int j = 1; j <= cnt; ++j) printf("%lld ", mat[i][j]); printf("\n");
        }
    }
};
Matrix mulm(const Matrix& a, const Matrix& b) {
    Matrix temp;
    for (int i = 1; i <= cnt; ++i) {
        for (int j = 1; j <= cnt; ++j) {
            for (int k = 1; k <= cnt; ++k) {
                if (k==i||k==j) continue;
                temp.mat[i][j] = min(temp.mat[i][j], a.mat[i][k]+b.mat[k][j]);
            }
        }
    }
    return temp;
}
Matrix d;
Matrix poww(LL n) {
    Matrix a = d, ret = d;
    --n;
    while (n) {
        if (n & 1) ret = mulm(ret, a);
        a = mulm(a, a);
        n >>= 1;
//        ret.print();
    }
    return ret;
}
int main() {
    freopen("in.txt", "r", stdin);
    int n, t, s, e;
    scanf("%d%d%d%d", &n, &t, &s, &e);
    for (int i = 0; i < t; ++i) {
        int l, x, y;
        scanf("%d%d%d", &l, &x, &y);
        if (!mp[x]) mp[x] = ++cnt;
        if (!mp[y]) mp[y] = ++cnt;
        d.mat[mp[x]][mp[y]] = d.mat[mp[y]][mp[x]] = l;
    }
//    d.print();
    printf("%d\n", poww(n).mat[mp[s]][mp[e]]);
    return 0;
}
