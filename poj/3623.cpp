#include <stdio.h>
#include <iostream>
#define maxn 60010
using namespace std;
typedef long long LL;
int a[maxn], wa[maxn], wb[maxn], wv[maxn], wt[maxn], h[maxn], rk[maxn], sa[maxn], n, r[maxn];
char s[maxn], ans[maxn];
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
}
inline void read(char &x) {
    char ch;
    while (ch=getchar(),ch>'Z' || ch<'A') ;
    x=ch;
}
int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    int m = 0;
    for (int i = 0; i < n; ++i) {
        read(s[i]);
        r[2*n-1-i] = r[i] = s[i];
        m = max(r[i], m);
    }
    int tot = n << 1;
    r[tot++] = 0;
    init(r, sa, tot, ++m);
    int l = 0, r = n-1, cnt=0;
    while (l < r) {
        if (rk[l] > rk[2*n-1-r]) ans[cnt++] = s[r--];
        else ans[cnt++] = s[l++];
    }
    ans[cnt++] = s[l];
    for (int i = 0; i < cnt; ++i) {
        if (i && i % 80==0) puts("");
        putchar(ans[i]);
    }
    return 0;
}
