#include <cstdio>
#include <cstring>
#define maxn 1000010
using namespace std;
typedef long long LL;
char s[maxn];
int f[maxn], n;
void getfail() {
    f[0] = f[1] = 0;
    for (int i = 1; i < n; ++i) {
        int j = f[i];
        while (j && s[i] != s[j]) j = f[j];
        f[i+1] = s[i] == s[j] ? j+1 : 0;
    }
}
void work() {
    n = strlen(s);
    getfail();
    if (n % (n - f[n]) == 0) printf("%d\n", n / (n - f[n]));
    else printf("1\n");
}
int main() {
//    freopen("in.txt", "r", stdin);
    while (scanf("%s", s) != EOF && s[0] != '.') work();
    return 0;
}
