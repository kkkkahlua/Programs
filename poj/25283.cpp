#include <stdio.h>
#include <algorithm>
#include <string.h>
#define lson rt<<1
#define rson rt<<1|1
#define maxn 100010
using namespace std;
typedef long long LL;
int a[maxn], l[maxn], r[maxn], b[maxn], ans;
bool vis[maxn];
struct tree { int l, r, c, flag; }tr[maxn*4];
void build(int rt, int l, int r) {
    tr[rt].l = l, tr[rt].r = r; tr[rt].flag = tr[rt].c = 0;
    if (l==r) return;
    int mid = l+r >> 1;
    build(lson, l, mid), build(rson, mid+1, r);
}
void push_down(int rt) {
    if (tr[rt].flag) {
        tr[lson].flag = tr[rson].flag
            = tr[lson].c = tr[rson].c = tr[rt].flag;
        tr[rt].flag = 0;
    }
}
void push_up(int rt) {
    tr[rt].c = tr[lson].c == tr[rson].c ? tr[lson].c : 0;
}
void modify(int rt, int l, int r, int c) {
    if (tr[rt].l == l && tr[rt].r == r) {
        tr[rt].c = tr[rt].flag = c;
        return;
    }
    push_down(rt);
    int mid = tr[rt].l + tr[rt].r >> 1;
    if (r <= mid) modify(lson, l, r, c);
    else if (l > mid) modify(rson, l, r, c);
    else modify(lson, l, mid, c), modify(rson, mid+1, r, c);
    push_up(rt);
}
void query(int rt) {
    if (tr[rt].l == tr[rt].r || tr[rt].c) {
        if (!vis[tr[rt].c] && tr[rt].c) ++ans, vis[tr[rt].c] = true;
        return;
    }
    push_down(rt);
    query(lson); query(rson);
}
void work() {
    int n;
    scanf("%d", &n);
    int tot=0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &l[i], &r[i]);
        a[++tot] = l[i], a[++tot] = r[i];
    }
    sort(a+1,a+tot+1);
    tot = unique(a+1,a+tot+1)-a-1;

    b[1] = a[1]; int cnt = 1;
    for (int i = 2; i <= tot; ++i) {
        if (a[i]-a[i-1] == 1) b[++cnt] = a[i];
        else b[++cnt] = a[i-1] + 1, b[++cnt] = a[i];
    }

    build(1,1,cnt);
    for (int i = 1; i <= n; ++i) {
        int pl = lower_bound(b+1, b+1+cnt, l[i]) - b,
            pr = lower_bound(b+1, b+1+cnt, r[i]) - b;
        modify(1, pl, pr, i);
    }

    ans = 0; memset(vis, 0, sizeof(vis));
    query(1);
    printf("%d\n", ans);
}
int main() {
    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
/*
1
2
2999999 3499996
3499998 3999997
*/
