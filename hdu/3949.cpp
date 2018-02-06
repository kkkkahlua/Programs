#include <bits/stdc++.h>
#define maxl 60
#define LL long long
using namespace std;
struct LinearBasis {
    LL a[maxl+1]; bool rel; int sz;
    vector<LL> v;
    LinearBasis() { memset(a, 0, sizeof a); rel = false; sz = 0; v.clear();}
    void insert(LL t) {
        for (int i = maxl; i >= 0; --i) {
            if (!(t >> i & 1)) continue;
            if (a[i]) t ^= a[i];
            else {
                for (int j = 0; j < i; ++j) if (t >> j & 1) t ^= a[j];
                for (int j = i+1; j <= maxl; ++j) if (a[j] >> i & 1) a[j] ^= t;
                a[i] = t, ++sz;
                return;
            }
        }
        rel = true;
    }
    void basis() {
        for (int i = 0; i <= maxl; ++i) if (a[i]) v.push_back(a[i]);
    }
    LL kth(LL x) {
        LL ret = 0;
        for (int i = 0; i < v.size(); ++i) if (x >> i & 1) ret ^= v[i];
        return ret;
    }
};
int kas;
void work() {
    int n, q; LL x;
    scanf("%d", &n);
    LinearBasis lb;
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &x);
        lb.insert(x);
    }
    lb.basis();

    scanf("%d", &q);
    printf("Case #%d:\n", ++kas);

    LL tot = (1LL << lb.sz) - 1;
    for (int i = 0; i < q; ++i) {
        scanf("%lld", &x);
        if (lb.rel) --x;
        if (x > tot) puts("-1");
        else printf("%lld\n", lb.kth(x));
    }
}
int main() {
//    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
