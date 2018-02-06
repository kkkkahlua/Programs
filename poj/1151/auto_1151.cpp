#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    srand(time(NULL));
    freopen("1151.in", "w", stdout);
    int T = 10, n = 80;
    while (T--) {
        printf("%d\n", n);
        for (int i = 0; i < n; ++i) {
            int x1 = rand() % 10000, y1 = rand() % 10000;
            int x2 = rand() % (10000 - x1) + x1+1,
                y2 = rand() % (10000 - y1) + y1+1;
            printf("%d %d %d %d\n", x1, y1, x2, y2);
        }
    }
    printf("0\n");
    return 0;
}
