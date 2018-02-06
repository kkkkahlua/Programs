#include <cstdio>
int main() {
    int n, a, b;
    scanf("%d", &n);
    while (scanf("%d%d", &a, &b) != EOF) printf("%d\n", (a % 100 + b % 100) % 100);
    return 0;
}
