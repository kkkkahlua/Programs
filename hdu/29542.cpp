#include <bits/stdc++.h>
#define maxn 200010
char T[maxn], P[maxn], ans[maxn];
int f[maxn], n, m;
using namespace std;
typedef long long LL;
void getfail() {
    f[0] = f[1] = 0;
    for (int i = 1; i < m; ++i) {
        int j = f[i];
        while (j && P[j] != P[i]) j = f[j];
        f[i+1] = P[j] == P[i] ? j+1 : 0;
    }
}
void work() {
    n = strlen(T), m = strlen(P);
    int mn = min(n, m);
    strcat(P, T);
    m += n; getfail();
    while (f[m] > mn) m = f[m];
    if (f[m] == 0) printf("0\n");
    else {
        memset(ans, 0, sizeof ans);
        memcpy(ans, P, f[m]);
        printf("%s %d\n", ans, f[m]);
    }
}
int main() {
    while (scanf("%s%s", P, T) != EOF) work();
    return 0;
}
