#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#define MAXN 40010
#define MAX 10100
using namespace std;
typedef long long LL;
int n, m, k, vis[30], loop[30];
const int MOD = 1e9 + 7;
vector<pair<int, int> > v;
vector<int> v2;
LL qpow(LL a, LL b) {
    LL ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret % MOD;
}
int GCD(int a, int b) {
    if (b == 0) return a;
    return GCD(b, a % b);
}
int LCA(int a, int b) {
    return a / GCD(a, b) * b;
}
//1kUAmhmf
//mfyd
int lca() {
    int ret = 1;
    for (int i = 0; i < v2.size(); ++i) ret = LCA(ret, v[v2[i]].first);// printf("v : %d ", v[v2[i]].first);
//    printf("\n");
    return ret;
}
void work() {
    scanf("%d", &n);
    char s[30];
    memset(vis, 0, sizeof(vis));
    memset(loop, 0, sizeof(loop));
    gets(s);
//    printf("%s\n", s);
    int a[30];
    for (int i = 0; s[i] != '\0'; ++i) a[i] = s[i] - 'a';
    for (int i = 0; i < 26; ++i) {
        if (vis[a[i]]) continue;
        int x = i, cnt = 1; vis[x] = true;
        while (a[x] != i) { x = a[x]; vis[x] = true; ++cnt; }
//        printf("%d ", cnt);
        ++loop[cnt];
    }
    v.clear();
    for (int i = 1; i < 27; ++i) {
        if (loop[i]) v.push_back(make_pair(i, i * loop[i]));
    }
    int setsnum = v.size();
    LL ans = 0;
    for (int i = 1; i < (1 << setsnum); ++i) {
        LL ans1 = 0;
        v2.clear();
        int cnt = 0;
        for (int j = 0; j < setsnum; ++j) {
            if (i & (1 << j)) {
                ++cnt;
                v2.push_back(j);
            }
        }
        if (cnt > n) continue;
        int setnum = v2.size();
//        printf("setnum : %d\n", setnum);
//        for (int j = 0; j < setnum; ++j) printf("%d ", v[v2[j]].second);
        ans1 = lca();
        LL ans2 = 0;
        for (int j = 1; j < (1 << setnum); ++j) {
            int sum = 0, cnt1 = 0;
            for (int k = 0; k < setnum; ++k) {
                if (j & (1 << k)) {
                    ++cnt1;
                    sum += v[v2[k]].second;
                }
            }
//            printf("sum %d\n", sum);
            if ((setnum - cnt1) & 1) ans2 = (ans2 + MOD - (LL)qpow(sum, n)) % MOD;
            else ans2 = (ans2 + (LL)qpow(sum, n)) % MOD;
        }
        ans1 = (ans1 * ans2) % MOD;
        ans = (ans + ans1) % MOD;
    }
    printf("%I64d\n", ans);
}
int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    while (scanf("%d", &n) != EOF) work();
    return 0;
}
