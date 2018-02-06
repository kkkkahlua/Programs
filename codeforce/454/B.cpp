#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
char s[20][20], ss[20];
int main() {
    freopen("in.txt", "r", stdin);
    for (int i = 1; i <= 3; ++i) gets(s[i]+1);
    gets(ss);
    for (int i = 4; i <= 6; ++i) gets(s[i]+1);
    gets(ss);
    for (int i = 7; i <= 9; ++i) gets(s[i]+1);

    int a,b;
    scanf("%d%d", &a, &b);
    int px = (a-1) % 3 + 1, py = (b-1) % 3 + 1;
    int u = px*3-2, l = py*3-2+py-1;
    bool flag = false;
    for (int i = u; i < u+3; ++i) {
        for (int j = l; j < l+3; ++j) {
            if (s[i][j]==46) {
                flag = true, s[i][j] = 33;
            }
        }
    }
    if (!flag) {
        for (int i = 1; i <= 9; ++i) {
            for (int j = 1; j <= 11; ++j) if (s[i][j]==46) s[i][j] = 33;
        }
    }
    for (int i = 1; i <= 3; ++i) puts(s[i]+1);
    puts("");
    for (int i = 4; i <= 6; ++i) puts(s[i]+1);
    puts("");
    for (int i = 7; i <= 9; ++i) puts(s[i]+1);
//    for (int i = 0; i < 11; ++i) puts(s[i]);
    return 0;
}
