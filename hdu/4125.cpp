#include <bits/stdc++.h>
#define maxn 600010
using namespace std;
typedef long long LL;
int id[maxn], ch[maxn][2], tot, a[maxn], f[7010], c[maxn], n, len, top, st[maxn];
char s[maxn * 3], P[7010];
bool vis[maxn];
void getfail() {
    int m = strlen(P);
    f[0] = f[1] = 0;
    for (int i = 1; i < m; ++i) {
        int j = f[i];
        while (j && P[j] != P[i]) j = f[j];
        f[i+1] = P[i] == P[j] ? j+1 : 0;
    }
}
int kmp() {
    int j = 0, l = len, m = strlen(P), cnt = 0;
    for (int i = 0; i < l; ++i) {
        while (j && s[i] != P[j]) j = f[j];
        if (s[i] == P[j]) ++j;
        if (j == m) ++cnt, j = f[j];
    }
    return cnt;
}
int kas;
void init() {
    memset(c, 0, sizeof(c));
    memset(ch, 0, sizeof ch);
}
int lowbit(int x) { return x & -x; }
void add(int x) { while (x <= n) ++c[x], x += lowbit(x); }
int sum(int x) { int ret = 0; while (x) ret += c[x], x -= lowbit(x); return ret; }
int query(int k) {
    int l = 1, r = n;
    while (r > l) {
        int mid = l + r >> 1;
        if (sum(mid) >= k) r = mid;
        else l = mid+1;
    }
    return l;
}
void insert(int x, int n) {
    add(x);
    int k = sum(x), l, r;
    if (k == 1) l = query(k+1), ch[l][0] = x;
    else if (k == n) r = query(k-1), ch[r][1] = x;
    else {
        l = query(k+1), r = query(k-1);
        if (!ch[r][1]) ch[r][1] = x;
        else ch[l][0] = x;
    }
}
void dfs(int u) {
    memset(vis, 0, sizeof(vis)); top = len = 0;
    st[top++] = u;
    while (top > 0) {
        int v = st[top-1];
        s[len++] = v & 1 ? '1' : '0';
        if (ch[v][0] && !vis[ch[v][0]]) { st[top++] = ch[v][0], vis[ch[v][0]] = true; continue; }
        if (ch[v][1] && !vis[ch[v][1]]) { st[top++] = ch[v][1], vis[ch[v][1]] = true; continue; }
        --top;
    }
}
void work() {
    init();
    int x;
    scanf("%d", &n);
    scanf("%d", &x);
    add(x); int rt = x;
    for (int i = 2; i <= n; ++i) scanf("%d", &x), insert(x, i);

    dfs(rt);
    scanf("%s", P);
    getfail();
    printf("Case #%d: %d\n", ++kas, kmp());
}
int main() {
    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
