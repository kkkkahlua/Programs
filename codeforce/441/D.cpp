#include <bits/stdc++.h>
#define maxn 300010
using namespace std;
typedef long long LL;
bool a[maxn];
int main() {
//    freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int l = n+1, r = n+1;
    putchar('1');
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        a[x] = 1;
        while (l > 1 && a[l-1]) --l;
        printf(" %d", i+1-(r-l));
    }
    putchar('\n');
    return 0;
}
