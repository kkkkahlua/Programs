#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
typedef long long LL;
int n, A, B;
int a[maxn];
bool check(LL k) {
    LL base = k * B, diff = A - B, sum = 0;
    for (int i = n-1; i >= 0; --i) {
        if (a[i] <= base) continue;
        sum += ceil(1.0 * (a[i] - base) / diff);
    }
    return sum <= k;
}
int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%d%d%d", &n, &A, &B);
    LL ri = 0;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]), ri += a[i]/B+1;
    sort(a, a+n);

    LL le = 1;
    while (ri > le) {
        LL mid = le + ri >> 1;
        if (check(mid)) ri = mid;
        else le = mid + 1;
    }
    printf("%lld\n", le);
    return 0;
}
