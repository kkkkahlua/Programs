#include <bits/stdc++.h>
#define maxn 200010
#define lson (rt<<1)
#define rson (lson|1)
using namespace std;
typedef long long LL;
struct node { int l, r; bool flag; }tr[maxn<<2];
char s[maxn];
int a[maxn];
void build(int rt, int l, int r) {
    tr[rt].l = l, tr[rt].r = r;
    if (l == r) {
        tr[rt].flag = s[l] == '1'; return;
    }
    int mid = l+r>>1;
    build(lson, l, mid); build(rson, mid+1, r);
    tr[rt].flag = tr[lson].flag & tr[rson].flag;
}
bool query(int rt, int l, int r) {
//    printf("%d %d %d\n", rt,l,r);
    if (tr[rt].l==l&&tr[rt].r==r) return tr[rt].flag;
    int mid = tr[rt].l+tr[rt].r >> 1;
    if (r <= mid) return query(lson, l, r);
    else if (l > mid) return query(rson, l, r);
    else return query(lson, l, mid) & query(rson, mid+1, r);
}
int main() {
//    freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    scanf("%s", s+1);
    build(1, 1, n);
    for (int i = 1; i <= n; ++i) {
        if (i == a[i]) continue;
        if (i < a[i] && !query(1, i, a[i]-1)) { puts("NO"); return 0; }
        else if (i > a[i] && !query(1, a[i], i-1)) { puts("NO"); return 0; }
    }
    puts("YES");
    return 0;
}
