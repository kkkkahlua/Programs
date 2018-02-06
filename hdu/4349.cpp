#include <bits/stdc++.h>
int n;
int count(int n) {
    int ret = 0;
    while (n) {
        ++ret;
        n &= n - 1;
    }
    return ret;
}
int pow(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) ret *= a;
        a *= a;
        b >>= 1;
    }
    return ret;
}
void work() {
    int cnt = count(n);
    printf("%d\n", pow(2, cnt));
}
int main() {
    while (scanf("%d", &n) != EOF) work();
    return 0;
}
