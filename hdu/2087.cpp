#include <bits/stdc++.h>
#define maxn 1010
using namespace std;
typedef long long LL;
char T[maxn], P[maxn];
int f[maxn];
int n, m, cnt;
void getfail() {
    f[0] = f[1] = 0;
    for (int i = 1; i < m; ++i) {
        int j = f[i];
        while (j && P[j] != P[i]) j = f[j];
        f[i+1] = P[i] == P[j] ? j+1 : 0;
    }
}
void kmp() {
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j && T[i] != P[j]) j = f[j];
        if (T[i] == P[j]) ++j;
        if (j == m) ++cnt, j = 0;
    }
}
void work() {
    n = strlen(T), m = strlen(P), cnt = 0;
    getfail();
    kmp();
    printf("%d\n", cnt);
}
int main() {
//    freopen("in.txt", "r", stdin);
    while (scanf("%s%s", T, P) != EOF && T[0] != '#') work();
    return 0;
}
