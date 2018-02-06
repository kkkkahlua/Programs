#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
bool flag, a[30][30], used[30];
int n, m, lim, ret, step[30];
vector<int> e[30];
struct node {
    int u, v;
};
void dfs(int cur, int cnt) {
    printf("%d %d %d\n", cur, cnt, m);
    if (flag) return;
    step[cnt] = cur;
    for (int i = 1; i <= n; ++i) {
        if (used[i]) continue;
        used[i] = 1;
        int num = e[i].size();
        printf("cur : %d\n", i);
        vector<node> temp; temp.clear();
        for (int j = 0; j < num; ++j) {
            for (int k=j+1; k < num; ++k) {
                if (!a[e[i][j]][e[i][k]]) temp.push_back({e[i][j],e[i][k]});
            }
        }
        printf("temp :%d\n",temp.size());
        for (auto nd : temp) {
            ++m;
            printf("%d %d\n", nd.u, nd.v);
            a[nd.u][nd.v] = a[nd.v][nd.u] = true;
        }
        if (m == lim) {
            ret = cnt + 1;
            printf("ret : %d\n", ret);
            flag = true;
            return;
        }

        dfs(i, cnt+1);
        if (flag) return;

        for (auto nd : temp) {
            --m;
            a[nd.u][nd.v] = a[nd.v][nd.u] = false;
        }
        used[i] = 0;
    }
}
int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d%d", &n,&m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u][v] = a[v][u] = 1;
        e[u].push_back(v);
        e[v].push_back(u);
    }
//    for (int i = 1; i <= n; ++i) {
//        printf("%d :\n", i);
//        for (auto x : e[i]) printf("%d ", x); puts("");
//    }
    lim = n*(n-1)/2;
    int ans = n+1;
    if (m == lim) { puts("0"); return 0; }
    for (int i = 1; i <= n; ++i) {
        printf("%d\n", m);
        flag = 0; used[i] = 1;
        vector<node> temp; temp.clear();
        int num = e[i].size();
        for (int j = 0; j < num; ++j) {
            for (int k=j+1; k < num; ++k) {
                if (!a[e[i][j]][e[i][k]]) temp.push_back({e[i][j],e[i][k]});
            }
        }
//        printf("sz : %d\n", temp.size());
        for (auto nd : temp) {
            ++m;
            a[nd.u][nd.v] = a[nd.v][nd.u] = true;
        }
        if (m == lim) { printf("%d\n", i); puts("1"); return 0; }
        dfs(i, 0);
        ans = min(ans, ret);
        printf("ans : %d\n", ans);

        for (auto nd : temp) {
            --m;
            a[nd.u][nd.v] = a[nd.v][nd.u] = false;
        }
        used[i] = 0;
    }
    printf("%d\n", ans);
    printf("%d", step[0]);
    for (int i = 1; i < ans; ++i) printf(" %d", step[i]); puts("");
    return 0;
}
