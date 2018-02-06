#include <bits/stdc++.h>
#define lson(x) (x << 1)
#define rson(x) (x << 1 | 1)
using namespace std;
typedef long long LL;
int n, m;
map<int, LL> dp, val;
LL calc(int u) {
    if (u > n) return 0;
    if (dp[u]) return dp[u];
    int temp = u, ldep = 0, rdep = 0;
    while (temp <= n) temp = lson(temp), ++ldep;
    temp = u;
    while (temp <= n) temp = rson(temp), ++rdep;
    if (ldep != rdep) temp = n;
    else temp /= 2;
    LL ret = 0;
    while (true) {
        ret += temp;
        if (temp == u) break;
        temp /= 2;
    }
    return ret;
}
LL uval, sum;
void dfs(int u, int son) {
    if (u == 0) return;
    uval = max(uval, sum + (val[u] ? val[u] : u) + calc(son ^ 1));
    if (u == 1) return;
    sum += val[u] ? val[u] : u;
    dfs(u/2, u);
}
LL ask(int u) {
    LL lval = calc(lson(u)), rval = calc(rson(u));
    uval = sum = 0;
    dfs(u/2, u);
    LL mn = min(min(lval, rval), uval);
    return lval + rval + uval - mn + (val[u] ? val[u] : u);
}
void update(int u) {
    if (u == 0) return;
    dp[u] = max(calc(lson(u)), calc(rson(u))) + (val[u]?val[u]:u);
    if (u == 1) return;
    update(u/2);
}
void change(int u, LL x) {
    dp[u] = (dp[u]?dp[u]:calc(u)) - (val[u]?val[u]:u) + x;
    val[u] = x;
    update(u/2);
}
void work() {
    val.clear();
    dp.clear();
    char s[10];
    while (m--) {
        scanf("%s", s);
        if (s[0] == 'q') {
            int u;
            scanf("%d", &u);
            printf("%lld\n", ask(u));
        }
        else {
            int u; LL x;
            scanf("%d%lld", &u, &x);
            change(u, x);
        }
    }
}
int main() {
    freopen("多校第九场标程和数据/数据/1001.in", "r", stdin);
    freopen("01.out", "w", stdout);
    while (scanf("%d%d", &n, &m) != EOF) work();
    return 0;
}
