#include <bits/stdc++.h>
int main() {
//    freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int tot = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if (x > 35) ++tot;
    }
    printf("%d\n", n - tot);
    return 0;
}
