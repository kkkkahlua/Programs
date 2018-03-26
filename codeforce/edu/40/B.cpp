#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i < (b); ++i)
#define F2(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i > (b); --i)
#define dF2(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 1010
using namespace std;
int wa[maxn], wb[maxn], wv[maxn], wt[maxn], h[maxn], rk[maxn], sa[maxn], n, m, tot, r[maxn];
char s[maxn];
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
    scanf("%d%s", &n, s);
    F(i, 0, n) m = max(r[tot++]=s[i], m); r[tot++] = 0;
    init(r, sa, tot, ++m);
    int p = rk[0], maxx = 0;
    dF2(i, p-1, 1) {
        if (h[i+1]>=sa[i] && (sa[i]<<1)<=n) maxx = max(maxx, sa[i]);
        h[i] = min(h[i], h[i+1]);
    }
    F(i, p+1, tot) {
        if (h[i]>=sa[i] && (sa[i]<<1)<=n) maxx = max(maxx, sa[i]);
        h[i+1] = min(h[i], h[i+1]);
    }
    printf("%d\n", maxx?n-maxx+1:n);
    return 0;
}
