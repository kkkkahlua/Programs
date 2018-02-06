#include <cstdio>
#include <cmath>
#include <cstring>
#define mod 1000000007
#define maxn 100010
using namespace std;
typedef long long LL;
char s1[maxn], s2[maxn];
int kas, n, m, x, y;
inline int min(int a, int b) { return a < b ? a : b; }
inline int abs(int a, int b) { return a > b ? a - b : b - a; }
void work() {
    scanf("%d%d%d\n", &n, &x, &y);
    scanf("%s%s", s1, s2);
    int tot = 0;
    for (int i = 0; i < n; ++i) {
        if (s1[i] == s2[i]) ++tot;
    }
    int lim = min(min(x, y), tot);
    bool flag = false;
    for (int i = 0; i <= lim; ++i) {
        if (x - i <= n - tot && y <= i + n - tot - (x - i)) {
            flag = true; break;
        }
    }
    if (flag) printf("Not lying\n");
    else printf("Lying\n");
}
int main() {
    freopen("1001.in", "r", stdin);
    freopen("01.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--) work();
    return 0;
}
