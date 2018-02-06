#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    char s[10];
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0; i < len-1; ++i) {
        if (s[i] =='A' && s[i+1] == 'C')
        {

            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}
