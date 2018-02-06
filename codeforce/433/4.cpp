#include <bits/stdc++.h>
#define maxn 300010
using namespace std;
typedef long long LL;
struct node1 {
    int x, y;
    bool operator < (const node& nd) const { return x > nd.x; }
};
struct node2 {
    int x, y;
    bool operator < (const node& nd) const { return x < nd.x; }
};
set<node> a, b;
int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d%I64d", &d[i], &f[i], &t[i], &c[i]);
        if (de[f[i]] != 0 && c[i] > de[f[i]]) continue;
        if (ar[t[i]] != 0 && c[i] > ar[t[i]]) continue;
        de[f[i]] = c[i], ar[t[i]] = c[i];

        a[f[i]].insert(node2(d[i], c[i]));
        b[t[i]].insert(node1(d[i], c[i]));
    }
    bool flag = false;
    for (int i = 1; i <= n; ++i) {
        if (!de[i] || !ar[i]) {
            flag = true;
            break;
        }
    }
    if (flag) printf("-1\n");
    else {
        for (int i = 1; i <= n; ++i) {
            for (auto nd : a[i]) {
                while (tot > 0 && nd.y < q1[tot-1].y) --tot;
                q1[tot++] = nd;
            }
        }
        for (int )
    }
    return 0;
}
