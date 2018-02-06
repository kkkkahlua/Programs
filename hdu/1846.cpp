#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    int T, n, m;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        if (n % (m+1)) puts("first");
        else puts("second");
    }
    return 0;
}
