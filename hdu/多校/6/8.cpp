#include <bits/stdc++.h>
#define maxn 20010
inline int abs(int a) { return a > 0 ? a : -a; }
inline int max(int a, int  b) { return a > b ? a : b; }
char s[maxn];
void work() {
    int n;
    scanf("%d\n", &n);
    scanf("%s", s);
//    printf("%d %s\n", n, s);
    int len = strlen(s), ret = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = len - 1; j >= 0; --j) {
            for (int k = 0; k < )
            int ans = abs(s[i] - s[j]), len = 1;
            if (ans > n) break;
            for (int l = i + 1, r = j -1; l < r; ++l,--r) {
                ans += abs(s[l] - s[r]);
                if (ans > n) break;
                ++len;
            }
            ret = max(ret, len);
        }
    }
    printf("%d\n", ret);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
