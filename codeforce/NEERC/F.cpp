#include <bits/stdc++.h>
#define maxl 110
#define maxn 410
using namespace std;
typedef long long LL;
char s[maxl];
struct Array {
    char data[maxl];
    char& operator [] (const int idx) { return data[idx]; }
}ss[maxn];
bool cmp(Array a, Array b) {
    return strcmp(a.data, b.data) < 0;
}
int main() {
//    freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        int len = strlen(s), p = 0;
        while (p < len) {
            if (s[p] == 'k') {
                int j = p;
                while (j < len && s[j] == 'k') ++j;
                if (j == len || s[j] != 'h') {
                    for (; p < j; ++p) ss[i][++ss[i][0]] = 'k';
                }
                else if (s[j] == 'h') ss[i][++ss[i][0]] = 'h', ++j;
                p = j;
            }
            else if (s[p] == 'u') {
                ss[i][++ss[i][0]] = 'o';
                ss[i][++ss[i][0]] = 'o';
                ++p;
            }
            else ss[i][++ss[i][0]] = s[p++];
        }
        ss[i][ss[i][0]+1] = '\0';
    }
    sort(ss, ss+n, cmp);
//    for (int i = 0; i < n; ++i) {
//        printf("%s\n", ss[i].data+1);
//    }
    int ans = 1;
    for (int i = 1; i < n; ++i) {
        if (cmp(ss[i-1], ss[i]) == 1) ++ans;
    }
    printf("%d\n", ans);
    return 0;
}
