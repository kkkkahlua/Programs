#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
char s[maxn];
int f[maxn];
typedef long long LL;
void getfail() {
    int n = strlen(s);
    f[0] = f[1] = 0;
    for (int i = 1; i < n; ++i) {
        int j = f[i];
        while (j && s[i] != s[j]) j = f[j];
        f[i+1] = s[i] == s[j] ? j+1 : 0;
    }
}
void work() {
    scanf("%s", s);
    getfail();
    int n = strlen(s);
    int diff = n - f[n];
    if (n % diff == 0 && n / diff > 1) printf("0\n");
    else printf("%d\n", diff - n % diff);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
