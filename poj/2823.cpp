#include <cstdio>
#define maxn 1000010
int qs[maxn], qb[maxn], a[maxn], ans1[maxn], ans2[maxn], n, k;
void work() {
    int f1 = 0, r1 = 0, f2 = 0, r2 = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (r1 > f1 && i - qs[f1] >= k) ++f1;
        if (r2 > f2 && i - qb[f2] >= k) ++f2;
        while (r1 > f1 && a[i] <= a[qs[r1 - 1]]) --r1; qs[r1++] = i;
        while (r2 > f2 && a[i] >= a[qb[r2 - 1]]) --r2; qb[r2++] = i;
        ans1[i] = a[qs[f1]]; ans2[i] = a[qb[f2]];
    }
    printf("%d", ans1[k - 1]); for (int i = k; i < n; ++i) printf(" %d", ans1[i]); printf("\n");
    printf("%d", ans2[k - 1]); for (int i = k; i < n; ++i) printf(" %d", ans2[i]); printf("\n");
}
int main() {
    while (scanf("%d%d", &n, &k) != EOF) work();
    return 0;
}
