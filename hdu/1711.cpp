#include <bits/stdc++.h>
#define maxn 1000010
using namespace std;
typedef long long LL;
int f[maxn], a[maxn], b[maxn];
void getfail(int* P, int m) {
    memset(f, 0, sizeof(f));
    for (int i = 1; i < m; ++i) {
        int j = f[i];
        while (j && P[i] != P[j]) j = f[j];
        f[i+1] = P[i] == P[j] ? j+1 : 0;
    }
}
int find(int* T, int n, int* P, int m) {
    getfail(P, m);
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j && T[i] != P[j]) j = f[j];
        if (T[i] == P[j]) ++j;
        if (j == m) return i - m + 2;
    }
    return -1;
}
void work() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i) scanf("%d", &b[i]);
    printf("%d\n", find(a, n, b, m));
}
int main() {
//    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
