#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    if (n > m) swap(n, m);
    for (int r = 0; r <= n; ++r) {
        if (n==2*r && k==r*m) { printf("Yes\n"); exit(0); }
        if ((k-r*m)*(n-2*r)>0 && (k-r*m)%(n-2*r)==0 && (k-r*m)/(n-2*r)<=m) { printf("Yes\n"); exit(0); }
    }
    printf("No\n");
    return 0;
}
