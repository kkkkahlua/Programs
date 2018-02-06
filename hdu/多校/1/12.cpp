#include <cstdio>
#include <algorithm>
#include <iostream>
#define maxn 1000000
using namespace std;
typedef long long LL;
LL U[maxn + 10], D[maxn + 10];
const LL mod = 1e9 + 7;
int kas, n, cnt;
bool flag;
template<typename T> inline void readint(T &x) {
    x = 0; T f = 1; char ch = getchar();
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    while (isdigit(ch)) { x = x * 10 + ch - '0'; ch = getchar(); }
    x *= f;
}
namespace IO {
    const int MX = 4e7;
    char buf[MX]; int c, sz;
    void begin() {
        c = 0;
        sz = fread(buf, 1, MX, stdin);
    }
    inline bool read(int &t) {
        while(c < sz && buf[c] != '-' && (buf[c] < '0' || buf[c] > '9')) c++;
        if(c >= sz) return false;
        bool flag = 0; if(buf[c] == '-') flag = 1, c++;
        for(t = 0; c < sz && '0' <= buf[c] && buf[c] <= '9'; c++) t = t * 10 + buf[c] - '0';
        if(flag) t = -t;
        return true;
    }
}
struct node {
    int l, r, id;
}a[maxn + 10];
LL poww(LL a, LL b) {
    LL ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}
void pre() {
    U[0] = D[0] = U[1] = D[1] = 1;
    for (int i = 2; i <= maxn; ++i) U[i] = U[i - 1] * i % mod;
    for (int i = 2; i <= maxn; ++i) D[i] = poww(U[i], mod - 2);
}
bool cmp(node u, node v) {
    return u.l < v.l || (u.l == v.l && u.r > v.r);
}
LL C(LL a, LL b) {
//    printf("%lld %lld\n", a, b);
    return U[a] * D[b] % mod * D[a - b] % mod;
}
LL dfs(int l, int r) {
    if (flag) return 0;
    if (l > r) return 1;
    ++cnt;
    if (a[cnt].l != l || a[cnt].r != r) { flag = true; return 0; }
    if (l == r) return 1;

    int temp = cnt;
    LL x1 = dfs(l, a[temp].id - 1);
    LL x2 = dfs(a[temp].id + 1, r);
    return x1 * x2 % mod * C(a[temp].r - a[temp].l, a[temp].id - a[temp].l) % mod;
}
void work() {
    for (int i = 1; i <= n; ++i) { IO::read(a[i].l); a[i].id = i; }
    for (int i = 1; i <= n; ++i) IO::read(a[i].r);
    flag = false;
    sort(a + 1, a + n + 1, cmp);
    cnt = 0;
    printf("Case #%d: %d\n", ++kas, dfs(1, n));
}
int main() {
    freopen("多校联合训练第一场标程及数据 - 复件/数据/1012.in", "r", stdin);
//    freopen("12.out", "w", stdout);
//    freopen("in.txt", "r", stdin);
    IO::begin();
    pre();
    while (IO::read(n)) work();
    return 0;
}
