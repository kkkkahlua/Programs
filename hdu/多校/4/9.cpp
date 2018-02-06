#include <bits/stdc++.h>
void work() {
    int n;
    scanf("%d", &n);
    int tot = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if (x & 1) ++tot;
    }
    int m = 2, k;
    int even = n - tot;
    if (even >= tot) k = 0;
    else k = 1;
    printf("%d %d\n", m, k);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
