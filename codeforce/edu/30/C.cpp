#include <bits/stdc++.h>
#define maxn 110
using namespace std;
typedef long long LL;
int a[maxn][maxn];
int main() {
//    freopen("in.txt", "r", stdin);
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    k = min(n, k);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) scanf("%d",&a[i][j]);
    }
    int ans=0, e=0;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) a[j][i] += a[j-1][i];
        int mx=0, p=0;
        for (int j = k; j <= n; ++j) if (a[j][i] - a[j-k][i] > mx) {
            mx = a[j][i] - a[j-k][i], p = j-k;
        }
        ans += mx, e += a[p][i];
    }
    printf("%d %d\n", ans, e);
    return 0;
}
