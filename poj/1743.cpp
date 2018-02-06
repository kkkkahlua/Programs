#include <cstdio>
#include <iostream>
#define maxn 200100
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;
int a[maxn], b[maxn], wa[maxn], wb[maxn], rk[maxn], h[maxn], sa[maxn], wt[maxn], wv[maxn], n;
bool cmp(int* r, int a, int b, int l) { return r[a] == r[b] && r[a+l] == r[b+l]; }
void init(int* r, int* sa, int n, int m) {
    int* x = wa, *y = wb, *t, i, j, k=0, p;

    for (i = 0; i < m; ++i) wt[i] = 0;
    for (i = 0; i < n; ++i) ++wt[x[i] = r[i]];
    for (i = 1; i < m; ++i) wt[i] += wt[i-1];
    for (i = n-1; i >= 0; --i) sa[--wt[x[i]]] = i;

    for (j = 1, p = 1; p < n; j <<= 1, m = p) {
        for (i = n-j, p = 0; i < n; ++i) y[p++] = i;
        for (i = 0; i < n; ++i) if (sa[i] >= j) y[p++] = sa[i] - j;

        for (i = 0; i < n; ++i) wv[i] = x[y[i]];

        for (i = 0; i < m; ++i) wt[i] = 0;
        for (i = 0; i < n; ++i) ++wt[wv[i]];
        for (i = 1; i < m; ++i) wt[i] += wt[i-1];
        for (i = n-1; i >= 0; --i) sa[--wt[wv[i]]] = y[i];

        t = x, x = y, y = t, x[sa[0]] = 0;
        for (i = 1, p = 1; i < n; ++i) x[sa[i]] = cmp(y, sa[i], sa[i-1], j) ? p-1 : p++;
    }
    for (i = 0; i < n; ++i) rk[sa[i]] = i;
    for (i = 0; i < n-1; h[rk[i++]] = k) {
        for (k = k ? k-1 : 0, j = sa[rk[i]-1]; r[i+k] == r[j+k]; ++k);
    }
}
bool check(int k) {
    int minn = inf, maxx = 0;
    for (int i = 1; i < n; ++i) {
        if (h[i] < k) minn = inf, maxx = 0;
        minn = min(minn, sa[i]), maxx = max(maxx, sa[i]);
        if (maxx - minn >= k+1) return true;
    }
    return false;
}
void work() {
    int m = 0;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    if (n < 10) { printf("0\n"); return; }
    for (int i = 0; i < n-1; ++i) b[i] = a[i+1] - a[i] + 88, m = max(b[i], m);
    b[n-1] = 0;
    init(b, sa, n, ++m);
    int le = 0, ri = n >> 1;
    while (ri - le > 1) {
        int mid = le + ri >> 1;
        if (check(mid)) le = mid;
        else ri = mid - 1;
    }
    int ans;
    if (check(ri)) ans = ri;
    else ans = le;
    if (ans >= 4) printf("%d\n", ans+1);
    else printf("0\n");
}
int main() {
    freopen("in.txt", "r", stdin);
    while (scanf("%d", &n) != EOF && n) work();
    return 0;
}
