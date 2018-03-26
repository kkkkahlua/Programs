#include <bits/stdc++.h>
#define maxn 500010
using namespace std;
typedef long long LL;
int wa[maxn], wb[maxn], wv[maxn], wt[maxn], h[maxn], rk[maxn], sa[maxn], n, r[maxn], l[maxn], st[maxn];
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
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    scanf("%s", s);
    int tot=0, m=0, len=strlen(s);
    for (int i = 0; i < len; ++i) m = max(r[tot++] = s[i], m); r[tot++] = 0;
    init(r, sa, tot, ++m);
    int top=0;
    LL ans = 1LL * (len+1) * len / 2 * (len-1);
    h[tot] = -1;
    for (int i = 2; i <= tot; ++i) {
        int ll = i;
        while (top && h[i]<h[st[top-1]]) {
            --top;
            ans -= 1LL * h[st[top]] * (i-st[top]) * (st[top]-(ll=l[st[top]])+1) * 2;
        }
        st[top++] = i; l[i] = ll;
    }
    printf("%lld\n", ans);
    return 0;
}
