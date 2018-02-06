#include <cstdio>
#include <iostream>
#define maxn 100010
using namespace std;
int a[maxn], n, m, k, hi[maxn], lo[maxn];
void work() {
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int l = 0, t1 = 0, t2 = 0, s1 = 0, s2 = 0, len = 0;
    lo[t1++] = hi[t2++] = 0;
    for (int i = 1; i < n; ++i) {
        while (t1 > s1 && a[i] < a[lo[t1 - 1]]) --t1;
        lo[t1++] = i;
        while (t2 > s2 && a[i] > a[hi[t2 - 1]]) --t2;
        hi[t2++] = i;
        while (a[hi[s2]] - a[lo[s1]] > k) {
            l = min(hi[s2], lo[s1]) + 1;
            while (lo[s1] < l) ++s1;
            while (hi[s2] < l) ++s2;
        }
        if (a[hi[s2]] - a[lo[s1]] >= m && a[hi[s2]] - a[lo[s1]] <= k) len = max(len, i - l + 1);
//        for (int j = s1; j < t1; ++j) printf("%d ", a[lo[j]]); printf("\n");
//        for (int j = s2; j < t2; ++j) printf("%d ", a[hi[j]]); printf("\n");

    }
    printf("%d\n", len);
}
int main() {
    freopen("3530.in", "r", stdin);
    while (scanf("%d%d%d", &n, &m, &k) != EOF) work();
    return 0;
}
