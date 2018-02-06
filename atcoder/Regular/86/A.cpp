#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
char s[4];
int main() {
    int ans=0;
    scanf("%s", s);
    for (int i = 0; s[i]; ++i) if (s[i] == '1') ++ans;
    printf("%d\n", ans);
    return 0;
}
