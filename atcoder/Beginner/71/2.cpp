#include <bits/stdc++.h>
bool vis[100];
char s[100010];
int main() {
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0; i < len; ++i) vis[s[i] - 'a'] = true;
    bool flag = false;
    for (int i = 0; i < 26; ++i) {
        if (!vis[i]) {
            printf("%c\n", 'a' + i);
            flag = true;
            break;
        }
    }
    if (!flag) printf("None\n");
    return 0;
}
