#include <bits/stdc++.h>
int main() {
    freopen("3726.in", "w", stdout);
    int n = 10000, m = 10000, q = 20000, T = 10;
    srand(time(NULL));
    while (T--) {
    printf("%d %d\n", n, m);
    for (int i = 0; i < n; ++i) printf("%d\n", rand() % 100);
    for (int i = 0; i < m; ++i) printf("%d %d\n", rand() % n + 1, rand() % n + 1);
    for (int i = 0; i < q; ++i) {
        int t = rand() % 3;
        if (t == 0) printf("D %d\n", rand() % m + 1);
        else if (t == 1) printf("Q %d %d\n", rand() % n + 1, rand() % n + 1);
        else printf("C %d %d\n", rand() % n + 1, rand() % 100);
    }
    printf("E\n");
    }
    printf("0 0\n");
    return 0;
}
