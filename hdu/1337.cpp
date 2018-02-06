#include <cstdio>
#include <cstring>
int tag[110], n;
void work() {
    memset(tag, 0, sizeof(tag));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (j % i == 0) tag[j] = 1 - tag[j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) if (tag[i]) ++ans;
    printf("%d\n", ans);
}
int main() {
    int T;
    scanf("%d", &T);
    while (scanf("%d", &n) != EOF) work();
    return 0;
}
