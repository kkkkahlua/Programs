#include <bits/stdc++.h>
#define maxn 10000010
unsigned x, y, z, rat[maxn], ans[maxn], A, B, C;
int n, m, b[110], id[110], kas;
using namespace std;
unsigned rng61() {
    unsigned t;
    x ^= x << 16;
    x ^= x >> 5;
    x ^= x << 1;
    t = x;
    x = y;
    y = z;
    z = t ^ x ^ y;
    return z;
}
bool cmp(int u, int v) { return b[u] > b[v]; }
void work() {
    x = A; y = B; z = C;
    for (int i = 0; i < n; ++i) rat[i] = rng61();
    for (int i = 0; i < m; ++i) { scanf("%d", &b[i]); id[i] = i; }
    sort(id, id + m, cmp);
    int en = n;
    for (int i = 0; i < m; ++i) {
        if (i > 0 && b[id[i]] == b[id[i - 1]]) {
            ans[id[i]] = ans[id[i - 1]];
            continue;
        }
        nth_element(rat, rat + b[id[i]], rat + en);
        ans[id[i]] = rat[b[id[i]]];
        en = b[id[i]];
    }
    printf("Case #%d: %u", ++kas, ans[0]);
    for (int i = 1; i < m; ++i) printf(" %u", ans[i]); printf("\n");
}
int main() {
    freopen("多校联合训练第一场标程及数据-复件/数据/1008.in", "r", stdin);
    freopen("08.out", "w", stdout);
//    freopen("in.txt", "r", stdin);
    while (scanf("%d%d%u%u%u", &n, &m, &A, &B, &C) != EOF) work();
    return 0;
}
