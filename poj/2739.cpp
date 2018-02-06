#include <cstdio>
#define maxn 10000
int prime[maxn + 10];
bool vis[maxn + 10];
int tot = 0, x;
void init() {
    for (int i = 2; i <= maxn; ++i) {
        if (!vis[i]) prime[tot++] = i;
        for (int j = 0; j < tot; ++j) {
            if (prime[j] * i > maxn) break;
            vis[prime[j] * i] = true;
            if (i % prime[j] == 0) break;
        }
    }
}
void work() {
    int l = 0, r = 0, sum = 0, ans = 0;
    while (true) {
        while (r < tot && sum < x) sum += prime[r++];
        if (sum < x) break;
        if (sum == x) ++ans;
        sum -= prime[l++];
    }
    printf("%d\n", ans);
}
int main() {
    init();
    while (scanf("%d", &x) && x) work();
    return 0;
}
