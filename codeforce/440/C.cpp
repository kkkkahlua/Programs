#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if (x==1 || x==2 || x==3 || x==5 || x==7 || x==11) { printf("-1\n"); continue; }
        if (x==6 || x==9) { printf("1\n"); continue; }
        int m = x %4;
        if (m==0 || m==2) printf("%d\n", x/4);
        else printf("%d\n", x/4-1);
    }
    return 0;
}
