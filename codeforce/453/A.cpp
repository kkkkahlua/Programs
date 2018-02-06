#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int x[110], y[110];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int endd = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x[i], &y[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (x[i] > endd) { puts("NO"); return 0; }
        endd = max(endd, y[i]);
    }
    if (endd >= m) puts("YES");
    else puts("NO");
    return 0;
}
