#include <bits/stdc++.h>
#define maxn 400010
using namespace std;
typedef long long LL;
LL ans, cnt1, cnt2;
int sum[maxn*10], ls[maxn*10], rs[maxn*10], root[maxn], v[maxn], sz, seg, l[maxn], r[maxn];
void read(int x) {
    scanf("%d", &v[x]);
    if (v[x]) return;
    l[x] = ++sz;
    read(l[x]);
    r[x] = ++sz;
    read(r[x]);
}
void push_up(int k) { sum[k] = sum[ls[k]] + sum[rs[k]]; }
void build(int& k, int l, int r, int val) {
    if (!k) k = ++seg;
    if (l == r) { ++sum[k]; return; }
    int mid = l + r >> 1;
    if (val <= mid) build(ls[k], l, mid, val);
    else build(rs[k], mid+1, r, val);
    push_up(k);
}
int merge(int x, int y) {
    if (!x) return y;
    if (!y) return x;
    cnt1 += 1LL * sum[ls[x]] * sum[rs[y]];
    cnt2 += 1LL * sum[rs[x]] * sum[ls[y]];
    ls[x] = merge(ls[x], ls[y]);
    rs[x] = merge(rs[x], rs[y]);
    push_up(x);
    return x;
}
void solve(int k) {
    if (!k) return;
    solve(l[k]), solve(r[k]);
    if (root[k]) return;
    cnt1 = cnt2 = 0;
    root[k] = merge(root[l[k]], root[r[k]]);
    ans += min(cnt1, cnt2);
}
void print(int x) {
    if (!x) return;
    printf("%d\n", x);
    print(l[x]), print(r[x]);
}
int main() {
    freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    read(++sz);
    for (int i = 1; i <= sz; ++i) {
        if (v[i]) build(root[i], 1, n, v[i]);
    }
    solve(1);
    printf("%lld\n", ans);
    return 0;
}
