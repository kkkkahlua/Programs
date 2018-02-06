#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
char s[100010];
bool ok[1010], exist[1010];
int main() {
    freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    bool flag = false;
    int cnt=0;

    for (int i = 'a'; i <= 'z'; ++i) ok[i] = 1; int num = 26;
    for (int i = 0; i < n; ++i) {
        char ch;
        scanf("\n%c%s", &ch, s);
        if (flag) {
            if (ch != '.' && i != n-1) ++cnt;
        }
        else {
            if (ch == '!') {
                int len = strlen(s);
                memset(exist, 0, sizeof exist);
                for (int j = 0; j < len; ++j) exist[s[j]] = 1;
                for (int j = 'a'; j <= 'z'; ++j) {
                    if (ok[j] && !exist[j]) --num, ok[j] = 0;
                }
                if (num == 1) flag = true;
            }
            else if (ch == '.') {
                int len = strlen(s);
                memset(exist, 0, sizeof exist);
                for (int j = 0; j < len; ++j) exist[s[j]] = 1;
                for (int j = 'a'; j <= 'z'; ++j) {
                    if (ok[j] && exist[j]) --num, ok[j] = 0;
                }
                if (num == 1) flag = true;
            }
            else if (ch == '?') {
                if (ok[s[0]]) --num, ok[s[0]] = 0;
                if (num == 1) flag = true;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
