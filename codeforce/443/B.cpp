#include <bits/stdc++.h>
#define maxn 1010
using namespace std;
int a[maxn];
typedef long long LL;
int main() {
    int n; LL k;
    scanf("%d%I64d", &n, &k);

    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    if (k >= n-1) { printf("%d\n", n); exit(0); }

    int p = 0, cnt = 0;
    while (true) {
        bool flag = false;
        int i = p+1;
        for (; i < n && cnt < k; ++i, ++cnt) {
            if (a[i] > a[p]) {
                flag = true, p = i, cnt = 1;
                break;
            }
        }
        if (!flag) { printf("%d", a[p]); break; }
    }

    return 0;
}
