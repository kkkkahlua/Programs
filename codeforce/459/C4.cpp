#include <bits/stdc++.h>
#define maxn 5010
using namespace std;
typedef long long LL;
char s[maxn];
int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("c4.out", "w", stdout);
    scanf("%s", s);
    int len = strlen(s), ans=0;
    for (int l = 0; l < len; ++l) {
        int cur = 0, qmk = 0;
        for (int r = l; r < len; ++r) {
            if (s[r] == '(') ++cur;
            else if (s[r] == ')') --cur;
            else ++qmk;
            if (cur < 0) break;
            if (cur < qmk) ++cur, --qmk;
            if (cur == qmk) ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}
