#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 500010
using namespace std;
typedef long long LL;
struct node {
    int val, p;
    bool operator < (const node& nd) const { return val < nd.val; }
}a[maxn];
int b[maxn], c[maxn], n;
inline int lowbit(int x) { return x & (-x); }
int query(int x) {
    int ret = 0;
    while (x) {
        ret += c[x];
        x -= lowbit(x);
    }
    return ret;
}
void add(int x) {
    while (x <= n) {
//        printf("%d\n", x);
        ++c[x];
        x += lowbit(x);
    }
}
void work() {
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; ++i) { scanf("%d", &a[i].val); a[i].p = i; }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) b[a[i].p] = i;
    LL sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i - 1 - query(b[i]);
        add(b[i]);
    }
    printf("%lld\n", sum);
}
int main() {
    freopen("in.txt", "r", stdin);
    while (scanf("%d", &n) != EOF && n) work();
    return 0;
}
