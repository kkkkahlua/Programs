#include <bits/stdc++.h>
#define maxn 300010
using namespace std;
int n, k, a[maxn], d[maxn];
bool check(int x) {
    int last = 0;
    for (int i = k; i <= n; ++i) {
        int j = d[i-k];
        if (a[i] - a[j+1] <= x) last = i;
        d[i] = last;
    }
    return d[n] == n;
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    sort(a+1, a+1+n);

    int l = 0, r = a[n] - a[1];
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid+1;
    }
    printf("%d\n", l);
    return 0;
}
