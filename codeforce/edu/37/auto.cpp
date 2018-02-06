#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    freopen("in.txt", "w", stdout);
    int n = 6, m = 10;
    srand(time(NULL));
    printf("%d %d\n", n, m);
    while (m--) {
        int x = rand() % n, y;
        do {
            y = rand() % n;
        } while (x==y);
        printf("%d %d\n", x+1, y+1);
    }
    return 0;
}
