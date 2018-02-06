#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    int n, m, x, a[100], b[100];
    scanf("%d%d", &n, &m);
    int mn = 10, mm = 10;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        mn = min(mn, a[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &b[i]);
        mm = min(mm, b[i]);
    }
    int minx = 10;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i] == b[j]) minx = min(minx, a[i]);
        }
    }
    if (minx < 10) printf("%d\n", minx);
    else {
        if (mn > mm) swap(mn, mm);
        printf("%d%d\n", mn,mm);
    }
    return 0;
}
