#include <bits/stdc++.h>
int sz = 1, ch[1000010][30], val[1000010];
char s[12];
void add(char* s) {
    int len = strlen(s), u = 0;
    for (int i = 0; i < len; ++i) {
//        printf("%d\n", u);
        int x = s[i] - 'a';
        if (!ch[u][x]) {
            memset(ch[sz], 0, sizeof(ch[sz]));
            ++val[sz];
//            printf("%d %d %d\n", i, x, sz);
            ch[u][x] = sz++;
            u = ch[u][x];
        }
        else {
            u = ch[u][x];
            ++val[u];
        }
    }
}
int query(char* s) {
    int len = strlen(s), u = 0;
    for (int i = 0; i < len; ++i) {
        int x = s[i] - 'a';
        if (!ch[u][x]) return 0;
        u = ch[u][x];
    }
    return val[u];
}
int main() {
    freopen("in.txt", "r", stdin);
    while (true) {
        int tot = 0;
        while (scanf("%c", &s[tot]) && s[tot] != '\n') ++tot;
        if (tot == 0) break;
        s[tot++] = '\0';
        add(s);
//        printf("%d %s\n", tot, s);
    }
    while (scanf("%s", s) != EOF) {
        printf("%d\n", query(s));
    }
    return 0;
}
