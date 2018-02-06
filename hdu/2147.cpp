#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF && n && m) {
        if ((n&1) && (m&1)) puts("What a pity!");
        else puts("Wonderful!");
    }
    return 0;
}
