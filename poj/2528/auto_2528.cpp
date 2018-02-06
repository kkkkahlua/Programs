#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    freopen("in.txt", "w", stdout);
    int T=10, n=10000; printf("%d\n", T);
    srand(time(NULL));
    while (T--) {
        printf("%d\n", n);
        for (int i=0; i <n;++i) {
            int l=rand();
            int r=l+rand();
            printf("%d %d\n", l, r);
        }
    }
    return 0;
}
