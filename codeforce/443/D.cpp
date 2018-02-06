#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
typedef long long LL;
struct node { int x, cnt; }b[maxn];
int main() {
//    freopen("in.txt", "r", stdin);
    LL n, m, k;
    scanf("%I64d%I64d%I64d", &n, &k, &m);
    int x = -1, cnt = 0, tot = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        if (a != x) {
            if (cnt) b[tot++] = {x, cnt};
            cnt = 1; x = a;
        }
        else {
            ++cnt;
            if (cnt == k) cnt = 0;
        }
    }
    if (cnt) b[tot++] = {x, cnt};

//    printf("%d\n", tot);
//    for (int i = 0; i < tot; ++i) printf("%d %d\n", b[i].x, b[i].cnt);

    int i = 0, j = tot-1;
    for (; i < j; ++i, --j) if (b[i].x != b[j].x || b[i].cnt + b[j].cnt != k) break;

//    printf("%d %d\n", i, j);

    LL ans;
    if (i > j) ans = (m&1) ? n : 0;
    else if (i == j) ans = 1LL * b[i].cnt * m % k;
    else {
        int num=0;
        for (int k = i; k <= j; ++k) num += b[k].cnt;
        ans = 1LL * num * m + i * k;
    }

    printf("%I64d\n", ans);

    return 0;
}
