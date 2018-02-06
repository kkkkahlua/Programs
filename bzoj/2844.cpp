#include <bits/stdc++.h>
#define mod 10086
#define maxl 30
using namespace std;
typedef long long LL;
LL poww(LL a, LL b) {
    LL ret = 1;
    while (b) {
        if (b & 1) (ret *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return ret;
}
struct LinearBasis {
    LL a[maxl+1]; int size; vector<int> v;
    LinearBasis() { memset(a, 0, sizeof(a)); size = 0; v.clear(); }
    void insert(LL t) {
        for (int i = maxl; i >= 0; --i) {
            if (!(t >> i & 1)) continue;
            if (a[i]) t ^= a[i];
            else {
                ++size;
                for (int j = 0; j < i; ++j) if (t >> j & 1) t ^= a[j];
                for (int j = i+1; j <= maxl; ++j) if (a[j] >> i & 1) a[j] ^= t;
                a[i] = t;
                return;
            }
        }
    }
    void basis() {
        for (int i = 0; i <= maxl; ++i) if (a[i]) v.push_back(i);
    }
    LL rank(LL x) {
        LL ret = 0;
        for (int i = 0; i < v.size(); ++i) if (x >> v[i] & 1) ret += 1LL << i;
        return ret;
    }
};
int main() {
//    freopen("in.txt", "r", stdin);
    int n, x, q;
    scanf("%d", &n);
    LinearBasis lb;
    for (int i = 0; i < n; ++i) scanf("%d", &x), lb.insert(x);
    lb.basis();
    scanf("%d", &q);
    LL num = poww(2, n - lb.size);
    printf("%lld\n", (lb.rank(q) % mod * num % mod + 1) % mod);
    return 0;
}
