#include <bits/stdc++.h>
int main() {
    freopen("in.txt", "w", stdout);
    int T = 100, R = 100, r = 100;
    printf("%d\n", T);
    while (T--) {
        printf("%d\n", R);
        printf("%d %d\n%d %d\n", 0, r, r, 0);
        --r;
    }
    return 0;
}
