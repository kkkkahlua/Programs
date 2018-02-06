#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1010
#define maxk 1000010
int c[maxn], kas, n, m, k;
using namespace std;
typedef long long LL;
struct Edge {
    int x, y;
}e[maxk];
bool cmp(Edge a, Edge b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}
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
    while (x <= m) {
        ++c[x];
        x += lowbit(x);
    }
}
void work() {
    memset(c, 0, sizeof(c));
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; ++i) scanf("%d%d", &e[i].x, &e[i].y);
    sort(e, e + k, cmp);
    LL sum = 0;
    for (int i = 0; i < k; ++i) {
        sum += i - query(e[i].y);
        add(e[i].y);
    }
    printf("Test case %d: %lld\n", ++kas, sum);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
