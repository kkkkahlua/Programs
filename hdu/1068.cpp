#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 2020
using namespace std;
int n, line[MAX][MAX], match[MAX];
bool used[MAX];
int find(int x) {
    for (int i = 0; i < n; ++i) {
        if (line[x][i] && !used[i]) {
            used[i] = true;
            if (match[i] == 0 || find(match[i])) {
                match[i] = x;
                return true;
            }
        }
    }
    return false;
}
void work() {
//    printf("%d\n", n);
    memset(line, 0, sizeof(line));
    memset(match, 0, sizeof(match));
    for (int i = 0; i < n; ++i) {
        int x, num;
        scanf("%d: (%d)", &x, &num);
//        printf("%d %d\n", x, num);
        for (int j = 0; j < num; ++j) {
            int y;
            scanf("%d", &y);
            line[x][y] = true;
        }
    }
    int tot = 0;
    for (int i = 0; i < n; ++i) {
        memset(used, 0, sizeof(used));
        if (find(i)) ++tot;
    }
//    printf("%d\n", tot);
    printf("%d\n", n - tot / 2);
}
int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while (scanf("%d", &n) != EOF) work();
    return 0;
}
