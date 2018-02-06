#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
int a[maxn];
void work() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sort(a, a + n);
    int i;
    for (i = n - 1; i > 0; --i) {
        int x = a[i] - a[i - 1];
        if (x > k) break;
    }
    printf("%d\n", n - i);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) work();
    return 0;
}
