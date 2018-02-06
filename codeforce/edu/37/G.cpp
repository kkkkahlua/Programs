#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int f[210], a[10], b[210], cnt;
void init(int p) {
    cnt = 0;
    for (int i = 2; i * i <= p; ++i) {
        if (!(p % i)) {
            a[cnt++] = i;
            while (!(p % i)) p /= i;
        }
    }
    if (p != 1) a[cnt++] = p;
    for (int i = 1; i < (1<<cnt); ++i) {
        b[i] = 1;
        for (int j = 0; j < cnt; ++j) if (i & (1<<j)) b[i] *= a[j];
    }
}
int get(int x) {
    int ret = 0;
    for (int i = 1; i < (1<<cnt); ++i) ret += f[i] * (x/b[i]);
    return x-ret;
}
void work() {
    int x, p, k, ans;
    scanf("%d%d%d", &x,&p,&k);
    init(p);
    int l = x+1, r = 1000000000, num = get(x);
    while (l<=r) {
        int mid = l+r>>1;
        if (get(mid)-num >= k) ans = mid, r = mid-1;
        else l = mid+1;
    }
    printf("%d\n", ans);
}
int main() {
    freopen("in.txt", "r", stdin);
    f[0] = -1;
    for (int i = 1; i < 128; ++i) f[i] = -f[i^(i&-i)];
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
