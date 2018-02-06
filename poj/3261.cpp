#include <cstdio>
#include <vector>
#include <iostream>
#define maxn 1000000
#define maxm maxn + 10
#define maxd 20010
using namespace std;
typedef long long LL;
int wa[maxm], wb[maxm], wv[maxm], wt[maxm], r[maxd], rk[maxd], sa[maxd], n, m, k, h[maxd], a[maxn];
vector<int> v[maxd];
bool cmp(int* r, int a, int b, int l) { return r[a] == r[b] && r[a+l] == r[b+l]; }
void init(int* r, int* sa, int n, int m) {
    int* x=wa, *y=wb, *t, i, j, p;
    for (i = 0; i < m; ++i) wt[i] = 0;
    for (i = 0; i < n; ++i) ++wt[x[i] = r[i]];
    for (i = 1; i < m; ++i) wt[i] += wt[i - 1];
    for (i = n-1; i >= 0; --i) sa[--wt[x[i]]] = i;

    for (j = p = 1; p < n; j <<= 1, m = p) {
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
    for (i = 0; i < n; h[rk[i++]] = k) {
        for (k = k ? --k : 0, j = sa[rk[i] - 1]; r[i+k] == r[j+k]; ++k);
    }
}
bool check(int x) {
    int cnt = -1;
    for (int i = 1; i < n; ++i) {
        if (h[i] < x) v[++cnt].clear();
        v[cnt].push_back(h[i]);
    }
    for (int i = 0; i <= cnt; ++i) if (v[i].size() >= k) return true;
    return false;
}
int main() {
    freopen("in.txt", "r", stdin);
    int m = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        m = max(m, a[i]);
    }
    r[n++] = 0;
    init(a, sa, n, ++m);
    int le = 1, ri = n - 1;
    while (ri - le > 1) {
        int mid = le + ri >> 1;
        if (check(mid)) le = mid;
        else ri = mid - 1;
    }
    if (check(ri)) printf("%d\n", ri);
    else printf("%d\n", le);
    return 0;
}
