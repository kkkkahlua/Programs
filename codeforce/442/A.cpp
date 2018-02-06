#include <bits/stdc++.h>
char s[110];
using namespace std;
typedef long long LL;
char* rec[5] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
int len[5] = {5,4,5,3,6};
bool cmp(char* s1, char* s2, int len) {
//    printf("%s %s\n", s1, s2);
    for (int i = 0; i < len; ++i) {
        if (s1[i] != s2[i]) return false;
    }
    return true;
}
int main() {
//    freopen("in.txt", "r", stdin);
    int cnt=0;
    scanf("%s", s);
    for (int i = 0; s[i]; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (cmp(rec[j], s+i, len[j])) ++cnt;
        }
        if (cnt > 2) {printf("NO\n");  return 0;}
    }
    if (cnt==1) printf("YES\n");
    else printf("NO\n");
    return 0;
}
