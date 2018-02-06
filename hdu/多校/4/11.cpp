#include <bits/stdc++.h>
char s[10][50];
bool f[10];
int judge(int l, int r) {
    memset(f, 0, sizeof(f));
//    for (int i = 0; i < 7; ++i) {
//        for (int j = l; j <= r; ++j) printf("%c", s[i][j]);
//        printf("\n");
//    }
    if (s[0][l + 1] == 'X') f[1] = true;
    if (s[1][r] == 'X') f[2] = true;
    if (s[4][r] == 'X') f[3] = true;
    if (s[6][l + 1] == 'X') f[4] = true;
    if (s[4][l] == 'X') f[5] = true;
    if (s[1][l] == 'X') f[6] = true;
    if (s[3][l + 1] == 'X') f[7] = true;
//    printf("%d%d%d%d%d%d%d\n", f[1], f[2], f[3], f[4], f[5], f[6],f[7]);
    if (f[1] && f[2] && f[3] && f[4] && f[5] && f[6] && !f[7]) return 0;
    if (f[2] && f[3] && !f[1] && !f[4] && !f[5] && !f[6] && !f[7]) return 1;
    if (f[1] && f[2] && f[7] &&f[4]&&f[5] && !f[3] && !f[6]) return 2;
    if (f[1] &&f[2]&&f[3]&&f[7] &&f[4]&&!f[5] &&!f[6]) return 3;
    if (f[2]&&f[3]&&f[6]&&f[7]&&!f[1]&&!f[4]&&!f[5]) return 4;
    if (f[1]&&f[3]&&f[6]&&f[7]&&f[4]&&!f[2]&&!f[5]) return 5;
    if (f[1]&&f[3]&&f[4]&&f[5]&&f[6]&&f[7]&&!f[2]) return 6;
    if (f[1]&&f[2]&&f[3]&&!f[4]&&!f[5]&&!f[6]&&!f[7]) return 7;
    if (f[1]&&f[2]&&f[3]&&f[4]&&f[5]&&f[6]&&f[7]) return 8;
    if (f[1]&&f[2]&&f[3]&&f[4]&&!f[5]&&f[6]&&f[7]) return 9;
}
void print(int x) {
    if (x) printf("%d",x);
    else printf("0");
}
void work() {
    for (int i = 0; i < 7; ++i) scanf("%s", s[i]);
    int x1 = judge(0, 3), x2 = judge(5, 8), x3 = judge(12, 15), x4 = judge(17, 20);
    print(x1);
    print(x2);
    printf(":");
    print(x3);print(x4);
    printf("\n");
}
int main() {
    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d\n", &T);
    while (T--) work();
    return 0;
}
