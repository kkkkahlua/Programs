#include <cstdio>
#include <cstring>
#include <iostream>
#define maxn 100010
using namespace std;
int exist[500], kase, T;
char s[maxn];
void work() {
//    int len = strlen(s), l = 0, ans = 1;
//    memset(exist, -1, sizeof(exist));
//    for (int i = 0; i < len; ++i) {
//        if (exist[s[i]] >= l) l = exist[s[i]] + 1;
//        exist[s[i]] = i;
////        printf("%d\n", l);
//        ans = max(ans, i - l + 1);
//    }

    int len = strlen(s), ans = 0;
    memset(exist, 0, sizeof(exist));
    for (int i = 0; i < len; ++i) {
        if (!exist[s[i]]) {
            exist[s[i]] = true;
            ++ans;
        }
    }

    printf("Case #%d: %d\n", ++kase, ans);
}
int main() {
    scanf("%d", &T);
    while (scanf("%s", s) != EOF) work();
    return 0;
}
