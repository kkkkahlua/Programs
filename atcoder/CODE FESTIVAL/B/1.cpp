#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
char s[100010];
int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%s", s);
    int len = strlen(s);
    s[len-8] = '\0';
    printf("%s", s);
    return 0;
}
