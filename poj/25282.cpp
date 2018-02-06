#include <stdio.h>
#include <algorithm>
#include <map>
#define lson rt<<1
#define rson rt<<1|1
#define maxn 100010
using namespace std;
typedef long long LL;
int a[maxn], l[maxn], r[maxn], b[maxn];
struct tree { int l, r; bool cov, flag; }tr[maxn*4];
map<int,int> mp;
void build(int rt, int l, int r) {
    tr[rt].l = l, tr[rt].r = r; tr[rt].cov = 0; tr[rt].flag = 0;
    if (l==r) return;
    int mid = l+r >> 1;
    build(lson, l, mid), build(rson, mid+1, r);
}
void push_down(int rt) {
    if (tr[rt].flag) {
        tr[lson].cov = tr[rson].cov = tr[lson].flag = tr[rson].flag = 1;
        tr[rt].flag = 0;
    }
}
void push_up(int rt) {
    tr[rt].cov = tr[lson].cov && tr[rson].cov;
}
bool insert(int rt, int l, int r) {
    if (tr[rt].l==l && tr[rt].r==r) {
        if (tr[rt].cov) return true;
        tr[rt].cov = tr[rt].flag = true;
        return false;
    }
    push_down(rt);
    int mid = tr[rt].l + tr[rt].r >> 1;
    bool ret;
    if (r <= mid) ret = insert(lson, l, r);
    else if (l > mid) ret = insert(rson, l, r);
    else {
        bool ans1 = insert(lson, l, mid), ans2 = insert(rson, mid+1, r);
        ret = ans1&ans2;
    }
    push_up(rt);
    return ret;
}
void work() {
    int n;
    scanf("%d", &n);
    int tot=0;
    for (int i = 0; i < n; ++i) {
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
    int ans=0;
    for (int i = n-1; i >= 0; --i) {
        int pl = lower_bound(b+1, b+1+cnt, l[i]) - b,
            pr = lower_bound(b+1, b+1+cnt, r[i]) - b;
        if (!insert(1, pl, pr)) ++ans;
    }
    printf("%d\n", ans);
}
int main() {
    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
