#include <cstdio>
int kas;
int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}
void work() {
    int n, a, b;
    printf("Case #%d: ", ++kas);
    scanf("%d%d%d", &n, &a, &b);
    int g = gcd(a, b);
    if ((n / g) & 1) printf("Yuwgna\n");
    else printf("Iaka\n");
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
