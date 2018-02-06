#include <bits/stdc++.h>
#define maxn 500010 * 20
int sz = 1, ch[maxn][30], val[maxn];
char s[500010];
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
void work() {
    int n, q;
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        int len = strlen(s);
        for (int l = 0, r = len - 1; l <r; ++l, --r) ss[l] = s[r];
        ss[len] = '\0';
        add(s, i); add(ss, i);
    }
}
int main() {
    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) work();
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        add(s);
    }
//    printf("%d %d\n", ch[0][0], ch[0][1]);
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%s", s);
        printf("%d\n", query(s));
    }
    return 0;
}
