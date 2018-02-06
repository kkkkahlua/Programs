#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 510
using namespace std;
int k, m, n, line[MAX][MAX], boy[MAX];
bool used[MAX];
bool find(int x) {
    for (int i = 1; i <= n; ++i) {
        if (line[x][i] && !used[i]) {
            used[i] = true;
            if (boy[i] == 0 || find(boy[i])) {
                boy[i] = x;
                return true;
            }
        }
    }
    return false;
}
void work() {
    memset(line, 0, sizeof(line));
    memset(boy, 0, sizeof(boy));
    for (int i = 0; i < k; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
//        printf("%d %d\n", a, b);
        line[a][b] = true;
    }
    int tot = 0;
    for (int i = 1; i <= m; ++i) {
        memset(used, 0, sizeof(used));
        if (find(i)) ++tot;
    }
    printf("%d\n", tot);
}
int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while (scanf("%d%d%d", &k, &m, &n) != EOF && k != 0) work();
    return 0;
}
