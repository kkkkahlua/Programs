#include <bits/stdc++.h>
#define maxn 1000010
using namespace std;
int f[maxn], n, k;
char s[maxn];
typedef long long LL;
void getfail() {
    f[0] = f[1] = 0;
    for (int i = 1; i < n; ++i) {
        int j = f[i];
        while (j && s[i] != s[j]) j = f[j];
        f[i+1] = s[i] == s[j] ? j+1 : 0;
    }
}
bool check(int l, int cir) {
    int upp = l / k, down = l / (k+1) + 1;
    upp = upp / cir, down = ceil(1.0 * down / cir);
//    printf("%d %d %d %d\n", cir, l, upp, down);
    return upp >= down || (l % (k+1) == 0 && (l / (k+1)) % cir == 0);
}
void work() {
    scanf("%s", s);
    getfail();
    for (int i = 1; i <= n; ++i) {
        int mincir = i - f[i], cir = mincir;
        printf("%d", check(i, cir));
    }
    printf("\n");
}
int main() {
    freopen("in.txt", "r", stdin);
    while (scanf("%d%d", &n, &k) != EOF) work();
    return 0;
}
