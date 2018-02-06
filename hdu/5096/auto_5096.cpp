#include <bits/stdc++.h>
int main() {
    freopen("5096.in", "w", stdout);
    srand(time(NULL));
    int T = 1000, n = 100, m = 10, q = 20;
    while (T--) {
        printf("%d %d\n", n, m);
        for (int i = 0; i < q; ++i) {
            int type = rand() % 3;
            if (type == 0) {
                printf("S %d:%d:%c:%d\n", rand() % 300, rand() % n, rand()%10+'A', rand()%2);
            }
            else if (type == 1) {
                printf("T %d\n", rand() % n);
            }
            else printf("R %d\n", rand() % n);
        }
        printf("Contest Ends\n");
    }
    return 0;
}
