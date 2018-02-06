#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    freopen("in.txt", "w", stdout);
    srand(time(NULL));
    int T = 10, n = 50;
    printf("%d\n", T);
    for (int i = 0; i < T; ++i) {
        printf("%d\n", n);
        for (int i = 0; i < n; ++i) {
            int x = rand() % 2;
            if (x) printf("-");
            printf("%d ", rand()%1000);
        }
        puts("");
    }
    return 0;
}
