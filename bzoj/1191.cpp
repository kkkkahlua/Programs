#include <bits/stdc++.h>
#define maxn 1010
using namespace std;
bool used[maxn];
int a[maxn][maxn], match[maxn], n, m;
typedef long long LL;
int find(int x) {
    for (int i = 0; i < n; ++i) {
        if (!used[i] && a[x][i]) {
            used[i] = true;
            if (!match[i] || find(match[i])) {
                match[i] = x;
                return true;
            }
        }
    }
    return false;
}
int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[i][x] = a[i][y] = 1;
    }
    int ans = 0;
    int i = 1;
    for (; i <= m; ++i) {
        memset(used, 0, sizeof(used));
        if (find(i)) ++ans;
        else break;
    }
    printf("%d\n", i-1);
    return 0;
}
