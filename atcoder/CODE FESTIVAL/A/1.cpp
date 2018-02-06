#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
char s[11];
int main() {
    scanf("%s", s);
    int len = strlen(s);
    s[4] = '\0';
    if (strcmp(s, "YAKI") == 0) printf("Yes\n");
    else printf("No\n");
    return 0;
}
