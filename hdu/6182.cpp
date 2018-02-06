#include <bits/stdc++.h>
#define maxn 15
typedef long long LL;
using namespace std;
vector<LL> v;
LL poww(LL a, LL b) {
    LL ret = 1;
    while (b) {
        if (b & 1) ret *= a;
        a *= a;
        b >>= 1;
    }
    return ret;
}
void init() {
    for (LL i = 1; i <= maxn; ++i) {
        v.push_back(poww(i, i));
    }
}
LL n;
void work() {
    printf("%d\n", upper_bound(v.begin(), v.end(), n)-v.begin());
}
int main() {
    init();
    while (scanf("%lld", &n) != EOF) work();
    return 0;
}
