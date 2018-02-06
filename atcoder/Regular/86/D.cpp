#include <bits/stdc++.h>
#define maxn 55
using namespace std;
typedef long long LL;
int a[maxn];
int main() {
//    freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    printf("%d\n", 2*n-2);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    int p1=1, p2=1;
    for (int i = 2; i <= n; ++i) {
        if (a[i] > a[p1]) p1 = i;
        if (a[i] < a[p2]) p2 = i;
    }
    if (abs(a[p1]) >= abs(a[p2])) {
        for (int i = 1; i < p1; ++i) printf("%d %d\n", p1, i);
        for (int i = p1+1; i <= n; ++i) printf("%d %d\n", p1, i);
        for (int i = 2; i <= n; ++i) printf("%d %d\n", i-1, i);
    }
    else {
        for (int i = 1; i < p2; ++i) printf("%d %d\n", p2, i);
        for (int i = p2+1; i <= n; ++i) printf("%d %d\n", p2, i);
        for (int i = n-1; i >= 1; --i) printf("%d %d\n", i+1, i);
    }
    return 0;
}
