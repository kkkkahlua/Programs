#include <cstdio>
#include <cstdlib>
#include <ctime>
#define L 100000
int main() {
    freopen("2777.in", "w", stdout);
    srand(time(NULL));
    printf("%d 30 100000\n", L);
    for (int i = 0; i < 100000; ++i) {
        if (i & 1) {
            printf("P ");
            int x = rand() % L + 1;
            int y = rand() % (L - x + 1) + x;
            printf("%d %d\n", x, y);
        }
        else {
            printf("C ");
            int x = rand() % L + 1;
            int y = rand() % (L - x + 1) + x;
            int c = rand() % 30 + 1;
            printf("%d %d %d\n", x, y, c);
        }
    }
    return 0;
}
