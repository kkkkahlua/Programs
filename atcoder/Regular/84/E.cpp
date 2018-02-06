#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
void find(int x, int p, int t) {
    a[p] = x;

}
int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &k);
    if (!(k&1)) {
        printf("%d", k/2);
        for (int i = 1; i < n; ++i) printf(" %d", k); puts("");
    }
    else {
        LL sum = 0;
        if (n & 1) find(k/2+1, 0, 0);
        else find(k/2, 0, 1);
    }
    return 0;
}
