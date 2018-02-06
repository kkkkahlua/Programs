#include <bits/stdc++.h>
#define maxn 1000010
using namespace std;
int f[maxn], n;
char s[maxn];
typedef long long LL;
void getfail(char* P) {
    int m = strlen(P);
    f[0] = f[1] = 0;
    for (int i = 1; i < m; ++i) {
        int j = f[i];
        while (j && P[j] != P[i]) j = f[j];
        f[i+1] = P[i] == P[j] ? j+1 : 0;
    }
}
int kas;
void work() {
    scanf("%s", s);
    getfail(s);
    printf("Test case #%d\n", ++kas);
    for (int i = 2; i <= n; ++i) {
        if (f[i] && i % (i-f[i]) == 0) printf("%d %d\n", i, i / (i-f[i]));
    }
    printf("\n");
}
int main() {
//    freopen("in.txt", "r", stdin);
    while (scanf("%d", &n) != EOF && n) work();
    return 0;
}
