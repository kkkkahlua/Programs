#include <bits/stdc++.h>
int cnt, T, n, k;
void build(int root, int dep) {
    if (dep > 10) return;
    int son = rand() % 5+1;
//    printf("son : %d\n", son);
    for (int i = 0; i < son; ++i) {
        ++cnt;
        if (cnt > n) return;
        printf("%d %d\n", root, cnt);
        build(cnt, dep+1);
    }
}
int main() {
    freopen("5877.in", "w", stdout);
    srand(time(NULL));
    T=10, n = 10, k = 50;
    printf("%d\n", T);
    while (T--) {
        cnt = 1;
        printf("%d %d\n", n, k);
        for (int i = 0; i < n; ++i) printf("%d ", rand() % 10); printf("\n");
        build(1, 0);
    }
    return 0;
}
