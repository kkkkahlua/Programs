#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
typedef long long LL;
int f[maxn], n, m;
char T[maxn<<1], P[maxn];
void getfail() {
    f[0] = f[1] = 0;
    for (int i = 1; i < m; ++i) {
        int j = f[i];
        while (j && P[j] != P[i]) j = f[j];
        f[i+1] = P[i] == P[j] ? j+1 : 0;
    }
}
int kmp() {
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j && T[i] != P[j]) j = f[j];
        if (T[i] == P[j]) ++j;
        if (j == m) return i-m+1;
    }
    return -1;
}
void work() {
    n = strlen(T), m = strlen(P);
    for (int i = 0; i < n; ++i) T[n+i] = T[i]; n <<= 1;
    if (n < m) { puts("no"); return; }
    getfail();
    if (~kmp()) puts("yes");
    else puts("no");
}
int main() {
    while (scanf("%s%s", T, P) != EOF) work();
    return 0;
}
