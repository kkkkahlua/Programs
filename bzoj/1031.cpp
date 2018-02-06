#include <bits/stdc++.h>
#define maxn 200010
using namespace std;
typedef long long LL;
int a[maxn], wa[maxn], wb[maxn], wv[maxn], wt[maxn], h[maxn], rk[maxn], sa[maxn], n, r[maxn];
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
}
int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%s", s);
    int m=0, len=strlen(s);
    for (int i = 0; i < len; ++i) r[i] = r[len+i] = s[i], m = max(r[i], m);
    int tot = len<<1; r[tot++] = 0;
    init(r, sa, tot, ++m);
    for (int i = 1; i < tot; ++i) {
        if (sa[i] < len) printf("%c", s[(sa[i]+len-1)%len]);
    }
    puts("");
    return 0;
}
