#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
typedef long long LL;
char T[maxn], P[maxn], ans[maxn];
int f[maxn], n, m;
void getfail() {
    f[0] = f[1] = 0;
    for (int i = 1; i < m; ++i) {
        int j = f[i];
        while (j && P[i] != P[j]) j = f[j];
        f[i+1] = P[i] == P[j] ? j+1 : 0;
    }
}
int kmp() {
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j && T[i] != P[j]) j = f[j];
        if (T[i] == P[j]) ++j;
        if (j == m && i != n-1) j = f[j];
    }
    return j;
}
void work() {
    memset(ans, 0, sizeof ans);
    n = strlen(T), m = strlen(P);
    getfail();
    int len = kmp();
    if (len == 0) printf("0\n");
    else {
        memcpy(ans, P, len*sizeof(char));
        printf("%s %d\n", ans, len);
    }
}
int main() {
    freopen("in.txt", "r", stdin);
    while (scanf("%s%s", P, T) != EOF) work();
    return 0;
}
