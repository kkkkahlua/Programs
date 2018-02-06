#include <cstdio>
#include <cstring>
#define maxn 100000010
#define MOD 1000000007
int a, b;
typedef long long LL;

void work() {
    LL ans = (LL)a * b - a - b;
    printf("%lld\n", ans);
}
int main() {
    int T;
    scanf("%d\n", &T);
    while (scanf("%d%d", &a, &b) != EOF) work();
    return 0;
}
