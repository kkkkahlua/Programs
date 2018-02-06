#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("in.txt", "w", stdout);
    int T = 10;
    printf("%d\n", T);
    int n = 3;
    srand(time(NULL));
    while (T--) {
        printf("%d\n", n);
        for (int i = 0; i < n; ++i)
        printf("%d %d %d\n", rand() % 10, rand() % 10, rand() % 100);
    }
    return 0;
}
