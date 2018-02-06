#include <cstdio>
#include <vector>
#include <cstring>
#define maxn 6010
int dp[maxn][2], a[maxn], fa[maxn], n;
inline max(int a, int b) { return a > b ? a : b; }
using namespace std;
vector<int> v[maxn];
void dfs(int x) {
    if (v[x].size() == 0) {
        dp[x][0] = 0; dp[x][1] = a[x];
        return;
    }
    int tot = v[x].size();
    dp[x][1] = a[x];
    for (int i = 0; i < tot; ++i) {
        dfs(v[x][i]);
        dp[x][1] += dp[v[x][i]][0];
        dp[x][0] += max(dp[v[x][i]][0], dp[v[x][i]][1]);
    }
}
void work() {
    memset(fa, 0, sizeof(fa));
    memset(dp, 0, sizeof(dp));
    v[0].clear();
    for (int i = 1; i <= n; ++i) { scanf("%d", &a[i]); v[i].clear(); }
    int x, y;
    while (scanf("%d%d", &x, &y) && x && y) { v[y].push_back(x); ++fa[x]; }
    for (int i = 1; i <= n; ++i) {
        if (fa[i] == 0) v[0].push_back(i);
    }
    dfs(0);
    printf("%d\n", max(dp[0][0], dp[0][1]));
}
int main() {
    while (scanf("%d", &n) != EOF) work();
    return 0;
}
