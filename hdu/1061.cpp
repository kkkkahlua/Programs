#include <cstdio>
typedef long long LL;
int n;
LL pow(LL a, LL b) {
    LL ans = 1;
    while (b) {
        if (b & 1) { ans *= a; ans %= 10; }
        a *= a; a %= 10;
        b >>= 1;
    }
    return ans;
}
void work() {
    printf("%lld\n", pow((LL)n, (LL)n));
}
int main() {
    int T;
    scanf("%d", &T);
    while (scanf("%d", &n) != EOF) work();
    return 0;
}
