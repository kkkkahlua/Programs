#include <cstdio>
#define maxn 1000010
typedef long long LL;
LL a[maxn], e[maxn];
void euler() {
    e[1] = 0;
    for (int i = 2; i <= maxn; ++i) e[i] = i;
    for (int i = 2; i <= maxn; ++i) {
        if (e[i] == i) {
            for (int j = i; j <= maxn; j += i) {
                e[j] = e[j] / i * (i - 1);
            }
        }
    }
    a[1] = 1;
    for (int i = 2; i <= maxn; ++i) a[i] = a[i - 1] + e[i];
}
int main() {
    freopen("phi.out", "w", stdout);
    euler();
    int n;
    while (scanf("%d", &n) != EOF) printf("%lld\n", 2 * a[n] + 1);
    return 0;
}
