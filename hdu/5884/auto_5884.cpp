#include <cstdio>
#include <cstdlib>
#include <ctime>
int a[20];
int main() {
    freopen("5884.in", "w", stdout);
    printf("5\n");
    srand(time(NULL));
    int sum = 0;
    for (int i = 0; i < 10; ++i) { a[i] = rand() % 100; sum += a[i]; }
    for (int i = 0; i < 5; ++i) {
        printf("%d %d\n", 10, sum);
        sum += 20;
        for (int j = 0; j < 10; ++j) printf("%d ", a[j]); printf("\n");
    }
    return 0;
}
