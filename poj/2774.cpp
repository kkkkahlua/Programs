#include <stdio.h>
#include <iostream>
#include <string.h>
#define maxn 200010
using namespace std;
typedef long long LL;
int a[maxn], wa[maxn], wb[maxn], wv[maxn], wt[maxn], h[maxn], rk[maxn], sa[maxn], n, r[maxn];
char s1[maxn], s2[maxn];
bool cmp(int* r, int a, int b, int l) { return r[a] == r[b] && r[a+l] == r[b+l]; }
void init(int* r, int* sa, int n, int m) {
    int* x=wa, *y=wb, *t, i, j, p;
    for (i = 0; i < m; ++i) wt[i] = 0;
    for (i = 0; i < n; ++i) ++wt[x[i] = r[i]];
    for (i = 1; i < m; ++i) wt[i] += wt[i - 1];
    for (i = n-1; i >= 0; --i) sa[--wt[x[i]]] = i;

    for (j = 1, p = 1; p < n; j <<= 1, m = p) {
        for (p = 0, i = n-j; i < n; ++i) y[p++] = i;
        for (i = 0; i < n; ++i) if (sa[i] >= j) y[p++] = sa[i] - j;

        for (i = 0; i < n; ++i) wv[i] = x[y[i]];

        for (i = 0; i < m; ++i) wt[i] = 0;
        for (i = 0; i < n; ++i) ++wt[wv[i]];
        for (i = 1; i < m; ++i) wt[i] += wt[i - 1];
        for (i = n-1; i >= 0; --i) sa[--wt[wv[i]]] = y[i];

        t = x, x = y, y = t, x[sa[0]] = 0;
        for (p = 1, i = 1; i < n; ++i) x[sa[i]] = cmp(y, sa[i], sa[i-1], j) ? p - 1 : p++;
    }

    for (i = 0; i < n; ++i) rk[sa[i]] = i;
    int k = 0;
    for (i = 0; i < n - 1; h[rk[i++]] = k) {
        for (k = k ? --k : 0, j = sa[rk[i] - 1]; r[i+k] == r[j+k]; ++k);
    }
}
int main() {
    scanf("%s%s", s1, s2);
    int tot=0, m=0;
    for (int i = 0; s1[i]; ++i) m = max(r[tot++] = s1[i], m); r[tot++] = '#';
    for (int i = 0; s2[i]; ++i) m = max(r[tot++] = s2[i], m);
    r[tot++] = 0;
    init(r, sa, tot, ++m);
    int ans = 0, len = strlen(s1);
    for (int i = 2; i < tot; ++i) {
        if (h[i]>ans && ((sa[i]<len) && (sa[i-1]>len) || (sa[i]>len && sa[i-1]<len))) ans = h[i];
    }
    printf("%d\n", ans);
}
