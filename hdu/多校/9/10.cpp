#include <bits/stdc++.h>
#define maxn 2510
using namespace std;
char s1[maxn], s2[maxn];
int rec[maxn], dp[maxn][maxn];
void init() {
    int len = strlen(1+s1);
    int i = 1, j = 2;
    rec[0] = 1;
    while (j <= len) {
        if (s1[i] == s1[j]) { ++j; continue; }
        for (; i < j; ++i) rec[i] = j;
        ++j;
    }
    for (; i < j; ++i) rec[i] = j;
//    for (int i = 1; i <= len; ++i) printf("%d ", rec[i]); printf("\n");
}
void work() {
    gets(s1+1); gets(s2+1);
    memset(rec, 0, sizeof(rec));
    init();
    int len1 = strlen(s1+1), len2 = strlen(s2+1);
    if (len1 == 0) {
        if (len2 == 0 || (len2 == 1 && s2[1] == '*') || (len2 == 2 && s2[2] == '*')) printf("yes\n");
        else printf("no\n");
        return;
    }
    if (len2 == 0) {
        if (len1 == 0) printf("yes\n");
        else printf("no\n");
        return;
    }
//    printf("%s\n%s\n", s1+1, s2+1);
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1; dp[0][1] = -1;
    for (int i = 0; i <= len2; ++i) {
        for (int j = 0; j <= len1; ++j) {
            if (i == len2 && j == len1) break;
            if (dp[i][j] && (s2[i+1] == s1[j+1] || s2[i+1] == '.')) {
                    ++dp[i+1][j+1];
                    --dp[i+1][j+2];
            }
            if (s2[i+1] == '*') {
                if (dp[i][j] || dp[i-1][j]) {
                    ++dp[i+1][j];
                    --dp[i+1][rec[j]];
                }
            }
            dp[i][j+1] += dp[i][j];

        }
    }
    if (dp[len2][len1]) printf("yes\n");
    else printf("no\n");
}
int main() {
//    freopen("多校第九场标程和数据/数据/1010.in", "r", stdin);
    int T;
    scanf("%d\n", &T);
    while (T--) work();
    return 0;
}
