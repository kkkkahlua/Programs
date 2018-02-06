#include <bits/stdc++.h>
#define maxn 100010
#define maxl 110
using namespace std;
char cph[maxn][maxl], ctn[maxn][maxl], s[maxl];
map<int, int> mpcph, mpctn;
typedef long long LL;
unsigned bkdr(char* s) {
    unsigned int seed = 131;
    unsigned int h = 0;
    while (*s) {
        h = h * seed + (*s++);
    }
    return h&0x7fffffff;
}
int main() {
    freopen("in.txt", "r", stdin);
    int cnt=0;
    while (true) {
        gets(cph[++cnt]);
        if (cph[cnt][0] == '@') break;
        for (int i = 0; cph[cnt][i]; ++i) {
            if (cph[cnt][i] == ']') {
                strcpy(ctn[cnt]+1, cph[cnt]+i+2);
                cph[cnt][i] = '\0';
                mpctn[bkdr(ctn[cnt]+1)] = mpcph[bkdr(cph[cnt]+1)] = cnt;
                break;
            }
        }
    }
    int n;
    scanf("%d", &n); getchar();
    for (int i = 0; i < n; ++i) {
        gets(s);
        if (s[0] == '[') {
            s[strlen(s)-1] = '\0';
            int idx = mpcph[bkdr(s+1)];
            if (!idx) puts("what?");
            else puts(ctn[idx]+1);
        }
        else {
            int idx = mpctn[bkdr(s)];
            if (!idx) puts("what?");
            else puts(cph[idx]+1);
        }
    }
    return 0;
}
