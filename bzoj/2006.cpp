#include <bits/stdc++.h>
#define maxn 500010
using namespace std;
typedef long long LL;
int a[maxn], n;
LL pre[maxn];
struct node { LL x; int p; }mn[maxn][32];
struct qnode {
    int i, l, r, p; LL val;
    bool operator < (const qnode& nd) const {
        return val < nd.val;
    }
};
priority_queue<qnode> pq;
void rmqInit() {
    for (int i = 1; i <= n; ++i) mn[i][0] = {pre[i], i};
    for (int j = 1; (1 << j) <= n; ++j) {
        for (int i = 1; i + (1 << (j-1)) - 1 <= n; ++i) {
            mn[i][j] = mn[i][j-1].x < mn[i + (1<<(j-1))][j-1].x ? mn[i][j-1] : mn[i + (1<<(j-1))][j-1];
        }
    }
}
int query(int l, int r) {
    int k = (int)(log((double)r-l+1)/log((double)2));
    return mn[l][k].x < mn[r-(1<<k)+1][k].x ? mn[l][k].p : mn[r-(1<<k)+1][k].p;
}
int main() {
//    freopen("in.txt", "r", stdin);
    int k, l, r;
    scanf("%d%d%d%d", &n, &k, &l, &r);
    pre[1] = 0;
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), pre[i+1] = pre[i] + a[i];
    rmqInit();
    for (int i = l; i <= n; ++i) {
        int ll = max(1, i - r + 1), rr = i - l + 1,
            p = query(ll, rr);
        pq.push({i, ll, rr, p, pre[i+1] - pre[p]});
    }
    LL ans = 0;
    while (k--) {
        qnode qnd = pq.top(); pq.pop();
        ans += qnd.val;
        int l1 = qnd.l, r1 = qnd.p - 1,
            l2 = qnd.p + 1, r2 = qnd.r,
            i = qnd.i;
        if (l1 <= r1) {
            int p1 = query(l1, r1);
            pq.push({i, l1, r1, p1, pre[i+1] - pre[p1]});
        }
        if (l2 <= r2) {
            int p2 = query(l2, r2);
            pq.push({i, l2, r2, p2, pre[i+1] - pre[p2]});
        }
    }
    printf("%lld\n", ans);
    return 0;
}
