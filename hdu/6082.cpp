#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define maxn 2010
#define maxm 1010
using namespace std;
typedef long long LL;
vector<int> hurt[12];
LL dp[maxn], minn[maxn];
int k[maxm], p[maxm], life[12], n, m;
inline int max(int a, int b) { return a > b ? a : b; }
inline LL min(LL a, LL b) { return a < b ? a : b; }
void work() {
    for (int i = 0; i <= 10; ++i) hurt[i].clear();
    memset(life, 0, sizeof(life));
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        hurt[y].push_back(x);
        life[y] = max(life[y], x);
    }
    int stg = 0;
    for (int i = 0; i < m; ++i) { scanf("%d%d", &k[i], &p[i]); stg = max(stg, p[i]); }
    LL sum = 0;
    for (int i = 0; i <= 10; ++i) {
        if (hurt[i].empty()) continue;
        int lim = life[i] + stg;
        for (int j = 0; j <= lim; ++j) dp[j] = inf;
        dp[0] = 0;
        bool flag = false;
        for (int j = 0; j < m; ++j) {
            int atk = p[j] - i;
            if (atk <= 0) continue;
            flag = true;
            for (int kk = atk; kk <= lim; ++kk) dp[kk] = min(dp[kk], dp[kk - atk] + k[j]);
        }
        if (!flag) {
            printf("-1\n");
            return;
        }
        minn[lim] = dp[lim];
        for (int j = lim - 1; j >= 0; --j) minn[j] = min(minn[j + 1], dp[j]);
        for (auto x : hurt[i]) sum += minn[x];
    }
    printf("%lld\n", sum);
}
int main() {
    freopen("in.txt", "r", stdin);
    while (scanf("%d%d", &n, &m) != EOF) work();
    return 0;
}
