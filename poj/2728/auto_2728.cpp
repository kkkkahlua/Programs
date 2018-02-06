#include <bits/stdc++.h>
#define n 1000
int main() {
    freopen("in.txt", "w", stdout);
    printf("%d\n", n);
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        printf("%d %d %d\n", rand() % 10000, rand() % 10000, rand() % 10000000);
    }
    printf("0\n");
    return 0;
}
