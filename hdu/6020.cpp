#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
char s[100010];
int sum, a[3], b[3], c[3], k, n;
bool judge() {
//    printf("c : %d %d %d %d\n", c[0], c[1], c[2], k);
    int lim1 = c[1] < k ? c[1] : k, lim2 = c[2] < k ? c[2] : k;
    for (int k2 = 0; k2 <= lim1; ++k2) {
        int k3 = k - k2 - c[0] > 0 ? k - k2 - c[0] : 0;
        for (; k3 <= lim2; ++k3) {
            if ((k2 + 2 * k3) % 3 == sum) {
//                printf("%d %d\n", k2, k3);
                return true;
            }
        }
    }
    return false;
}
void work() {
//    printf("%d %d\n", n, k);
//    scanf("%s", s);
    gets(s);
//    printf("%s\n", s);
    int len = strlen(s), p = 0;
    sum = 0;
    bool flag = false;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for (; s[p] != '0' && p < len; ++p);
    for (int i = 0; i < p; ++i) {
        int x = (s[i] - '0') % 3;
        ++a[x];
        sum += x;
    }

    for (int i = p; i < len; ++i) {
        int x = (s[i] - '0') % 3;
        ++b[x];
        sum += x;
    }
//    printf("a : %d %d %d\n", a[0], a[1], a[2]);

//    printf("b : %d %d %d\n", b[0], b[1], b[2]);

    for (int i = 0; i < 3; ++i) c[i] = a[i] + b[i];
    if (judge()) printf("yes\n");
    else printf("no\n");

    c[0] = b[0]; c[1] = b[1]; c[2] = b[2];
    sum %= 3;
    if (p == 1) {
        if (judge()) {
            printf("yes\n");
            return;
        }
        printf("no\n");
        return;
    }

    b[0] += a[0]; b[1] += a[1]; b[2] += a[2];
//    printf("%d %d %d\n", b[0], b[1], b[2]);
    if (a[0] >= 1) {
        c[0] = b[0] - 1; c[1] = b[1]; c[2] = b[2];
        if (judge()) {
            printf("yes\n");
            return;
        }
    }
    if (a[1] >= 1) {
        c[0] = b[0]; c[1] = b[1] - 1; c[2] = b[2];
        if (judge()) {
            printf("yes\n");
            return;
        }
    }
    if (a[2] >= 1) {
        c[0] = b[0]; c[1] = b[1]; c[2] = b[2] - 1;
        if (judge()) {
            printf("yes\n");
            return;
        }
    }
    printf("no\n");
}
int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    while (scanf("%d%d\n", &n, &k) != EOF) work();
    return 0;
}
