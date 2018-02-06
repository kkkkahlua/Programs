#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#define K 25
#define maxn 100010
using namespace std;
typedef long long LL;
vector<int> ans;
int n, m, k, cnt;
int eq1[maxn][K+10], eq2[maxn][K+10], lt1[maxn][K+10], lt2[maxn][K+10], f[maxn], x[maxn], a[maxn];
bool cmp(int i, int j) { return x[i] < x[j]; }
void init(int* x, int eq[maxn][K+10], int lt[maxn][K+10], int n) {
    for (int i = 1; i <= n; ++i) {
        memcpy(eq[i], eq[i-1], sizeof(eq[0]));
        ++eq[i][x[i]];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= K; ++j) lt[i][j] = lt[i][j-1] + eq[i][j];
    }
}
bool match1(int i, int j, int x, int y) {
    return eq2[i][x] - eq2[i-j][x] == eq2[j][y] && lt2[i][x-1] - lt2[i-j][x-1] == lt2[j][y-1];
}
bool match2(int i, int j, int x, int y) {
    return eq1[i][x] - eq1[i-j][x] == eq2[j][y] && lt1[i][x-1] - lt1[i-j][x-1] == lt2[j][y-1];
}
void getfail(int* P) {
    int j = 0; f[1] = 0;
    for (int i = 1; i <= m; ) {
        if (!j || match1(i, j, P[i], P[j])) f[++i] = ++j;
        else j = f[j];
    }
}
void kmp(int* T, int* P) {
    int j = 1;
    for (int i = 1; i <= n; ) {
        if (!j || match2(i, j, T[i], P[j])) ++j, ++i;
        else j = f[j];
        if (j == m + 1) {
            ans.push_back(i-m);
            ++cnt;
            j = f[j];
        }
    }
}
void init() {
    memset(x, 0, sizeof(x)); memset(a, 0, sizeof(a)); memset(f, 0, sizeof(f));
    memset(eq1, 0, sizeof eq1); memset(eq2, 0, sizeof eq2);
    memset(lt1, 0, sizeof lt1); memset(lt2, 0, sizeof lt2);
    ans.clear();
}
void work() {
    init();
    for (int i = 1; i <= n; ++i) scanf("%d", &x[i]); init(x, eq1, lt1, n);
    for (int i = 1; i <= m; ++i) scanf("%d", &a[i]); init(a, eq2, lt2, m);
    getfail(a);
    cnt = 0;
    kmp(x, a);
    printf("%d\n", cnt);
    for (vector<int>::iterator it = ans.begin(); it != ans.end(); ++it) printf("%d\n", *it);
}
int main() {
    freopen("in.txt", "r", stdin);
    while (scanf("%d%d%d", &n, &m, &k) != EOF) work();
    return 0;
}
