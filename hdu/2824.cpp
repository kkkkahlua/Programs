#include <cstdio>
#define maxn 3000000
int a, b;
typedef long long LL;
LL e[maxn + 10];
bool check[maxn + 10];
int prime[maxn + 10];
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
//    for (int i = 1; i <= 50; ++i) printf("%d ", e[i]);
    for (int i = 2; i <= maxn; ++i) e[i] += e[i - 1];
}
void euler2() {
    int tot = 0;
    e[1] = 1;
    for (int i = 2; i <= maxn; ++i) {
        if (!check[i]) {
            prime[tot++] = i;
            e[i] = i - 1;
        }
        for (int j = 0; j < tot; ++j) {
            if (i * prime[j] > maxn) break;
            check[i * prime[j]] = true;
            if (i % prime[j]) e[i * prime[j]] = e[i] * (prime[j] - 1);
            else {
                e[i * prime[j]] = e[i] * prime[j];
                break;
            }
        }
    }
    e[1] = 0;
    for (int i = 1; i <= maxn; ++i) e[i] += e[i - 1];
}
void work() {
    printf("%lld\n", e[b] - e[a - 1]);
}
int main() {
    euler2();
    while (scanf("%d%d", &a, &b) != EOF) work();
    return 0;
}
