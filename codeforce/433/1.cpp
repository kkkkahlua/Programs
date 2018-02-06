#include <bits/stdc++.h>
#define maxn
using namespace std;
typedef long long LL;
void work() {
}
int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}
int main() {
//    freopen("in.txt", "r", stdin);
//    int T;
//    while (T--) work();
    int n;
    scanf("%d", &n);
    int lim = n >>1;
    for (int i = lim; i >= 1; --i) {
        int j = n - i;
        if (gcd(i, j) == 1) {
            printf("%d %d\n", i, j);
            break;
        }
    }
    return 0;
}
