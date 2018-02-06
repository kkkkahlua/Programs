#include <bits/stdc++.h>
#define n 20
#define m 40
int main() {
    freopen("in.txt", "w", stdout);
    srand(time(NULL));
    printf("%d %d\n", n, m);
    for (int i = 0; i < m; ++i) {
        int x = rand() % 2;
        if (x == 0) {
            printf("%d %d %d\n", x, rand() % n +1 ,rand()%n+1);
        }
        else printf("%d %d\n", x, rand()%n+1);
    }
    return 0;
}
