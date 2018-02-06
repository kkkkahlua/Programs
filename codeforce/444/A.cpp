#include <bits/stdc++.h>
using namespace std;
char s[110];
typedef long long LL;
int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%s", s);
    int len = strlen(s);
    int i = 0;
    for (; i < len; ++i) {
        if (s[i] == '1') break;
    }
    int cnt=0;
    for (int j = i+1; j < len; ++j) {
        if (s[j] == '0') ++cnt;
        if (cnt==6) { puts("yes"); exit(0);}
    }
    puts("no");
    return 0;
}
